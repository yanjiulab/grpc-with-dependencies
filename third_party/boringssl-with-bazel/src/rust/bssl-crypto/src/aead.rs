/* Copyright (c) 2023, Google Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
use crate::{CSlice, CSliceMut};
use bssl_sys::{EVP_AEAD, EVP_AEAD_CTX};

/// Error returned in the event of an unsuccessful AEAD operation.
#[derive(Debug)]
pub struct AeadError;

/// Authenticated Encryption with Associated Data (AEAD) algorithm trait.
pub trait Aead {
    /// The size of the auth tag for the given AEAD implementation. This is the amount of bytes
    /// appended to the data when it is encrypted.
    const TAG_SIZE: usize;

    /// The byte array nonce type which specifies the size of the nonce used in the aes operations.
    type Nonce: AsRef<[u8]>;

    /// Encrypt the given buffer containing a plaintext message. On success returns the encrypted
    /// `msg` and appended auth tag, which will result in a Vec which is  `Self::TAG_SIZE` bytes
    /// greater than the initial message.
    fn encrypt(&self, msg: &[u8], aad: &[u8], nonce: &Self::Nonce) -> Result<Vec<u8>, AeadError>;

    /// Decrypt the message, returning the decrypted plaintext or an error in the event the
    /// provided authentication tag does not match the given ciphertext. On success the returned
    /// Vec will only contain the plaintext and so will be `Self::TAG_SIZE` bytes less than the
    /// initial message.
    fn decrypt(&self, msg: &[u8], aad: &[u8], nonce: &Self::Nonce) -> Result<Vec<u8>, AeadError>;
}

/// AES-GCM-SIV implementation.
pub struct AesGcmSiv(AeadImpl<12, 16>);

/// Instantiates a new AES-128-GCM-SIV instance from key material.
pub fn new_aes_128_gcm_siv(key: &[u8; 16]) -> AesGcmSiv {
    AesGcmSiv(AeadImpl::new::<EvpAes128GcmSiv>(key))
}

/// Instantiates a new AES-256-GCM-SIV instance from key material.
pub fn new_aes_256_gcm_siv(key: &[u8; 32]) -> AesGcmSiv {
    AesGcmSiv(AeadImpl::new::<EvpAes256GcmSiv>(key))
}

impl Aead for AesGcmSiv {
    const TAG_SIZE: usize = 16;
    type Nonce = [u8; 12];

    fn encrypt(&self, msg: &[u8], aad: &[u8], nonce: &[u8; 12]) -> Result<Vec<u8>, AeadError> {
        self.0.encrypt(msg, aad, nonce)
    }

    fn decrypt(&self, msg: &[u8], aad: &[u8], nonce: &[u8; 12]) -> Result<Vec<u8>, AeadError> {
        self.0.decrypt(msg, aad, nonce)
    }
}

// Private  implementation of an AEAD which is generic over Nonce size and Tag size. This should
// only be exposed publicly by wrapper types which provide the correctly sized const generics for
// the given aead algorithm.
struct AeadImpl<const N: usize, const T: usize>(*mut EVP_AEAD_CTX);

trait EvpAeadType {
    type Key: AsRef<[u8]>;
    fn evp_aead() -> *const EVP_AEAD;
}

struct EvpAes128GcmSiv;
impl EvpAeadType for EvpAes128GcmSiv {
    type Key = [u8; 16];

    fn evp_aead() -> *const EVP_AEAD {
        // Safety:
        // - this just returns a constant value
        unsafe { bssl_sys::EVP_aead_aes_128_gcm_siv() }
    }
}

struct EvpAes256GcmSiv;
impl EvpAeadType for EvpAes256GcmSiv {
    type Key = [u8; 32];

    fn evp_aead() -> *const EVP_AEAD {
        // Safety:
        // - this just returns a constant value
        unsafe { bssl_sys::EVP_aead_aes_256_gcm_siv() }
    }
}

impl<const N: usize, const T: usize> AeadImpl<N, T> {
    // Create a new AeadImpl instance from key material and for a supported AeadType.
    fn new<A: EvpAeadType>(key: &A::Key) -> Self {
        let key_cslice = CSlice::from(key.as_ref());

        // Safety:
        // - This is always safe as long as the correct key size is set by the wrapper type.
        let ctx = unsafe {
            bssl_sys::EVP_AEAD_CTX_new(
                A::evp_aead(),
                key_cslice.as_ptr(),
                key_cslice.len(),
                bssl_sys::EVP_AEAD_DEFAULT_TAG_LENGTH as usize,
            )
        };
        assert!(!ctx.is_null());
        AeadImpl(ctx)
    }

    // Encrypts msg in-place, adding enough space to msg for the auth tag.
    fn encrypt(&self, msg: &[u8], aad: &[u8], nonce: &[u8; N]) -> Result<Vec<u8>, AeadError> {
        let mut out = Vec::new();
        out.resize(msg.len() + T, 0u8);

        let mut out_cslice = CSliceMut::from(out.as_mut_slice());
        let msg_cslice = CSlice::from(msg);
        let aad_cslice = CSlice::from(aad);
        let nonce_cslice = CSlice::from(nonce.as_slice());
        let mut out_len = 0usize;

        // Safety:
        // - The buffers are all valid, with corresponding ptr and length
        let result = unsafe {
            bssl_sys::EVP_AEAD_CTX_seal(
                self.0,
                out_cslice.as_mut_ptr(),
                &mut out_len,
                out_cslice.len(),
                nonce_cslice.as_ptr(),
                nonce_cslice.len(),
                msg_cslice.as_ptr(),
                msg_cslice.len(),
                aad_cslice.as_ptr(),
                aad_cslice.len(),
            )
        };

        if result == 1 {
            // Verify the correct number of bytes were written.
            assert_eq!(out_len, out.len());
            Ok(out)
        } else {
            Err(AeadError)
        }
    }

    // Decrypts msg in-place, on success msg will contain the plain text alone, without the auth
    // tag.
    fn decrypt(&self, msg: &[u8], aad: &[u8], nonce: &[u8; N]) -> Result<Vec<u8>, AeadError> {
        let mut out = Vec::new();
        out.resize(msg.len() - T, 0u8);

        let mut out_cslice = CSliceMut::from(out.as_mut_slice());
        let aad_cslice = CSlice::from(aad);
        let msg_cslice = CSlice::from(msg);
        let mut out_len = 0usize;

        // Safety:
        // - The buffers are all valid, with corresponding ptr and length
        let result = unsafe {
            bssl_sys::EVP_AEAD_CTX_open(
                self.0,
                out_cslice.as_mut_ptr(),
                &mut out_len,
                out_cslice.len(),
                nonce.as_ptr(),
                nonce.len(),
                msg_cslice.as_ptr(),
                msg_cslice.len(),
                aad_cslice.as_ptr(),
                aad_cslice.len(),
            )
        };

        if result == 1 {
            // Verify the correct number of bytes were written.
            assert_eq!(out_len, out.len());
            Ok(out)
        } else {
            Err(AeadError)
        }
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use crate::test_helpers::decode_hex;

    #[test]
    fn aes_128_gcm_siv_tests() {
        // https://github.com/google/wycheproof/blob/master/testvectors/aes_gcm_siv_test.json
        // TC1 - Empty Message
        let key = decode_hex("01000000000000000000000000000000");
        let nonce = decode_hex("030000000000000000000000");
        let tag: [u8; 16] = decode_hex("dc20e2d83f25705bb49e439eca56de25");
        let mut buf = Vec::from(&[] as &[u8]);
        let aes = new_aes_128_gcm_siv(&key);
        let result = aes.encrypt(&mut buf, b"", &nonce);
        assert!(result.is_ok());
        assert_eq!(result.unwrap(), &tag);

        // TC2
        let msg: [u8; 8] = decode_hex("0100000000000000");
        let ct: [u8; 8] = decode_hex("b5d839330ac7b786");
        let tag: [u8; 16] = decode_hex("578782fff6013b815b287c22493a364c");
        let result = aes.encrypt(&msg, b"", &nonce);
        assert!(result.is_ok());
        let mut result_vec = result.unwrap();
        assert_eq!(&result_vec[..8], &ct);
        assert_eq!(&result_vec[8..], &tag);
        let result = aes.decrypt(result_vec.as_mut_slice(), b"", &nonce);
        assert!(result.is_ok());
        assert_eq!(&result.unwrap(), &msg);

        // TC14 contains associated data
        let msg: [u8; 4] = decode_hex("02000000");
        let ct: [u8; 4] = decode_hex("a8fe3e87");
        let aad: [u8; 12] = decode_hex("010000000000000000000000");
        let tag: [u8; 16] = decode_hex("07eb1f84fb28f8cb73de8e99e2f48a14");
        let result = aes.encrypt(&msg, &aad, &nonce);
        assert!(result.is_ok());
        let mut result_vec = result.unwrap();
        assert_eq!(&result_vec[..4], &ct);
        assert_eq!(&result_vec[4..], &tag);
        let result = aes.decrypt(result_vec.as_mut_slice(), &aad, &nonce);
        assert!(result.is_ok());
        assert_eq!(&result.unwrap(), &msg);
    }

    #[test]
    fn aes_256_gcm_siv_tests() {
        // https://github.com/google/wycheproof/blob/master/testvectors/aes_gcm_siv_test.json
        // TC77
        let test_key =
            decode_hex("0100000000000000000000000000000000000000000000000000000000000000");
        let nonce = decode_hex("030000000000000000000000");
        let aes = new_aes_256_gcm_siv(&test_key);
        let mut msg: [u8; 8] = decode_hex("0100000000000000");
        let ct: [u8; 8] = decode_hex("c2ef328e5c71c83b");
        let tag: [u8; 16] = decode_hex("843122130f7364b761e0b97427e3df28");
        let enc_result = aes.encrypt(&mut msg, b"", &nonce);
        assert!(enc_result.is_ok());
        let mut enc_data = enc_result.unwrap();
        assert_eq!(&enc_data[..8], &ct);
        assert_eq!(&enc_data[8..], &tag);
        let result = aes.decrypt(enc_data.as_mut_slice(), b"", &nonce);
        assert!(result.is_ok());
        assert_eq!(&result.unwrap(), &msg);

        // TC78
        let mut msg: [u8; 12] = decode_hex("010000000000000000000000");
        let ct: [u8; 12] = decode_hex("9aab2aeb3faa0a34aea8e2b1");
        let tag: [u8; 16] = decode_hex("8ca50da9ae6559e48fd10f6e5c9ca17e");
        let enc_result = aes.encrypt(&mut msg, b"", &nonce);
        assert!(enc_result.is_ok());
        let mut enc_data = enc_result.unwrap();
        assert_eq!(&enc_data[..12], &ct);
        assert_eq!(&enc_data[12..], &tag);
        let result = aes.decrypt(enc_data.as_mut_slice(), b"", &nonce);
        assert!(result.is_ok());
        assert_eq!(&result.unwrap(), &msg);

        // TC89 contains associated data
        let mut msg: [u8; 4] = decode_hex("02000000");
        let ct: [u8; 4] = decode_hex("22b3f4cd");
        let tag: [u8; 16] = decode_hex("1835e517741dfddccfa07fa4661b74cf");
        let aad: [u8; 12] = decode_hex("010000000000000000000000");
        let enc_result = aes.encrypt(&mut msg, &aad, &nonce);
        assert!(enc_result.is_ok());
        let mut enc_data = enc_result.unwrap();
        assert_eq!(&enc_data[..4], &ct);
        assert_eq!(&enc_data[4..], &tag);
        let result = aes.decrypt(enc_data.as_mut_slice(), &aad, &nonce);
        assert!(result.is_ok());
        assert_eq!(&result.unwrap(), &msg);
    }
}
