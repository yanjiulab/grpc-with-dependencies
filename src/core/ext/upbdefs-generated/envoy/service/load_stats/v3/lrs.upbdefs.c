/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/service/load_stats/v3/lrs.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include "upb/reflection/def.h"
#include "envoy/service/load_stats/v3/lrs.upbdefs.h"
#include "envoy/service/load_stats/v3/lrs.upb.h"

extern _upb_DefPool_Init envoy_config_core_v3_base_proto_upbdefinit;
extern _upb_DefPool_Init envoy_config_endpoint_v3_load_report_proto_upbdefinit;
extern _upb_DefPool_Init google_protobuf_duration_proto_upbdefinit;
extern _upb_DefPool_Init udpa_annotations_status_proto_upbdefinit;
extern _upb_DefPool_Init udpa_annotations_versioning_proto_upbdefinit;
static const char descriptor[1037] = {'\n', '%', 'e', 'n', 'v', 'o', 'y', '/', 's', 'e', 'r', 'v', 'i', 'c', 'e', '/', 'l', 'o', 'a', 'd', '_', 's', 't', 'a', 't', 
's', '/', 'v', '3', '/', 'l', 'r', 's', '.', 'p', 'r', 'o', 't', 'o', '\022', '\033', 'e', 'n', 'v', 'o', 'y', '.', 's', 'e', 'r', 
'v', 'i', 'c', 'e', '.', 'l', 'o', 'a', 'd', '_', 's', 't', 'a', 't', 's', '.', 'v', '3', '\032', '\037', 'e', 'n', 'v', 'o', 'y', 
'/', 'c', 'o', 'n', 'f', 'i', 'g', '/', 'c', 'o', 'r', 'e', '/', 'v', '3', '/', 'b', 'a', 's', 'e', '.', 'p', 'r', 'o', 't', 
'o', '\032', '*', 'e', 'n', 'v', 'o', 'y', '/', 'c', 'o', 'n', 'f', 'i', 'g', '/', 'e', 'n', 'd', 'p', 'o', 'i', 'n', 't', '/', 
'v', '3', '/', 'l', 'o', 'a', 'd', '_', 'r', 'e', 'p', 'o', 'r', 't', '.', 'p', 'r', 'o', 't', 'o', '\032', '\036', 'g', 'o', 'o', 
'g', 'l', 'e', '/', 'p', 'r', 'o', 't', 'o', 'b', 'u', 'f', '/', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', '.', 'p', 'r', 'o', 
't', 'o', '\032', '\035', 'u', 'd', 'p', 'a', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i', 'o', 'n', 's', '/', 's', 't', 'a', 't', 
'u', 's', '.', 'p', 'r', 'o', 't', 'o', '\032', '!', 'u', 'd', 'p', 'a', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i', 'o', 'n', 
's', '/', 'v', 'e', 'r', 's', 'i', 'o', 'n', 'i', 'n', 'g', '.', 'p', 'r', 'o', 't', 'o', '\"', '\304', '\001', '\n', '\020', 'L', 'o', 
'a', 'd', 'S', 't', 'a', 't', 's', 'R', 'e', 'q', 'u', 'e', 's', 't', '\022', '.', '\n', '\004', 'n', 'o', 'd', 'e', '\030', '\001', ' ', 
'\001', '(', '\013', '2', '\032', '.', 'e', 'n', 'v', 'o', 'y', '.', 'c', 'o', 'n', 'f', 'i', 'g', '.', 'c', 'o', 'r', 'e', '.', 'v', 
'3', '.', 'N', 'o', 'd', 'e', 'R', '\004', 'n', 'o', 'd', 'e', '\022', 'K', '\n', '\r', 'c', 'l', 'u', 's', 't', 'e', 'r', '_', 's', 
't', 'a', 't', 's', '\030', '\002', ' ', '\003', '(', '\013', '2', '&', '.', 'e', 'n', 'v', 'o', 'y', '.', 'c', 'o', 'n', 'f', 'i', 'g', 
'.', 'e', 'n', 'd', 'p', 'o', 'i', 'n', 't', '.', 'v', '3', '.', 'C', 'l', 'u', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 's', 
'R', '\014', 'c', 'l', 'u', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 's', ':', '3', '\232', '\305', '\210', '\036', '.', '\n', ',', 'e', 'n', 
'v', 'o', 'y', '.', 's', 'e', 'r', 'v', 'i', 'c', 'e', '.', 'l', 'o', 'a', 'd', '_', 's', 't', 'a', 't', 's', '.', 'v', '2', 
'.', 'L', 'o', 'a', 'd', 'S', 't', 'a', 't', 's', 'R', 'e', 'q', 'u', 'e', 's', 't', '\"', '\244', '\002', '\n', '\021', 'L', 'o', 'a', 
'd', 'S', 't', 'a', 't', 's', 'R', 'e', 's', 'p', 'o', 'n', 's', 'e', '\022', '\032', '\n', '\010', 'c', 'l', 'u', 's', 't', 'e', 'r', 
's', '\030', '\001', ' ', '\003', '(', '\t', 'R', '\010', 'c', 'l', 'u', 's', 't', 'e', 'r', 's', '\022', '*', '\n', '\021', 's', 'e', 'n', 'd', 
'_', 'a', 'l', 'l', '_', 'c', 'l', 'u', 's', 't', 'e', 'r', 's', '\030', '\004', ' ', '\001', '(', '\010', 'R', '\017', 's', 'e', 'n', 'd', 
'A', 'l', 'l', 'C', 'l', 'u', 's', 't', 'e', 'r', 's', '\022', 'Q', '\n', '\027', 'l', 'o', 'a', 'd', '_', 'r', 'e', 'p', 'o', 'r', 
't', 'i', 'n', 'g', '_', 'i', 'n', 't', 'e', 'r', 'v', 'a', 'l', '\030', '\002', ' ', '\001', '(', '\013', '2', '\031', '.', 'g', 'o', 'o', 
'g', 'l', 'e', '.', 'p', 'r', 'o', 't', 'o', 'b', 'u', 'f', '.', 'D', 'u', 'r', 'a', 't', 'i', 'o', 'n', 'R', '\025', 'l', 'o', 
'a', 'd', 'R', 'e', 'p', 'o', 'r', 't', 'i', 'n', 'g', 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', '\022', '>', '\n', '\033', 'r', 'e', 
'p', 'o', 'r', 't', '_', 'e', 'n', 'd', 'p', 'o', 'i', 'n', 't', '_', 'g', 'r', 'a', 'n', 'u', 'l', 'a', 'r', 'i', 't', 'y', 
'\030', '\003', ' ', '\001', '(', '\010', 'R', '\031', 'r', 'e', 'p', 'o', 'r', 't', 'E', 'n', 'd', 'p', 'o', 'i', 'n', 't', 'G', 'r', 'a', 
'n', 'u', 'l', 'a', 'r', 'i', 't', 'y', ':', '4', '\232', '\305', '\210', '\036', '/', '\n', '-', 'e', 'n', 'v', 'o', 'y', '.', 's', 'e', 
'r', 'v', 'i', 'c', 'e', '.', 'l', 'o', 'a', 'd', '_', 's', 't', 'a', 't', 's', '.', 'v', '2', '.', 'L', 'o', 'a', 'd', 'S', 
't', 'a', 't', 's', 'R', 'e', 's', 'p', 'o', 'n', 's', 'e', '2', '\216', '\001', '\n', '\024', 'L', 'o', 'a', 'd', 'R', 'e', 'p', 'o', 
'r', 't', 'i', 'n', 'g', 'S', 'e', 'r', 'v', 'i', 'c', 'e', '\022', 'v', '\n', '\017', 'S', 't', 'r', 'e', 'a', 'm', 'L', 'o', 'a', 
'd', 'S', 't', 'a', 't', 's', '\022', '-', '.', 'e', 'n', 'v', 'o', 'y', '.', 's', 'e', 'r', 'v', 'i', 'c', 'e', '.', 'l', 'o', 
'a', 'd', '_', 's', 't', 'a', 't', 's', '.', 'v', '3', '.', 'L', 'o', 'a', 'd', 'S', 't', 'a', 't', 's', 'R', 'e', 'q', 'u', 
'e', 's', 't', '\032', '.', '.', 'e', 'n', 'v', 'o', 'y', '.', 's', 'e', 'r', 'v', 'i', 'c', 'e', '.', 'l', 'o', 'a', 'd', '_', 
's', 't', 'a', 't', 's', '.', 'v', '3', '.', 'L', 'o', 'a', 'd', 'S', 't', 'a', 't', 's', 'R', 'e', 's', 'p', 'o', 'n', 's', 
'e', '\"', '\000', '(', '\001', '0', '\001', 'B', '\220', '\001', '\n', ')', 'i', 'o', '.', 'e', 'n', 'v', 'o', 'y', 'p', 'r', 'o', 'x', 'y', 
'.', 'e', 'n', 'v', 'o', 'y', '.', 's', 'e', 'r', 'v', 'i', 'c', 'e', '.', 'l', 'o', 'a', 'd', '_', 's', 't', 'a', 't', 's', 
'.', 'v', '3', 'B', '\010', 'L', 'r', 's', 'P', 'r', 'o', 't', 'o', 'P', '\001', 'Z', 'O', 'g', 'i', 't', 'h', 'u', 'b', '.', 'c', 
'o', 'm', '/', 'e', 'n', 'v', 'o', 'y', 'p', 'r', 'o', 'x', 'y', '/', 'g', 'o', '-', 'c', 'o', 'n', 't', 'r', 'o', 'l', '-', 
'p', 'l', 'a', 'n', 'e', '/', 'e', 'n', 'v', 'o', 'y', '/', 's', 'e', 'r', 'v', 'i', 'c', 'e', '/', 'l', 'o', 'a', 'd', '_', 
's', 't', 'a', 't', 's', '/', 'v', '3', ';', 'l', 'o', 'a', 'd', '_', 's', 't', 'a', 't', 's', 'v', '3', '\272', '\200', '\310', '\321', 
'\006', '\002', '\020', '\002', 'b', '\006', 'p', 'r', 'o', 't', 'o', '3', 
};

static _upb_DefPool_Init *deps[6] = {
  &envoy_config_core_v3_base_proto_upbdefinit,
  &envoy_config_endpoint_v3_load_report_proto_upbdefinit,
  &google_protobuf_duration_proto_upbdefinit,
  &udpa_annotations_status_proto_upbdefinit,
  &udpa_annotations_versioning_proto_upbdefinit,
  NULL
};

_upb_DefPool_Init envoy_service_load_stats_v3_lrs_proto_upbdefinit = {
  deps,
  &envoy_service_load_stats_v3_lrs_proto_upb_file_layout,
  "envoy/service/load_stats/v3/lrs.proto",
  UPB_STRINGVIEW_INIT(descriptor, 1037)
};
