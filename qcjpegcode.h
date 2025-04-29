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
#if defined(__arm__) || defined(__aarch64__)
    #include <sys/system_properties.h>
    #include <sys/types.h>
    #include <unistd.h>
    #define UI_PERF_CHECK bool isPerfMode = false;\
        char value[PROP_VALUE_MAX];\
        char *stopStr;\
        long int converted = 0;\
        memset(value, 0, sizeof(char)*PROP_VALUE_MAX);\
        if (__system_property_get(UI_PERFMODE, value) > 0) {\
            converted = strtol(value, &stopStr, 0);\
            if (errno != EINVAL && errno != ERANGE && (strncmp(stopStr, "\0", 1) == 0)) {\
                if (converted > 0 && converted == getpid()) {\
                    isPerfMode = true;\
                }\
            }\
        }
#else
    #define UI_PERF_CHECK bool isPerfMode = false;
#endif
#endif
