/* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#ifndef QC_JPEG_CODE
#define QC_JPEG_CODE
#define QC_JPEG_ENCODE_STAGES 0x100
#define QC_JPEG_ENCODE_FINISH_COMPRESS 0x1
#define QC_JPEG_ENCODE_WRITE_MARKER 0x2
#define QC_JPEG_ENCODE_START_COMPRESS_1 0x3
#define QC_JPEG_ENCODE_START_COMPRESS_2 0x4
#define QC_JPEG_ENCODE_START_COMPRESS_3 0x5
#define QC_JPEG_ENCODE_ENCODE_MCU_HUFF_1 0x6
#define QC_JPEG_ENCODE_ENCODE_MCU_HUFF_2 0x7
#define QC_JPEG_ENCODE_JINT_COMPRESS_MASTER 0x8
#define QC_JPEG_ENCODE_EMIT_BYTE 0x9

#define QC_JPEG_DECODE_STAGES 0x200
#define QC_JPEG_DECODE_DESTROY_DECOMPRESS 0x1
#define QC_JPEG_DECODE_READ_HEADER 0x2
#define QC_JPEG_DECODE_START_DECOMPRESS 0x3
#define QC_JPEG_DECODE_SKIP_INPUT_DATA 0x4
#define QC_JPEG_DECODE_SKIP_INPUT_DATA_TJ 0x5
#define QC_JPEG_DECODE_READ_MARKERS_1 0x6
#define QC_JPEG_DECODE_READ_MARKERS_2 0x7

#define UI_PERFMODE "debug.ui.perfmode.enable"
#define UI_PERFMODE_PROCESS "debug.ui.perfmode.process"
#define PROCESS_NAME_LEN 21
#if defined(__arm__) || defined(__aarch64__)
    #include <sys/system_properties.h>
    #define UI_PERF_CHECK extern const char* __progname;\
        bool isPerfMode = false;\
        char value[PROP_VALUE_MAX];\
        memset(value, 0, sizeof(char)*PROP_VALUE_MAX);\
        if (__system_property_get(UI_PERFMODE, value) > 0 && strncmp(value, "true", 4) == 0) {\
            memset(value, 0, sizeof(char)*PROP_VALUE_MAX);\
            __system_property_get(UI_PERFMODE_PROCESS, value);\
            if (__system_property_get(UI_PERFMODE_PROCESS, value) > 0 &&\
                strncmp(__progname, value, PROCESS_NAME_LEN) == 0) {\
                isPerfMode = true;\
            }\
        }
#else
    #define UI_PERF_CHECK bool isPerfMode = false;
#endif
#endif
