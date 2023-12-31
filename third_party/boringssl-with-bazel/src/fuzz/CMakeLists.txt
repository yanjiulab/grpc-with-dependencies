macro(fuzzer name)
  add_executable(${name} ${name}.cc)
  target_compile_options(${name} PRIVATE "-Wno-missing-prototypes")
  target_link_libraries(${name} crypto ${ARGN})
  if(LIBFUZZER_FROM_DEPS)
    set_target_properties(${name} PROPERTIES LINK_FLAGS "-fsanitize=fuzzer-no-link")
    target_link_libraries(${name} Fuzzer)
  else()
    set_target_properties(${name} PROPERTIES LINK_FLAGS "-fsanitize=fuzzer")
  endif()
  set_target_properties(
    ${name}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    COMPILE_FLAGS "-D_BORINGSSL_LIBPKI_")
endmacro()

fuzzer(arm_cpuinfo)
fuzzer(bn_div)
fuzzer(bn_mod_exp)
fuzzer(cert)
fuzzer(client ssl)
fuzzer(conf)
fuzzer(crl_getcrlstatusforcert_fuzzer pki)
fuzzer(crl_parse_crl_certificatelist_fuzzer pki)
fuzzer(crl_parse_crl_tbscertlist_fuzzer pki)
fuzzer(crl_parse_issuing_distribution_point_fuzzer pki)
fuzzer(decode_client_hello_inner ssl)
fuzzer(der_roundtrip)
fuzzer(dtls_client ssl)
fuzzer(dtls_server ssl)
fuzzer(ocsp_parse_ocsp_cert_id_fuzzer pki)
fuzzer(ocsp_parse_ocsp_response_data_fuzzer pki)
fuzzer(ocsp_parse_ocsp_response_fuzzer pki)
fuzzer(ocsp_parse_ocsp_single_response_fuzzer pki)
fuzzer(parse_authority_key_identifier_fuzzer pki)
fuzzer(parse_certificate_fuzzer pki)
fuzzer(pkcs12)
fuzzer(pkcs8)
fuzzer(privkey)
fuzzer(read_pem)
fuzzer(server ssl)
fuzzer(session ssl)
fuzzer(spki)
fuzzer(ssl_ctx_api ssl)
fuzzer(verify_name_match_fuzzer pki)
fuzzer(verify_name_match_normalizename_fuzzer pki)
fuzzer(verify_name_match_verifynameinsubtree_fuzzer pki)
