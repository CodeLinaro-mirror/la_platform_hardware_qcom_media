/*--------------------------------------------------------------------------
Copyright (c) 2017, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Changes from Qualcomm Innovation Center are provided under the following license:
Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
SPDX-License-Identifier: BSD-3-Clause-Clear
--------------------------------------------------------------------------*/

void omx_video::init_vendor_extensions(VendorExtensionStore &store) {

    //TODO: add extensions based on Codec, m_platform and/or other capability queries

    ADD_EXTENSION("qti-ext-enc-preprocess-rotate", OMX_IndexConfigCommonRotate, OMX_DirOutput)
    ADD_PARAM_END("angle", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-avc-intra-period", OMX_IndexConfigVideoAVCIntraPeriod, OMX_DirOutput)
    ADD_PARAM    ("n-pframes",    OMX_AndroidVendorValueInt32)
    ADD_PARAM_END("n-idr-period", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-error-correction", OMX_QcomIndexParamVideoSliceSpacing, OMX_DirOutput)
    ADD_PARAM_END("resync-marker-spacing-bits", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-slice", OMX_QcomIndexParamVideoSliceSpacing, OMX_DirOutput)
    ADD_PARAM_END("spacing", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-custom-profile-level", OMX_IndexParamVideoProfileLevelCurrent, OMX_DirOutput)
    ADD_PARAM    ("profile", OMX_AndroidVendorValueInt32)
    ADD_PARAM_END("level",   OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-timestamp-source-avtimer", OMX_QTIIndexParamEnableAVTimerTimestamps, OMX_DirInput)
    ADD_PARAM_END("enable", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-ltr-count", OMX_QcomIndexParamVideoLTRCount, OMX_DirInput)
    ADD_PARAM_END("num-ltr-frames", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-ltr", OMX_QcomIndexConfigVideoLTRUse, OMX_DirInput)
    ADD_PARAM_END("use-frame", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-ltr", OMX_QcomIndexConfigVideoLTRMark, OMX_DirInput)
    ADD_PARAM_END("mark-frame", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-sar", OMX_QcomIndexParamVencAspectRatio, OMX_DirInput)
    ADD_PARAM    ("width", OMX_AndroidVendorValueInt32)
    ADD_PARAM_END("height", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-extradata-enable", OMX_QcomIndexParamIndexExtraDataType, OMX_DirOutput)
    ADD_PARAM_END("types", OMX_AndroidVendorValueString)

    ADD_EXTENSION("qti-ext-enc-caps-vt-driver-version", OMX_QTIIndexParamCapabilitiesVTDriverVersion, OMX_DirOutput)
    ADD_PARAM_END("number", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-caps-preprocess", OMX_QTIIndexParamCapabilitiesMaxDownScaleRatio, OMX_DirOutput)
    ADD_PARAM_END("max-downscale-factor", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-caps-preprocess", OMX_QTIIndexParamCapabilitiesRotationSupport, OMX_DirOutput)
    ADD_PARAM_END("rotation", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-caps-ltr", OMX_QTIIndexParamCapabilitiesMaxLTR, OMX_DirOutput)
    ADD_PARAM_END("max-count", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-caps-temporal-layers", OMX_QTIIndexParamCapabilitiesMaxTemporalLayers, OMX_DirInput)
    ADD_PARAM    ("max-p-count", OMX_AndroidVendorValueInt32)
    ADD_PARAM_END("max-b-count", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-app-input-control", OMX_QcomIndexParamVencControlInputQueue, OMX_DirInput)
    ADD_PARAM_END("enable", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-input-trigger", OMX_IndexConfigTimePosition, OMX_DirInput)
    ADD_PARAM_END("timestamp", OMX_AndroidVendorValueInt64)

    ADD_EXTENSION("qti-ext-enc-frame-qp", OMX_QcomIndexConfigQp, OMX_DirInput)
    ADD_PARAM_END("value", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-base-layer-pid", OMX_QcomIndexConfigBaseLayerId, OMX_DirInput)
    ADD_PARAM_END("value", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-initial-qp", QOMX_IndexParamVideoInitialQp, OMX_DirOutput)
    ADD_PARAM    ("qp-i", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-i-enable", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-p", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-p-enable", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-b", OMX_AndroidVendorValueInt32)
    ADD_PARAM_END("qp-b-enable", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-qp-range", OMX_QcomIndexParamVideoIPBQPRange, OMX_DirOutput)
    ADD_PARAM    ("qp-i-min", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-i-max", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-p-min", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-p-max", OMX_AndroidVendorValueInt32)
    ADD_PARAM    ("qp-b-min", OMX_AndroidVendorValueInt32)
    ADD_PARAM_END("qp-b-max", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-low-latency", OMX_QcomIndexConfigVideoVencLowLatencyMode, OMX_DirInput)
    ADD_PARAM_END("enable", OMX_AndroidVendorValueInt32)

    ADD_EXTENSION("qti-ext-enc-dynamic-frame-rate", OMX_IndexConfigVideoFramerate, OMX_DirOutput)
    ADD_PARAM_END("frame-rate", OMX_AndroidVendorValueInt32)
}

OMX_ERRORTYPE omx_video::get_vendor_extension_config(
                OMX_CONFIG_ANDROID_VENDOR_EXTENSIONTYPE *ext) {
    if (ext->nIndex >= mVendorExtensionStore.size()) {
        return OMX_ErrorNoMore;
    }

    const VendorExtension& vExt = mVendorExtensionStore[ext->nIndex];
    DEBUG_PRINT_LOW("VendorExt: getConfig: index=%u (%s)", ext->nIndex, vExt.name());

    vExt.copyInfoTo(ext);
    if (ext->nParamSizeUsed < vExt.paramCount()) {
        // this happens during initial getConfig to query only extension-name and param-count
        return OMX_ErrorNone;
    }

    // We now have sufficient params allocated in extension data passed.
    // Following code is to set the extension-specific data

    bool setStatus = true;

    switch ((OMX_U32)vExt.extensionIndex()) {
        case OMX_IndexConfigCommonRotate:
        {
            setStatus &= vExt.setParamInt32(ext, "angle", m_sConfigFrameRotation.nRotation);
            break;
        }
        case OMX_IndexConfigVideoAVCIntraPeriod:
        {
            setStatus &= vExt.setParamInt32(ext, "n-pframes", m_sConfigAVCIDRPeriod.nPFrames);
            setStatus &= vExt.setParamInt32(ext, "n-idr-period", m_sConfigAVCIDRPeriod.nIDRPeriod);
            break;
        }
        case OMX_QcomIndexParamVideoSliceSpacing:
        {
            if (vExt.isConfigKey(ext, "resync-marker-spacing-bits")) {
                setStatus &= vExt.setParamInt32(ext,
                        "resync-marker-spacing-bits", m_sSliceSpacing.nSliceSize);
            } else if (vExt.isConfigKey(ext, "spacing")) {
                setStatus &= vExt.setParamInt32(ext, "spacing", m_sSliceSpacing.nSliceSize);
            }
            break;
        }
        case OMX_IndexParamVideoProfileLevelCurrent:
        {
            setStatus &= vExt.setParamInt32(ext, "profile", m_sParamProfileLevel.eProfile);
            setStatus &= vExt.setParamInt32(ext, "level", m_sParamProfileLevel.eLevel);

            break;
        }
        case OMX_QTIIndexParamEnableAVTimerTimestamps:
        {
            setStatus &= vExt.setParamInt32(ext, "enable", m_sParamAVTimerTimestampMode.bEnable);
            break;
        }
        case OMX_QcomIndexParamVideoLTRCount:
        {
            setStatus &= vExt.setParamInt32(ext, "num-ltr-frames", m_sParamLTRCount.nCount);
            break;
        }
        case OMX_QcomIndexConfigVideoLTRUse:
        {
            setStatus &= vExt.setParamInt32(ext, "use-frame", m_sConfigLTRUse.nID);
            break;
        }
        case OMX_QcomIndexConfigVideoLTRMark:
        {
            break;
        }
        case OMX_QcomIndexParamVencAspectRatio:
        {
            setStatus &= vExt.setParamInt32(ext, "width", m_sSar.nSARWidth);
            setStatus &= vExt.setParamInt32(ext, "height", m_sSar.nSARHeight);
            break;
        }
        case OMX_QcomIndexParamIndexExtraDataType:
        {
            char exType[OMX_MAX_STRINGVALUE_SIZE+1];
            memset (exType,0, (sizeof(char)*OMX_MAX_STRINGVALUE_SIZE));
            if ((OMX_BOOL)(m_sExtraData & VEN_EXTRADATA_LTRINFO)){
                const char *extradataType = getStringForExtradataType(OMX_ExtraDataVideoLTRInfo);
                if((extradataType != NULL) && ((strlcat(exType, extradataType,
                    OMX_MAX_STRINGVALUE_SIZE)) >= OMX_MAX_STRINGVALUE_SIZE)) {
                    DEBUG_PRINT_LOW("extradata string size exceeds size %d",OMX_MAX_STRINGVALUE_SIZE );
                }
            }
            if ((OMX_BOOL)(m_sExtraData & VENC_EXTRADATA_MBINFO)) {
                const char *extradataType = getStringForExtradataType(OMX_ExtraDataVideoEncoderMBInfo);
                if (extradataType != NULL && exType[0]!=0) {
                    strlcat(exType,"|", OMX_MAX_STRINGVALUE_SIZE);
                }
                if((extradataType != NULL) && ((strlcat(exType, extradataType,
                    OMX_MAX_STRINGVALUE_SIZE)) >= OMX_MAX_STRINGVALUE_SIZE)) {
                    DEBUG_PRINT_LOW("extradata string size exceeds size %d",OMX_MAX_STRINGVALUE_SIZE );
                }
            }
            setStatus &= vExt.setParamString(ext, "types", exType);
            DEBUG_PRINT_LOW("VendorExt: getparam: Extradata %s",exType);
            break;
        }
        case OMX_QTIIndexParamCapabilitiesVTDriverVersion:
        {
            setStatus &= vExt.setParamInt32(ext, "number", 65536);
            break;
        }
        case OMX_QTIIndexParamCapabilitiesMaxLTR:
        {
            setStatus &= vExt.setParamInt32(ext, "max-count", 3);
            break;
        }
        case OMX_QTIIndexParamCapabilitiesMaxDownScaleRatio:
        {
            setStatus &= vExt.setParamInt32(ext, "max-downscale-factor", 8);
            break;
        }
        case OMX_QTIIndexParamCapabilitiesRotationSupport:
        {
            setStatus &= vExt.setParamInt32(ext, "rotation",1);
            break;
        }
        case OMX_QTIIndexParamCapabilitiesMaxTemporalLayers:
        {
            OMX_U32 nPLayerCountMax , nBLayerCountMax;
            if (!dev_get_temporal_layer_caps(&nPLayerCountMax,
                        &nBLayerCountMax)) {
                DEBUG_PRINT_ERROR("Failed to get temporal layer capabilities");
                break;
            }
            setStatus &= vExt.setParamInt32(ext, "max-p-count",nPLayerCountMax);
            setStatus &= vExt.setParamInt32(ext, "max-b-count",nBLayerCountMax);
            break;
        }
        case OMX_QcomIndexParamVencControlInputQueue:
        {
            setStatus &= vExt.setParamInt32(ext, "enable", m_sParamControlInputQueue.bEnable);
            break;
        }
        case OMX_IndexConfigTimePosition:
        {
            setStatus &= vExt.setParamInt64(ext, "timestamp", m_sConfigInputTrigTS.nTimestamp);
            break;
        }
        case OMX_QcomIndexConfigQp:
        {
            setStatus &= vExt.setParamInt32(ext, "value", m_sConfigQP.nQP);
            break;
        }
        case OMX_QcomIndexConfigBaseLayerId:
        {
            setStatus &= vExt.setParamInt32(ext, "value", m_sBaseLayerID.nPID);
            break;
        }
        case QOMX_IndexParamVideoInitialQp:
        {
            setStatus &= vExt.setParamInt32(ext, "qp-i", m_sParamInitqp.nQpI);
            setStatus &= vExt.setParamInt32(ext, "qp-p", m_sParamInitqp.nQpP);
            setStatus &= vExt.setParamInt32(ext, "qp-b", m_sParamInitqp.nQpB);
            setStatus &= vExt.setParamInt32(ext, "qp-i-enable", (m_sParamInitqp.bEnableInitQp & 0x1));
            setStatus &= vExt.setParamInt32(ext, "qp-p-enable", ((m_sParamInitqp.bEnableInitQp >> 0x1) & 0x1));
            setStatus &= vExt.setParamInt32(ext, "qp-b-enable", ((m_sParamInitqp.bEnableInitQp >> 0x2) & 0x1));
            break;
        }
        case OMX_QcomIndexParamVideoIPBQPRange:
        {
            setStatus &= vExt.setParamInt32(ext, "qp-i-min", m_sSessionIPBQPRange.minIQP);
            setStatus &= vExt.setParamInt32(ext, "qp-i-max", m_sSessionIPBQPRange.maxIQP);
            setStatus &= vExt.setParamInt32(ext, "qp-p-min", m_sSessionIPBQPRange.minPQP);
            setStatus &= vExt.setParamInt32(ext, "qp-p-max", m_sSessionIPBQPRange.maxPQP);
            setStatus &= vExt.setParamInt32(ext, "qp-b-min", m_sSessionIPBQPRange.minBQP);
            setStatus &= vExt.setParamInt32(ext, "qp-b-max", m_sSessionIPBQPRange.maxBQP);
            break;
        }
        case OMX_QcomIndexConfigVideoVencLowLatencyMode:
        {
            setStatus &= vExt.setParamInt32(ext, "enable", m_slowLatencyMode.bLowLatencyMode);
            break;
        }
        case OMX_IndexConfigVideoFramerate:
        {
            setStatus &= vExt.setParamInt32(ext, "frame-rate", m_sConfigFramerate.xEncodeFramerate >> 16);
            break;
        }
        default:
        {
            return OMX_ErrorNotImplemented;
        }
    }
    return setStatus ? OMX_ErrorNone : OMX_ErrorUnsupportedSetting;
}

OMX_ERRORTYPE omx_video::set_vendor_extension_config(
                OMX_CONFIG_ANDROID_VENDOR_EXTENSIONTYPE *ext) {

    DEBUG_PRINT_LOW("set_vendor_extension_config");
    if (ext->nIndex >= mVendorExtensionStore.size()) {
        DEBUG_PRINT_ERROR("unrecognized vendor extension index (%u) max(%u)",
                ext->nIndex, mVendorExtensionStore.size());
        return OMX_ErrorBadParameter;
    }

    const VendorExtension& vExt = mVendorExtensionStore[ext->nIndex];
    DEBUG_PRINT_LOW("VendorExt: setConfig: index=%u (%s)", ext->nIndex, vExt.name());

    OMX_ERRORTYPE err = OMX_ErrorNone;
    err = vExt.isConfigValid(ext);
    if (err != OMX_ErrorNone) {
        return OMX_ErrorUnsupportedSetting;
    }

    // mark this as set, regardless of set_config succeeding/failing.
    // App will know by inconsistent values in output-format
    vExt.set();

    bool valueSet = false;
    switch ((OMX_U32)vExt.extensionIndex()) {
        case OMX_IndexConfigCommonRotate:
        {
            OMX_CONFIG_ROTATIONTYPE rotationParam;
            memcpy(&rotationParam, &m_sConfigFrameRotation, sizeof(OMX_CONFIG_ROTATIONTYPE));
            valueSet |= vExt.readParamInt32(ext, "angle", &rotationParam.nRotation);
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: OMX_IndexConfigCommonRotate : %d",
                    rotationParam.nRotation);

            err = set_config(
                    NULL, OMX_IndexConfigCommonRotate, &rotationParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_IndexConfigCommonRotate failed !");
            }
            break;
        }
        case OMX_IndexConfigVideoAVCIntraPeriod:
        {
            OMX_VIDEO_CONFIG_AVCINTRAPERIOD idrConfig;
            memcpy(&idrConfig, &m_sConfigAVCIDRPeriod, sizeof(OMX_VIDEO_CONFIG_AVCINTRAPERIOD));
            valueSet |= vExt.readParamInt32(ext, "n-pframes", (OMX_S32 *)&(idrConfig.nPFrames));
            valueSet |= vExt.readParamInt32(ext, "n-idr-period", (OMX_S32 *)&(idrConfig.nIDRPeriod));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: AVC-intra-period : nP=%d, nIDR=%d",
                    idrConfig.nPFrames, idrConfig.nIDRPeriod);

            err = set_config(
                    NULL, OMX_IndexConfigVideoAVCIntraPeriod, &idrConfig);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_IndexConfigVideoAVCIntraPeriod failed !");
            }
            break;
        }
        case OMX_QcomIndexParamVideoSliceSpacing:
        {
            QOMX_VIDEO_PARAM_SLICE_SPACING_TYPE sliceSpacing;
            memcpy(&sliceSpacing, &m_sSliceSpacing, sizeof(QOMX_VIDEO_PARAM_SLICE_SPACING_TYPE));

            if (vExt.isConfigKey(ext, "qti-ext-enc-error-correction")) {
                sliceSpacing.eSliceMode = QOMX_SLICEMODE_BYTE_COUNT;
                valueSet |= vExt.readParamInt32(ext,
                    "resync-marker-spacing-bits", (OMX_S32 *)&(sliceSpacing.nSliceSize));
            } else if (vExt.isConfigKey(ext, "qti-ext-enc-slice")) {
                sliceSpacing.eSliceMode = QOMX_SLICEMODE_MB_COUNT;
                valueSet |= vExt.readParamInt32(ext,
                    "spacing", (OMX_S32 *)&(sliceSpacing.nSliceSize));
            } else {
              DEBUG_PRINT_ERROR("VENDOR-EXT: set_config: Slice Spacing : Incorrect Mode !");
              break;
            }

            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: slice spacing : mode %d size %d",
                    sliceSpacing.eSliceMode, sliceSpacing.nSliceSize);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexParamVideoSliceSpacing, &sliceSpacing);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_QcomIndexParamVideoSliceSpacing failed !");
            }
            break;
        }
        case OMX_IndexParamVideoProfileLevelCurrent:
        {
            OMX_VIDEO_PARAM_PROFILELEVELTYPE profileParam;
            memcpy(&profileParam, &m_sParamProfileLevel, sizeof(OMX_VIDEO_PARAM_PROFILELEVELTYPE));
            valueSet |= vExt.readParamInt32(ext, "profile", (OMX_S32 *)&(profileParam.eProfile));
            valueSet |= vExt.readParamInt32(ext, "level", (OMX_S32 *)&(profileParam.eLevel));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: custom-profile/level : profile=%u level=%u",
                    (OMX_U32)profileParam.eProfile, (OMX_U32)profileParam.eLevel);

            err = set_parameter(
                    NULL, OMX_IndexParamVideoProfileLevelCurrent, &profileParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_IndexParamVideoProfileLevelCurrent failed !");
            }

            break;
        }
        case OMX_QTIIndexParamEnableAVTimerTimestamps:
        {
            QOMX_ENABLETYPE avTimerEnableParam;
            memcpy(&avTimerEnableParam, &m_sParamAVTimerTimestampMode, sizeof(QOMX_ENABLETYPE));
            valueSet |= vExt.readParamInt32(ext, "enable", (OMX_S32 *)&(avTimerEnableParam.bEnable));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: AV-timer timestamp mode enable=%u", avTimerEnableParam.bEnable);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)OMX_QTIIndexParamEnableAVTimerTimestamps, &avTimerEnableParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QTIIndexParamEnableAVTimerTimestamps failed !");
            }

            break;
        }
        case OMX_QcomIndexParamVideoLTRCount:
        {
            QOMX_VIDEO_PARAM_LTRCOUNT_TYPE ltrCountParam;
            memcpy(&ltrCountParam, &m_sParamLTRCount, sizeof(QOMX_VIDEO_PARAM_LTRCOUNT_TYPE));
            valueSet |= vExt.readParamInt32(ext, "num-ltr-frames",
                                 (OMX_S32 *)&(ltrCountParam.nCount));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: LTR count =%d ", ltrCountParam.nCount);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)QOMX_IndexParamVideoLTRCount, &ltrCountParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QcomIndexParamVideoLTRCount failed !");
            }
            break;
        }
        case OMX_QcomIndexConfigVideoLTRUse:
        {
            QOMX_VIDEO_CONFIG_LTRUSE_TYPE ltrUseParam;
            OMX_INIT_STRUCT(&ltrUseParam, QOMX_VIDEO_CONFIG_LTRUSE_TYPE);
            ltrUseParam.nPortIndex = (OMX_U32)PORT_INDEX_IN;
            valueSet |= vExt.readParamInt32(ext, "use-frame", (OMX_S32 *)&(ltrUseParam.nID));
            if (!valueSet) {
                break;
            }
            DEBUG_PRINT_HIGH("VENDOR-EXT: LTR UseFrame id= %d ", ltrUseParam.nID);

            err = set_config(
                    NULL, (OMX_INDEXTYPE)QOMX_IndexConfigVideoLTRUse, &ltrUseParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QcomIndexConfigVideoLTRUse failed !");
            }
            break;
        }
        case OMX_QcomIndexConfigVideoLTRMark:
        {
            QOMX_VIDEO_CONFIG_LTRMARK_TYPE ltrMarkParam;
            OMX_INIT_STRUCT(&ltrMarkParam, QOMX_VIDEO_CONFIG_LTRMARK_TYPE);
            ltrMarkParam.nPortIndex = (OMX_U32)PORT_INDEX_IN;
            valueSet |= vExt.readParamInt32(ext, "mark-frame", (OMX_S32 *)&(ltrMarkParam.nID));
            if (!valueSet) {
                break;
            }
            DEBUG_PRINT_HIGH("VENDOR-EXT: LTR mark frame =%d ", ltrMarkParam.nID);

            err = set_config(
                    NULL, (OMX_INDEXTYPE)QOMX_IndexConfigVideoLTRMark, &ltrMarkParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_QcomIndexConfigVideoLTRMark failed !");
            }

            break;
        }
        case OMX_QcomIndexParamVencAspectRatio:
        {
            QOMX_EXTNINDEX_VIDEO_VENC_SAR aspectRatioParam;
            OMX_INIT_STRUCT(&aspectRatioParam, QOMX_EXTNINDEX_VIDEO_VENC_SAR);
            valueSet |= vExt.readParamInt32(ext, "width", (OMX_S32 *)&(aspectRatioParam.nSARWidth));
            valueSet |= vExt.readParamInt32(ext, "height", (OMX_S32 *)&(aspectRatioParam.nSARHeight));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: VencAspectRatio: width =%d, height=%d",
              aspectRatioParam.nSARWidth, aspectRatioParam.nSARHeight);
            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexParamVencAspectRatio, &aspectRatioParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QcomIndexParamVencAspectRatio failed !");
            }
            break;
        }
        case OMX_QcomIndexConfigQp:
        {
            OMX_SKYPE_VIDEO_CONFIG_QP qpValueParam;
            memcpy(&qpValueParam, &m_sConfigQP, sizeof(OMX_SKYPE_VIDEO_CONFIG_QP));
            valueSet |= vExt.readParamInt32(ext, "value", (OMX_S32 *)&(qpValueParam.nQP));
            if (!valueSet) {
                break;
            }
            DEBUG_PRINT_HIGH("VENDOR-EXT: OMX_QcomIndexConfigQp = %d ", qpValueParam.nQP);

            err = set_config(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexConfigQp, &qpValueParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_QcomIndexConfigQp failed !");
            }
            break;
        }
        case OMX_QcomIndexConfigBaseLayerId:
        {
            OMX_SKYPE_VIDEO_CONFIG_BASELAYERPID baseLayerPid;
            memcpy(&baseLayerPid, &m_sBaseLayerID,
                   sizeof(OMX_SKYPE_VIDEO_CONFIG_BASELAYERPID));
            OMX_INIT_STRUCT(&baseLayerPid, OMX_SKYPE_VIDEO_CONFIG_BASELAYERPID);
            valueSet |= vExt.readParamInt32(ext, "value", (OMX_S32 *)&(baseLayerPid.nPID));
            if (!valueSet) {
                break;
            }
            DEBUG_PRINT_HIGH("VENDOR-EXT: Config BaseLayerPID = %d ", baseLayerPid.nPID);

            err = set_config(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexConfigBaseLayerId, &baseLayerPid);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_QcomIndexConfigBaseLayerId failed !");
            }
            break;
        }
        case OMX_QcomIndexParamIndexExtraDataType:
        {
            QOMX_INDEXEXTRADATATYPE extraDataParam;
            char exType[OMX_MAX_STRINGVALUE_SIZE];
            OMX_INIT_STRUCT(&extraDataParam, QOMX_INDEXEXTRADATATYPE);
            valueSet |= vExt.readParamInt64(ext, "types", exType);
            if (!valueSet) {
                break;
            }
            char *rest = exType;
            char *token = strtok_r(exType, "|", &rest);
            do {
                extraDataParam.bEnabled = OMX_TRUE;
                extraDataParam.nIndex = (OMX_INDEXTYPE)getIndexForExtradataType(token);
                if (extraDataParam.nIndex < 0) {
                    DEBUG_PRINT_HIGH(" extradata %s not supported ",token);
                    continue;
                }
                if (extraDataParam.nIndex == (OMX_INDEXTYPE)OMX_ExtraDataVideoLTRInfo ||
                    extraDataParam.nIndex == (OMX_INDEXTYPE)OMX_ExtraDataVideoEncoderMBInfo) {
                    extraDataParam.nPortIndex = (OMX_U32)PORT_INDEX_OUT;
                }
                DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: extradata: enable for index = %d",
                                  extraDataParam.nIndex);
                err = set_parameter(
                       NULL, (OMX_INDEXTYPE)OMX_QcomIndexParamIndexExtraDataType, &extraDataParam);
                if (err != OMX_ErrorNone) {
                    DEBUG_PRINT_ERROR("set_config: OMX_QcomIndexParamIndexExtraDataType failed !");
                }
            } while ((token = strtok_r(NULL, "|", &rest)));
            break;
        }
        case OMX_QcomIndexParamVencControlInputQueue:
        {
            QOMX_ENABLETYPE controlInputQueueParam;
            memcpy(&controlInputQueueParam, &m_sParamControlInputQueue, sizeof(QOMX_ENABLETYPE));
            valueSet |= vExt.readParamInt32(ext, "enable", (OMX_S32 *)&(controlInputQueueParam.bEnable));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_param: control input queue enable=%u", controlInputQueueParam.bEnable);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexParamVencControlInputQueue, &controlInputQueueParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QcomIndexParamVencControlInputQueue failed !");
            }

            break;
        }
        case OMX_IndexConfigTimePosition:
        {
            OMX_TIME_CONFIG_TIMESTAMPTYPE triggerTimeStamp;
            memcpy(&triggerTimeStamp, &m_sConfigInputTrigTS, sizeof(OMX_TIME_CONFIG_TIMESTAMPTYPE));
            valueSet |= vExt.readParamInt64(ext, "timestamp", (OMX_S64 *)&(triggerTimeStamp.nTimestamp));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: trigger timestamp =%lld", triggerTimeStamp.nTimestamp);

            err = set_config(
                    NULL, (OMX_INDEXTYPE)OMX_IndexConfigTimePosition, &triggerTimeStamp);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_IndexConfigTimePosition failed !");
            }

            break;
        }
        case QOMX_IndexParamVideoInitialQp:
        {
            QOMX_EXTNINDEX_VIDEO_INITIALQP initQP;
            OMX_INIT_STRUCT(&initQP, QOMX_EXTNINDEX_VIDEO_INITIALQP);
            initQP.nPortIndex = (OMX_U32)PORT_INDEX_OUT;
            OMX_S32 enableIQp = (m_sParamInitqp.bEnableInitQp & 0x1);
            OMX_S32 enablePQp = ((m_sParamInitqp.bEnableInitQp >> 0x1) & 0x1);
            OMX_S32 enableBQp = ((m_sParamInitqp.bEnableInitQp >> 0x2) & 0x1);
            initQP.nQpI = m_sParamInitqp.nQpI;
            initQP.nQpP = m_sParamInitqp.nQpP;
            initQP.nQpB = m_sParamInitqp.nQpB;
            initQP.bEnableInitQp = m_sParamInitqp.bEnableInitQp;
            valueSet |= vExt.readParamInt32(ext, "qp-i", (OMX_S32 *)&(initQP.nQpI));
            valueSet |= vExt.readParamInt32(ext, "qp-b", (OMX_S32 *)&(initQP.nQpB));
            valueSet |= vExt.readParamInt32(ext, "qp-p", (OMX_S32 *)&(initQP.nQpP));
            valueSet |= vExt.readParamInt32(ext, "qp-i-enable", (OMX_S32 *)&enableIQp);
            valueSet |= vExt.readParamInt32(ext, "qp-p-enable", (OMX_S32 *)&enablePQp);
            valueSet |= vExt.readParamInt32(ext, "qp-b-enable", (OMX_S32 *)&enableBQp);
            initQP.bEnableInitQp = (((enableIQp == 0x1) << 0x0 ) | ((enablePQp == 0x1) << 0x1 ) | ((enableBQp == 0x1) << 0x2 ));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_param: QOMX_IndexParamVideoInitialQp I/B/P value: %d %d %d",
                initQP.nQpI,initQP.nQpB,initQP.nQpP);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)QOMX_IndexParamVideoInitialQp, &initQP);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: QOMX_IndexParamVideoInitialQp failed !");
            }
            break;
        }
        case OMX_QcomIndexParamVideoIPBQPRange:
        {
            OMX_QCOM_VIDEO_PARAM_IPB_QPRANGETYPE qpRange;
            memcpy(&qpRange, &m_sSessionIPBQPRange, sizeof(OMX_QCOM_VIDEO_PARAM_IPB_QPRANGETYPE));
            valueSet |= vExt.readParamInt32(ext, "qp-i-min", (OMX_S32 *)&(qpRange.minIQP));
            valueSet |= vExt.readParamInt32(ext, "qp-i-max", (OMX_S32 *)&(qpRange.maxIQP));
            valueSet |= vExt.readParamInt32(ext, "qp-p-min", (OMX_S32 *)&(qpRange.minPQP));
            valueSet |= vExt.readParamInt32(ext, "qp-p-max", (OMX_S32 *)&(qpRange.maxPQP));
            valueSet |= vExt.readParamInt32(ext, "qp-b-min", (OMX_S32 *)&(qpRange.minBQP));
            valueSet |= vExt.readParamInt32(ext, "qp-b-max", (OMX_S32 *)&(qpRange.maxBQP));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_param: OMX_QcomIndexParamVideoIPBQPRange for min/max value for I/P/B: %d-%d / %d-%d / %d-%d"
                ,qpRange.minIQP,qpRange.maxIQP,qpRange.minPQP,qpRange.maxPQP,qpRange.minBQP,qpRange.maxBQP);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexParamVideoIPBQPRange, &qpRange);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QcomIndexParamVideoIPBQPRange failed !");
            }
            break;
        }
        case OMX_QcomIndexConfigVideoVencLowLatencyMode:
        {
            QOMX_EXTNINDEX_VIDEO_VENC_LOW_LATENCY_MODE lowLatency;
            memcpy(&lowLatency, &m_slowLatencyMode, sizeof(QOMX_EXTNINDEX_VIDEO_VENC_LOW_LATENCY_MODE));
            valueSet |= vExt.readParamInt32(ext, "enable", (OMX_S32 *)&(lowLatency.bLowLatencyMode));
            if (!valueSet) {
                break;
            }

            DEBUG_PRINT_HIGH("VENDOR-EXT: set_param: low latency mode =%u", lowLatency.bLowLatencyMode);

            err = set_parameter(
                    NULL, (OMX_INDEXTYPE)OMX_QcomIndexConfigVideoVencLowLatencyMode, &lowLatency);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_param: OMX_QcomIndexConfigVideoVencLowLatencyMode failed !");
            }

            break;
        }
        case OMX_IndexConfigVideoFramerate:
        {
            OMX_CONFIG_FRAMERATETYPE rateParam;
            memcpy(&rateParam, &m_sConfigFramerate, sizeof(OMX_CONFIG_FRAMERATETYPE));
            valueSet |= vExt.readParamInt32(ext, "frame-rate", (OMX_S32 *)&rateParam.xEncodeFramerate);
            if (!valueSet) {
                break;
            }
            DEBUG_PRINT_HIGH("VENDOR-EXT: set_config: OMX_IndexConfigVideoFramerate : %d",
                    rateParam.xEncodeFramerate);
            rateParam.xEncodeFramerate <<= 16;
            err = set_config(
                    NULL, OMX_IndexConfigVideoFramerate, &rateParam);
            if (err != OMX_ErrorNone) {
                DEBUG_PRINT_ERROR("set_config: OMX_IndexConfigVideoFramerate failed !");
            }
            break;
        }
        case OMX_QTIIndexParamCapabilitiesVTDriverVersion:
        case OMX_QTIIndexParamCapabilitiesMaxLTR:
        case OMX_QTIIndexParamCapabilitiesMaxDownScaleRatio:
        case OMX_QTIIndexParamCapabilitiesRotationSupport:
        case OMX_QTIIndexParamCapabilitiesMaxTemporalLayers:
        {
             break;
        }
        default:
        {
            return OMX_ErrorNotImplemented;
        }
    }
    return err;
}
