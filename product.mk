MSM_VIDC_TARGET_LIST := kona lito bengal msmnile

ifeq ($(call is-board-platform-in-list, $(QCOM_BOARD_PLATFORMS)),true)

#MM_CORE
MM_CORE := libmm-omxcore
MM_CORE += libOmxCore
MM_CORE += libplatformconfig
MM_CORE += libcodec2_vndk.vendor
MM_CORE += libcodec2_hidl@1.0.vendor

PRODUCT_PACKAGES += $(MM_CORE)

endif

ifeq ($(call is-board-platform-in-list, $(MSM_VIDC_TARGET_LIST)), true)

MM_VIDEO := ExoplayerDemo
MM_VIDEO += libc2dcolorconvert
MM_VIDEO += libOmxSwVdec
MM_VIDEO += libOmxSwVencMpeg4
MM_VIDEO += libOmxVdec
MM_VIDEO += libOmxVenc
MM_VIDEO += libstagefrighthw
MM_VIDEO += init.qti.media.sh

PRODUCT_PACKAGES += $(MM_VIDEO)

include hardware/qcom/media/conf_files/$(TARGET_BOARD_PLATFORM)/$(TARGET_BOARD_PLATFORM).mk

endif

#---------------------------------------------------------------------------------------------------
# Runtime Codec2.0 enablement
#---------------------------------------------------------------------------------------------------
# TODO(PC): Override ccodec selection option back to defult (4).
#           QSSI is forcing this to '1'. Must be reverted
ifeq ($(call is-board-platform-in-list, lahaina holi msmnile), true)
    $(warning "Default Codec2.0 Enabled")
    PRODUCT_PROPERTY_OVERRIDES += debug.stagefright.ccodec=4
else
#Vendor property to enable Codec2 for audio and OMX for Video
    PRODUCT_PROPERTY_OVERRIDES += debug.stagefright.ccodec=1
endif
