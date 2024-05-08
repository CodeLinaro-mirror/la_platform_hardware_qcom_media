/*--------------------------------------------------------------------------
Copyright (c) 2009, 2018 The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of The Linux Foundation nor
      the names of its contributors may be used to endorse or promote
      products derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Changes from Qualcomm Innovation Center are provided under the following license:

Copyright (c) 2021 Qualcomm Innovation Center, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted (subject to the limitations in the
disclaimer below) provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.

    * Neither the name of Qualcomm Innovation Center, Inc. nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

--------------------------------------------------------------------------*/
/*==========================================================================
                            O p e n M A X   w r a p p e r s
                             O p e n  M A X   C o r e

*//** @file qc_omx_msg.h
  This module contains the definitions of the OpenMAX core.

*//*========================================================================*/

#ifndef _QC_OMX_MSG_H_
#define _QC_OMX_MSG_H_

#ifdef GENIVI_DLT
#include "dlt.h"

DLT_IMPORT_CONTEXT(dlt_con_omx_core);
void omx_core_dlt_register(void);
void omx_core_dlt_unregister(void);
#endif


#ifdef _ENABLE_QC_MSG_LOG_
    #ifdef _ANDROID_
        #include <utils/Log.h>

        #ifdef __cplusplus
        extern "C" {
        #endif

        #ifndef LOGE
        #define LOGE ALOGE
        #endif

        #ifndef LOGW
        #define LOGW ALOGW
        #endif

        #ifndef LOGD
        #define LOGD ALOGD
        #endif

        #ifndef LOGV
        #define LOGV ALOGV
        #endif

        #ifndef LOGI
        #define LOGI ALOGI
        #endif

        #ifdef __cplusplus
        }
        #endif
        #ifdef GENIVI_DLT
            #define DEBUG_PRINT_ERROR(fmt,...) \
            do { \
                char logbuf[256]; \
                snprintf(logbuf, sizeof(logbuf), fmt, ## __VA_ARGS__); \
                DLT_LOG(dlt_con_omx_core, DLT_LOG_ERROR, DLT_STRING(logbuf)); \
            } while (0)

            #define DEBUG_PRINT(fmt,...) \
            do { \
                char logbuf[256]; \
                snprintf(logbuf, sizeof(logbuf), fmt, ## __VA_ARGS__); \
                DLT_LOG(dlt_con_omx_core, DLT_LOG_INFO, DLT_STRING(logbuf)); \
            } while (0)

            #define DEBUG_DETAIL(fmt,...) \
            do { \
                char logbuf[256]; \
                snprintf(logbuf, sizeof(logbuf), fmt, ## __VA_ARGS__); \
                DLT_LOG(dlt_con_omx_core, DLT_LOG_INFO, DLT_STRING(logbuf)); \
            } while (0)
        #else
            #define DEBUG_PRINT_ERROR LOGE
            #define DEBUG_PRINT       LOGI
            #define DEBUG_DETAIL      LOGV
        #endif //GENIVI_DLT
    #else
        #define DEBUG_PRINT_ERROR printf
        #define DEBUG_PRINT       printf
        #define DEBUG_DETAIL      printf
    #endif // _ANDROID_
#else
    #ifdef _ANDROID_
        #include <utils/Log.h>
        #define DEBUG_PRINT_ERROR ALOGV
        #define DEBUG_PRINT ALOGV
        #define DEBUG_DETAIL ALOGV
    #endif // _ANDROID_
#endif // _ENABLE_QC_MSG_LOG_

#endif // _QC_OMX_MSG_H_
