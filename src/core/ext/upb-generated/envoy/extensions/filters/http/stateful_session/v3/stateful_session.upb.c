/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/extensions/filters/http/stateful_session/v3/stateful_session.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/collections/array_internal.h"
#include "upb/message/internal.h"
#include "upb/mini_table/enum_internal.h"
#include "envoy/extensions/filters/http/stateful_session/v3/stateful_session.upb.h"
#include "envoy/config/core/v3/extension.upb.h"
#include "udpa/annotations/status.upb.h"
#include "validate/validate.upb.h"

// Must be last.
#include "upb/port/def.inc"

static const upb_MiniTableSub envoy_extensions_filters_http_stateful_session_v3_StatefulSession_submsgs[1] = {
  {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msg_init},
};

static const upb_MiniTableField envoy_extensions_filters_http_stateful_session_v3_StatefulSession__fields[1] = {
  {1, UPB_SIZE(4, 8), 1, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_extensions_filters_http_stateful_session_v3_StatefulSession_msg_init = {
  &envoy_extensions_filters_http_stateful_session_v3_StatefulSession_submsgs[0],
  &envoy_extensions_filters_http_stateful_session_v3_StatefulSession__fields[0],
  UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000800000100000a, &upb_psm_1bt_maxmaxb},
  })
};

static const upb_MiniTableSub envoy_extensions_filters_http_stateful_session_v3_StatefulSessionPerRoute_submsgs[1] = {
  {.submsg = &envoy_extensions_filters_http_stateful_session_v3_StatefulSession_msg_init},
};

static const upb_MiniTableField envoy_extensions_filters_http_stateful_session_v3_StatefulSessionPerRoute__fields[2] = {
  {1, UPB_SIZE(4, 8), -1, kUpb_NoSub, 8, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(4, 8), -1, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_extensions_filters_http_stateful_session_v3_StatefulSessionPerRoute_msg_init = {
  &envoy_extensions_filters_http_stateful_session_v3_StatefulSessionPerRoute_submsgs[0],
  &envoy_extensions_filters_http_stateful_session_v3_StatefulSessionPerRoute__fields[0],
  UPB_SIZE(8, 16), 2, kUpb_ExtMode_NonExtendable, 2, UPB_FASTTABLE_MASK(24), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x0008000001000008, &upb_pob1_1bt},
    {0x0008000002000012, &upb_pom_1bt_max64b},
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
  })
};

static const upb_MiniTable *messages_layout[2] = {
  &envoy_extensions_filters_http_stateful_session_v3_StatefulSession_msg_init,
  &envoy_extensions_filters_http_stateful_session_v3_StatefulSessionPerRoute_msg_init,
};

const upb_MiniTableFile envoy_extensions_filters_http_stateful_session_v3_stateful_session_proto_upb_file_layout = {
  messages_layout,
  NULL,
  NULL,
  2,
  0,
  0,
};

#include "upb/port/undef.inc"

