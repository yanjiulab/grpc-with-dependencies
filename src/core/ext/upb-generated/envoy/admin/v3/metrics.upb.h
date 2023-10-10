/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/admin/v3/metrics.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ADMIN_V3_METRICS_PROTO_UPB_H_
#define ENVOY_ADMIN_V3_METRICS_PROTO_UPB_H_

#include "upb/collections/array_internal.h"
#include "upb/collections/map_gencode_util.h"
#include "upb/message/accessors.h"
#include "upb/message/internal.h"
#include "upb/mini_table/enum_internal.h"
#include "upb/wire/decode.h"
#include "upb/wire/decode_fast.h"
#include "upb/wire/encode.h"

// Must be last. 
#include "upb/port/def.inc"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct envoy_admin_v3_SimpleMetric envoy_admin_v3_SimpleMetric;
extern const upb_MiniTable envoy_admin_v3_SimpleMetric_msg_init;

typedef enum {
  envoy_admin_v3_SimpleMetric_COUNTER = 0,
  envoy_admin_v3_SimpleMetric_GAUGE = 1
} envoy_admin_v3_SimpleMetric_Type;



/* envoy.admin.v3.SimpleMetric */

UPB_INLINE envoy_admin_v3_SimpleMetric* envoy_admin_v3_SimpleMetric_new(upb_Arena* arena) {
  return (envoy_admin_v3_SimpleMetric*)_upb_Message_New(&envoy_admin_v3_SimpleMetric_msg_init, arena);
}
UPB_INLINE envoy_admin_v3_SimpleMetric* envoy_admin_v3_SimpleMetric_parse(const char* buf, size_t size, upb_Arena* arena) {
  envoy_admin_v3_SimpleMetric* ret = envoy_admin_v3_SimpleMetric_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &envoy_admin_v3_SimpleMetric_msg_init, NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE envoy_admin_v3_SimpleMetric* envoy_admin_v3_SimpleMetric_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  envoy_admin_v3_SimpleMetric* ret = envoy_admin_v3_SimpleMetric_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &envoy_admin_v3_SimpleMetric_msg_init, extreg, options, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* envoy_admin_v3_SimpleMetric_serialize(const envoy_admin_v3_SimpleMetric* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &envoy_admin_v3_SimpleMetric_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* envoy_admin_v3_SimpleMetric_serialize_ex(const envoy_admin_v3_SimpleMetric* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &envoy_admin_v3_SimpleMetric_msg_init, options, arena, &ptr, len);
  return ptr;
}
UPB_INLINE void envoy_admin_v3_SimpleMetric_clear_type(envoy_admin_v3_SimpleMetric* msg) {
  const upb_MiniTableField field = {1, 0, 0, kUpb_NoSub, 5, kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsAlternate | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE int32_t envoy_admin_v3_SimpleMetric_type(const envoy_admin_v3_SimpleMetric* msg) {
  int32_t default_val = 0;
  int32_t ret;
  const upb_MiniTableField field = {1, 0, 0, kUpb_NoSub, 5, kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsAlternate | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE void envoy_admin_v3_SimpleMetric_clear_value(envoy_admin_v3_SimpleMetric* msg) {
  const upb_MiniTableField field = {2, 8, 0, kUpb_NoSub, 4, kUpb_FieldMode_Scalar | (kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE uint64_t envoy_admin_v3_SimpleMetric_value(const envoy_admin_v3_SimpleMetric* msg) {
  uint64_t default_val = (uint64_t)0ull;
  uint64_t ret;
  const upb_MiniTableField field = {2, 8, 0, kUpb_NoSub, 4, kUpb_FieldMode_Scalar | (kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE void envoy_admin_v3_SimpleMetric_clear_name(envoy_admin_v3_SimpleMetric* msg) {
  const upb_MiniTableField field = {3, 16, 0, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView envoy_admin_v3_SimpleMetric_name(const envoy_admin_v3_SimpleMetric* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {3, 16, 0, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}

UPB_INLINE void envoy_admin_v3_SimpleMetric_set_type(envoy_admin_v3_SimpleMetric *msg, int32_t value) {
  const upb_MiniTableField field = {1, 0, 0, kUpb_NoSub, 5, kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsAlternate | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void envoy_admin_v3_SimpleMetric_set_value(envoy_admin_v3_SimpleMetric *msg, uint64_t value) {
  const upb_MiniTableField field = {2, 8, 0, kUpb_NoSub, 4, kUpb_FieldMode_Scalar | (kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void envoy_admin_v3_SimpleMetric_set_name(envoy_admin_v3_SimpleMetric *msg, upb_StringView value) {
  const upb_MiniTableField field = {3, 16, 0, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}

extern const upb_MiniTableFile envoy_admin_v3_metrics_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif  /* ENVOY_ADMIN_V3_METRICS_PROTO_UPB_H_ */