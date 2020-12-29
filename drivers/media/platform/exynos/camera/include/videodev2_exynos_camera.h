/*
 * Video for Linux Two header file for samsung
 *
 * Copyright (C) 2009, Dongsoo Nathaniel Kim<dongsoo45.kim@samsung.com>
 *
 * This header file contains several v4l2 APIs to be proposed to v4l2
 * community and until bein accepted, will be used restrictly in Samsung's
 * camera interface driver FIMC.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __LINUX_VIDEODEV2_EXYNOS_CAMERA_H
#define __LINUX_VIDEODEV2_EXYNOS_CAMERA_H

/* Values for 'capabilities' field */
/* Object detection device */
#define V4L2_CAP_OBJ_RECOGNITION	0x10000000
/* strobe control */
#define V4L2_CAP_STROBE			0x20000000

#define V4L2_CID_FOCUS_MODE		(V4L2_CID_CAMERA_CLASS_BASE+17)
/* Focus Methods */
enum v4l2_focus_mode {
	V4L2_FOCUS_MODE_AUTO		= 0,
	V4L2_FOCUS_MODE_MACRO		= 1,
	V4L2_FOCUS_MODE_MANUAL		= 2,
	V4L2_FOCUS_MODE_LASTP		= 2,
};

#define V4L2_CID_ZOOM_MODE		(V4L2_CID_CAMERA_CLASS_BASE+18)
/* Zoom Methods */
enum v4l2_zoom_mode {
	V4L2_ZOOM_MODE_CONTINUOUS	= 0,
	V4L2_ZOOM_MODE_OPTICAL		= 1,
	V4L2_ZOOM_MODE_DIGITAL		= 2,
	V4L2_ZOOM_MODE_LASTP		= 2,
};

/* Exposure Methods */
#define V4L2_CID_PHOTOMETRY		(V4L2_CID_CAMERA_CLASS_BASE+19)
enum v4l2_photometry_mode {
	V4L2_PHOTOMETRY_MULTISEG	= 0, /*Multi Segment*/
	V4L2_PHOTOMETRY_CWA		= 1, /*Centre Weighted Average*/
	V4L2_PHOTOMETRY_SPOT		= 2,
	V4L2_PHOTOMETRY_AFSPOT		= 3, /*Spot metering on focused point*/
	V4L2_PHOTOMETRY_LASTP		= V4L2_PHOTOMETRY_AFSPOT,
};

/* Manual exposure control items menu type: iris, shutter, iso */
#define V4L2_CID_CAM_APERTURE	(V4L2_CID_CAMERA_CLASS_BASE+20)
#define V4L2_CID_CAM_SHUTTER	(V4L2_CID_CAMERA_CLASS_BASE+21)
#define V4L2_CID_CAM_ISO	(V4L2_CID_CAMERA_CLASS_BASE+22)

/* Following CIDs are menu type */
#define V4L2_CID_SCENEMODE	(V4L2_CID_CAMERA_CLASS_BASE+23)
#define V4L2_CID_CAM_STABILIZE	(V4L2_CID_CAMERA_CLASS_BASE+24)
#define V4L2_CID_CAM_MULTISHOT	(V4L2_CID_CAMERA_CLASS_BASE+25)

/* Control dynamic range */
#define V4L2_CID_CAM_DR		(V4L2_CID_CAMERA_CLASS_BASE+26)

/* White balance preset control */
#define V4L2_CID_WHITE_BALANCE_PRESET	(V4L2_CID_CAMERA_CLASS_BASE+27)
#define V4L2_CID_CAM_SENSOR_FW_VER	(V4L2_CID_CAMERA_CLASS_BASE + 28)
#define V4L2_CID_CAM_PHONE_FW_VER	(V4L2_CID_CAMERA_CLASS_BASE + 29)

/* CID extensions */
#define V4L2_CID_ROTATION		(V4L2_CID_PRIVATE_BASE + 0)
#define V4L2_CID_PADDR_Y		(V4L2_CID_PRIVATE_BASE + 1)
#define V4L2_CID_PADDR_CB		(V4L2_CID_PRIVATE_BASE + 2)
#define V4L2_CID_PADDR_CR		(V4L2_CID_PRIVATE_BASE + 3)
#define V4L2_CID_PADDR_CBCR		(V4L2_CID_PRIVATE_BASE + 4)
#define V4L2_CID_OVERLAY_AUTO		(V4L2_CID_PRIVATE_BASE + 5)
#define V4L2_CID_OVERLAY_VADDR0		(V4L2_CID_PRIVATE_BASE + 6)
#define V4L2_CID_OVERLAY_VADDR1		(V4L2_CID_PRIVATE_BASE + 7)
#define V4L2_CID_OVERLAY_VADDR2		(V4L2_CID_PRIVATE_BASE + 8)
#define V4L2_CID_OVLY_MODE		(V4L2_CID_PRIVATE_BASE + 9)
#define V4L2_CID_DST_INFO		(V4L2_CID_PRIVATE_BASE + 10)
/* UMP secure id control */
#define V4L2_CID_GET_UMP_SECURE_ID	(V4L2_CID_PRIVATE_BASE + 11)
#define V4L2_CID_GET_PHY_SRC_YADDR	(V4L2_CID_PRIVATE_BASE + 12)
#define V4L2_CID_GET_PHY_SRC_CADDR	(V4L2_CID_PRIVATE_BASE + 13)
#define V4L2_CID_IMAGE_EFFECT_FN	(V4L2_CID_PRIVATE_BASE + 16)
#define V4L2_CID_IMAGE_EFFECT_APPLY	(V4L2_CID_PRIVATE_BASE + 17)
#define V4L2_CID_IMAGE_EFFECT_CB	(V4L2_CID_PRIVATE_BASE + 18)
#define V4L2_CID_IMAGE_EFFECT_CR	(V4L2_CID_PRIVATE_BASE + 19)
#define V4L2_CID_RESERVED_MEM_BASE_ADDR	(V4L2_CID_PRIVATE_BASE + 20)
#define V4L2_CID_FIMC_VERSION		(V4L2_CID_PRIVATE_BASE + 21)

#define V4L2_CID_STREAM_PAUSE			(V4L2_CID_PRIVATE_BASE + 53)
#define V4L2_CID_CACHE_FLUSH			(V4L2_CID_PRIVATE_BASE + 61)
#define V4L2_CID_RESERVED_MEM_SIZE		(V4L2_CID_PRIVATE_BASE + 63)

/* CID Extensions for camera sensor operations */
#define V4L2_CID_CAM_PREVIEW_ONOFF	(V4L2_CID_PRIVATE_BASE + 64)
#define V4L2_CID_CAM_CAPTURE		(V4L2_CID_PRIVATE_BASE + 65)
/* #define V4L2_CID_CAM_JPEG_MEMSIZE	(V4L2_CID_PRIVATE_BASE + 66) */

#define V4L2_CID_CAM_DATE_INFO_YEAR	(V4L2_CID_PRIVATE_BASE + 14)
#define V4L2_CID_CAM_DATE_INFO_MONTH	(V4L2_CID_PRIVATE_BASE + 15)
#define V4L2_CID_CAM_DATE_INFO_DATE	(V4L2_CID_PRIVATE_BASE + 22)
#define V4L2_CID_CAM_SENSOR_VER		(V4L2_CID_PRIVATE_BASE + 23)
#define V4L2_CID_CAM_FW_MINOR_VER	(V4L2_CID_PRIVATE_BASE + 24)
#define V4L2_CID_CAM_FW_MAJOR_VER	(V4L2_CID_PRIVATE_BASE + 25)
#define V4L2_CID_CAM_PRM_MINOR_VER	(V4L2_CID_PRIVATE_BASE + 26)
#define V4L2_CID_CAM_PRM_MAJOR_VER	(V4L2_CID_PRIVATE_BASE + 27)
#define V4L2_CID_CAM_FW_VER		(V4L2_CID_PRIVATE_BASE + 28)
#define V4L2_CID_CAM_SET_FW_ADDR	(V4L2_CID_PRIVATE_BASE + 29)
#define V4L2_CID_CAM_SET_FW_SIZE	(V4L2_CID_PRIVATE_BASE + 30)
#define V4L2_CID_CAM_UPDATE_FW		(V4L2_CID_PRIVATE_BASE + 31)
enum v4l2_firmware_mode {
	FW_MODE_UPDATE,
	FW_MODE_VERSION,
	FW_MODE_DUMP,
};

#define V4L2_CID_CAM_JPEG_MAIN_SIZE		(V4L2_CID_PRIVATE_BASE + 32)
#define V4L2_CID_CAM_JPEG_MAIN_OFFSET		(V4L2_CID_PRIVATE_BASE + 33)
#define V4L2_CID_CAM_JPEG_THUMB_SIZE		(V4L2_CID_PRIVATE_BASE + 34)
#define V4L2_CID_CAM_JPEG_THUMB_OFFSET		(V4L2_CID_PRIVATE_BASE + 35)
#define V4L2_CID_CAM_JPEG_POSTVIEW_OFFSET	(V4L2_CID_PRIVATE_BASE + 36)
#define V4L2_CID_CAM_JPEG_QUALITY	(V4L2_CID_PRIVATE_BASE + 37)
#define V4L2_CID_CAM_SENSOR_MAKER	(V4L2_CID_PRIVATE_BASE + 38)
#define V4L2_CID_CAM_SENSOR_OPTICAL	(V4L2_CID_PRIVATE_BASE + 39)
#define V4L2_CID_CAM_AF_VER_LOW		(V4L2_CID_PRIVATE_BASE + 40)
#define V4L2_CID_CAM_AF_VER_HIGH	(V4L2_CID_PRIVATE_BASE + 41)
#define V4L2_CID_CAM_GAMMA_RG_LOW	(V4L2_CID_PRIVATE_BASE + 42)
#define V4L2_CID_CAM_GAMMA_RG_HIGH	(V4L2_CID_PRIVATE_BASE + 43)
#define V4L2_CID_CAM_GAMMA_BG_LOW	(V4L2_CID_PRIVATE_BASE + 44)
#define V4L2_CID_CAM_GAMMA_BG_HIGH	(V4L2_CID_PRIVATE_BASE + 45)
#define V4L2_CID_CAM_DUMP_FW		(V4L2_CID_PRIVATE_BASE + 46)
#define V4L2_CID_CAM_GET_DUMP_SIZE	(V4L2_CID_PRIVATE_BASE + 47)
#define V4L2_CID_CAMERA_VT_MODE		(V4L2_CID_PRIVATE_BASE + 48)
#define V4L2_CID_CAMERA_VGA_BLUR	(V4L2_CID_PRIVATE_BASE + 49)
#define V4L2_CID_CAMERA_CAPTURE		(V4L2_CID_PRIVATE_BASE + 50)
#define V4L2_CID_CAMERA_HDR		(V4L2_CID_PRIVATE_BASE + 51)

#define V4L2_CID_MAIN_SW_DATE_INFO_YEAR		(V4L2_CID_PRIVATE_BASE + 54)
#define V4L2_CID_MAIN_SW_DATE_INFO_MONTH	(V4L2_CID_PRIVATE_BASE + 55)
#define V4L2_CID_MAIN_SW_DATE_INFO_DATE		(V4L2_CID_PRIVATE_BASE + 56)
#define V4L2_CID_MAIN_SW_FW_MINOR_VER		(V4L2_CID_PRIVATE_BASE + 57)
#define V4L2_CID_MAIN_SW_FW_MAJOR_VER		(V4L2_CID_PRIVATE_BASE + 58)
#define V4L2_CID_MAIN_SW_PRM_MINOR_VER		(V4L2_CID_PRIVATE_BASE + 59)
#define V4L2_CID_MAIN_SW_PRM_MAJOR_VER		(V4L2_CID_PRIVATE_BASE + 60)

#define V4L2_CID_FIMC_IS_BASE			(V4L2_CTRL_CLASS_CAMERA | 0x1000)
#define V4L2_CID_FIMC_IS_TUNE_BASE		(V4L2_CTRL_CLASS_CAMERA | 0x2000)
#define V4L2_CID_SENSOR_BASE			(V4L2_CTRL_CLASS_CAMERA | 0x3000)
#define V4L2_CID_CAMERAPP_BASE          (V4L2_CTRL_CLASS_CAMERA | 0x4000)

#define V4L2_CID_IS_S_STREAM			(V4L2_CID_FIMC_IS_BASE + 14)
enum is_set_stream {
	IS_DISABLE_STREAM,
	IS_ENABLE_STREAM
};

#define V4L2_CID_IS_G_STREAM			(V4L2_CID_FIMC_IS_BASE + 15)
#define V4L2_CID_IS_G_CAPABILITY		(V4L2_CID_FIMC_IS_BASE + 17)
#define V4L2_CID_IS_G_COMPLETES			(V4L2_CID_FIMC_IS_BASE + 18)
#define V4L2_CID_IS_BDS_WIDTH			(V4L2_CID_FIMC_IS_BASE + 19)
#define V4L2_CID_IS_BDS_HEIGHT			(V4L2_CID_FIMC_IS_BASE + 20)
#define V4L2_CID_IS_DVFS_LOCK			(V4L2_CID_FIMC_IS_BASE + 21)
#define V4L2_CID_IS_DVFS_UNLOCK			(V4L2_CID_FIMC_IS_BASE + 22)
#define V4L2_CID_IS_DVFS_CLUSTER0		(V4L2_CID_FIMC_IS_BASE + 23)
#define V4L2_CID_IS_DVFS_CLUSTER1		(V4L2_CID_FIMC_IS_BASE + 24)
#define V4L2_CID_IS_PREVIEW_STATE		(V4L2_CID_FIMC_IS_BASE + 25)
#define V4L2_CID_IS_DVFS_CLUSTER2		(V4L2_CID_FIMC_IS_BASE + 26)
#define V4L2_CID_IS_CHANGE_CHAIN_PATH		(V4L2_CID_FIMC_IS_BASE + 27)
#define V4L2_CID_IS_CHECK_CHAIN_STATE		(V4L2_CID_FIMC_IS_BASE + 28)
#define V4L2_CID_IS_S_USE_EXT_PLANE		(V4L2_CID_FIMC_IS_BASE + 29)

#define V4L2_CID_IS_FORCE_DONE			(V4L2_CID_FIMC_IS_BASE + 50)
#define V4L2_CID_IS_SET_SETFILE			(V4L2_CID_FIMC_IS_BASE + 51)
#define V4L2_CID_IS_S_BNS			(V4L2_CID_FIMC_IS_BASE + 52)
#define V4L2_CID_IS_G_BNS_SIZE			(V4L2_CID_FIMC_IS_BASE + 53)
#define V4L2_CID_IS_COLOR_RANGE			(V4L2_CID_FIMC_IS_BASE + 54)
#define V4L2_CID_IS_MIN_TARGET_FPS		(V4L2_CID_FIMC_IS_BASE + 55)
#define V4L2_CID_IS_MAX_TARGET_FPS		(V4L2_CID_FIMC_IS_BASE + 56)
#define V4L2_CID_IS_G_DTPSTATUS			(V4L2_CID_FIMC_IS_BASE + 57)
#define V4L2_CID_IS_END_OF_STREAM		(V4L2_CID_FIMC_IS_BASE + 58)
#define V4L2_CID_IS_MAP_BUFFER			(V4L2_CID_FIMC_IS_BASE + 59)
#define V4L2_CID_IS_INTENT			(V4L2_CID_FIMC_IS_BASE + 60)
#define V4L2_CID_IS_CAMERA_TYPE 		(V4L2_CID_FIMC_IS_BASE + 61)
enum is_fw_boot_mode {
	IS_COLD_BOOT = 0,  /* FrontCamera, 3rd-Party Camera */
	IS_WARM_BOOT,      /* SamsungCamera & RearCamera */
	IS_COLD_RESET,      /* Reset for camera using warm boot mode */
};

#define V4L2_CID_IS_G_MIPI_ERR			(V4L2_CID_FIMC_IS_BASE + 62)
#define V4L2_CID_IS_CAPTURE_EXPOSURETIME	(V4L2_CID_FIMC_IS_BASE + 67)
#define V4L2_CID_IS_FAST_CAPTURE_CONTROL	(V4L2_CID_FIMC_IS_BASE + 68)
#define V4L2_CID_IS_S_SENSOR_SIZE		(V4L2_CID_FIMC_IS_BASE + 69)
#define V4L2_CID_IS_G_VC1_FRAMEPTR		(V4L2_CID_FIMC_IS_BASE + 70)
#define V4L2_CID_IS_G_VC2_FRAMEPTR		(V4L2_CID_FIMC_IS_BASE + 71)
#define V4L2_CID_IS_G_VC3_FRAMEPTR		(V4L2_CID_FIMC_IS_BASE + 72)
#define V4L2_CID_IS_FDAE			(V4L2_CID_FIMC_IS_BASE + 73)
#define V4L2_CID_IS_FACTORY_APERTURE_CONTROL	(V4L2_CID_FIMC_IS_BASE + 74)
#define V4L2_CID_IS_S_TUNING_CONFIG		(V4L2_CID_FIMC_IS_BASE + 75)
#define V4L2_CID_IS_G_ACTIVE_CAMERA		(V4L2_CID_FIMC_IS_BASE + 76)
#define V4L2_CID_IS_FACTORY_OIS_FW_VER		(V4L2_CID_FIMC_IS_BASE + 77)
#define V4L2_CID_IS_FACTORY_OIS_HEA		(V4L2_CID_FIMC_IS_BASE + 78)

#define V4L2_CID_IS_S_NFD_DATA			(V4L2_CID_FIMC_IS_BASE + 79)
#define V4L2_CID_IS_G_SETFILE_VERSION	(V4L2_CID_FIMC_IS_BASE + 80)
#define V4L2_CID_IS_HW_SYNC_CAMERA	(V4L2_CID_FIMC_IS_BASE + 81)
#define V4L2_CID_IS_S_STANDBY_OFF	(V4L2_CID_FIMC_IS_BASE + 82)
#define V4L2_CID_IS_CONVERT_BUFFER_SECURE_TO_NON_SUCURE		(V4L2_CID_FIMC_IS_BASE + 83)

#define V4L2_CID_IS_SCENE_MODE			(V4L2_CID_FIMC_IS_BASE + 667)

#define V4L2_CID_IS_OPENING_HINT		(V4L2_CID_FIMC_IS_BASE + 670)
enum is_opening_hint {
	IS_OPENING_HINT_NONE,
	IS_OPENING_HINT_FASTEN_AE,
	IS_OPENING_HINT_PREVIOUS_AE,
	IS_OPENING_HINT_MAX,
};

#define V4L2_CID_IS_CLOSING_HINT		(V4L2_CID_FIMC_IS_BASE + 671)
enum is_closing_hint {
	IS_CLOSING_HINT_NONE,
	IS_CLOSING_HINT_SWITCHING,
	IS_CLOSING_HINT_FINISHING,
	IS_CLOSING_HINT_MAX,
};

#define V4L2_CID_IS_SECURE_MODE			(V4L2_CID_FIMC_IS_BASE + 700)
#define V4L2_CID_IS_DEBUG_DUMP			(V4L2_CID_FIMC_IS_BASE + 900)
#define V4L2_CID_IS_DEBUG_SYNC_LOG		(V4L2_CID_FIMC_IS_BASE + 901)
#define V4L2_CID_IS_HAL_VERSION			(V4L2_CID_FIMC_IS_BASE + 902)
enum is_transient_action {
	ACTION_NONE = 0,
	ACTION_ZOOMING,
	ACTION_MANUAL_FOCUSING,
	ACTION_MAX,
};
#define V4L2_CID_IS_TRANSIENT_ACTION             (V4L2_CID_FIMC_IS_BASE + 903)
#define V4L2_CID_IS_FORCE_FLASH_MODE	         (V4L2_CID_FIMC_IS_BASE + 904)

#define V4L2_CID_ISASB0_G_CHKOUT			(V4L2_CID_FIMC_IS_BASE + 0xC00)
#define V4L2_CID_ISASB1_G_CHKOUT			(V4L2_CID_FIMC_IS_BASE + 0xC01)
#define V4L2_CID_ISASB2_G_CHKOUT			(V4L2_CID_FIMC_IS_BASE + 0xC02)
#define V4L2_CID_IS_G_SFRTEST			(V4L2_CID_FIMC_IS_BASE + 0xC03)

enum v4l2_is_hal_version {
	IS_HAL_VER_1_0,
	IS_HAL_VER_3_2,
	IS_HAL_VER_MAX,
};

#define V4L2_CID_FLASH_SET_CAL_EN                       (V4L2_CID_FIMC_IS_TUNE_BASE + 5)
#define V4L2_CID_FLASH_SET_BY_CAL_CH0                   (V4L2_CID_FIMC_IS_TUNE_BASE + 6)
#define V4L2_CID_FLASH_SET_BY_CAL_CH1                   (V4L2_CID_FIMC_IS_TUNE_BASE + 7)
#define V4L2_CID_GYRO_SELF_TEST                                (V4L2_CID_FIMC_IS_TUNE_BASE + 8)

#define V4L2_CID_SENSOR_SET_AE_TARGET			(V4L2_CID_SENSOR_BASE + 1)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_1x1_2		(V4L2_CID_SENSOR_BASE + 2)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_1x3_4		(V4L2_CID_SENSOR_BASE + 3)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_2x1_2		(V4L2_CID_SENSOR_BASE + 4)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_2x3_4		(V4L2_CID_SENSOR_BASE + 5)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_3x1_2		(V4L2_CID_SENSOR_BASE + 6)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_3x3_4		(V4L2_CID_SENSOR_BASE + 7)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_4x1_2		(V4L2_CID_SENSOR_BASE + 8)
#define V4L2_CID_SENSOR_SET_AE_WEIGHT_4x3_4		(V4L2_CID_SENSOR_BASE + 9)
#define V4L2_CID_SENSOR_SET_RG_WEIGHT			(V4L2_CID_SENSOR_BASE + 10)
#define V4L2_CID_SENSOR_SET_AE_SPEED			(V4L2_CID_SENSOR_BASE + 11)
#define V4L2_CID_SENSOR_SET_SHUTTER			(V4L2_CID_SENSOR_BASE + 12)
#define V4L2_CID_SENSOR_SET_GAIN			(V4L2_CID_SENSOR_BASE + 13)
#define V4L2_CID_SENSOR_SET_BIT_CONVERTING		(V4L2_CID_SENSOR_BASE + 14)
#define V4L2_CID_SENSOR_SET_AUTO_EXPOSURE		(V4L2_CID_SENSOR_BASE + 15)
#define V4L2_CID_SENSOR_SET_FRAME_RATE			(V4L2_CID_SENSOR_BASE + 16)
#define V4L2_CID_SENSOR_SET_FRAME_DURATION		(V4L2_CID_SENSOR_BASE + 17)
#define V4L2_CID_SENSOR_SET_ANALOG_GAIN                 (V4L2_CID_SENSOR_BASE + 18)
#define V4L2_CID_SENSOR_SET_DIGITAL_GAIN                (V4L2_CID_SENSOR_BASE + 19)
#define V4L2_CID_SENSOR_SET_LASER_CONTORL               (V4L2_CID_SENSOR_BASE + 20)
#define V4L2_CID_SENSOR_SET_EXTENDEDMODE		(V4L2_CID_SENSOR_BASE + 21)
#define V4L2_CID_SENSOR_SET_TOF_AUTO_FOCUS		(V4L2_CID_SENSOR_BASE + 22)
#define V4L2_CID_SENSOR_SET_CAPTURE_INTENT_INFO		(V4L2_CID_SENSOR_BASE + 24)

#define V4L2_CID_SENSOR_DEINIT                          (V4L2_CID_SENSOR_BASE + 90)
#define V4L2_CID_SENSOR_NOTIFY_VSYNC                    (V4L2_CID_SENSOR_BASE + 91)
#define V4L2_CID_SENSOR_NOTIFY_VBLANK                   (V4L2_CID_SENSOR_BASE + 92)
#define V4L2_CID_SENSOR_NOTIFY_FLASH_FIRE               (V4L2_CID_SENSOR_BASE + 93)
#define V4L2_CID_SENSOR_NOTIFY_ACTUATOR                 (V4L2_CID_SENSOR_BASE + 94)
#define V4L2_CID_SENSOR_NOTIFY_M2M_ACTUATOR             (V4L2_CID_SENSOR_BASE + 95)
#define V4L2_CID_SENSOR_NOTIFY_ACTUATOR_INIT            (V4L2_CID_SENSOR_BASE + 96)

#define V4L2_CID_SENSOR_GET_MIN_EXPOSURE_TIME           (V4L2_CID_SENSOR_BASE + 100)
#define V4L2_CID_SENSOR_GET_MAX_EXPOSURE_TIME           (V4L2_CID_SENSOR_BASE + 101)
#define V4L2_CID_SENSOR_GET_MIN_ANALOG_GAIN             (V4L2_CID_SENSOR_BASE + 102)
#define V4L2_CID_SENSOR_GET_MAX_ANALOG_GAIN             (V4L2_CID_SENSOR_BASE + 103)
#define V4L2_CID_SENSOR_GET_MIN_DIGITAL_GAIN            (V4L2_CID_SENSOR_BASE + 104)
#define V4L2_CID_SENSOR_GET_MAX_DIGITAL_GAIN            (V4L2_CID_SENSOR_BASE + 105)
#define V4L2_CID_SENSOR_ADJUST_FRAME_DURATION           (V4L2_CID_SENSOR_BASE + 106)
#define V4L2_CID_SENSOR_ADJUST_ANALOG_GAIN              (V4L2_CID_SENSOR_BASE + 107)
#define V4L2_CID_SENSOR_GET_ANALOG_GAIN                 (V4L2_CID_SENSOR_BASE + 108)
#define V4L2_CID_SENSOR_GET_DIGITAL_GAIN                (V4L2_CID_SENSOR_BASE + 109)
#define V4L2_CID_SENSOR_GET_PD_VALUE                    (V4L2_CID_SENSOR_BASE + 110)

/* for FRS */
#define V4L2_CID_SENSOR_SET_FRS_CONTROL			(V4L2_CID_SENSOR_BASE + 120)
enum v4l2_cis_frs_command {
	FRS_SSM_START = 0,			/* Only used in 3statck sensor */
	FRS_SSM_MANUAL_CUE_ENABLE,		/* Only used in 3statck sensor */
	FRS_SSM_STOP,
	FRS_SSM_MODE_AUTO_MANUAL_CUE_16,	/* Only used in 3statck sensor */
	FRS_SSM_MODE_AUTO_MANUAL_CUE_32,	/* Only used in 3statck sensor */
	FRS_SSM_MODE_AUTO_MANUAL_CUE_48,	/* Only used in 3statck sensor */
	FRS_SSM_MODE_AUTO_MANUAL_CUE_64,	/* Only used in 3statck sensor */
	FRS_SSM_MODE_ONLY_MANUAL_CUE,		/* Only used in 3statck sensor */
	FRS_SSM_MODE_FACTORY_TEST,
	FRS_DRAM_TEST_SECTION2,
	FRS_SSM_MODE_FLICKER_DETECT_OFF,  	/* Only used in 2statck sensor */
	FRS_SSM_MODE_FLICKER_DETECT_ENABLE,	/* Only used in 2statck sensor */
	FRS_SSM_MODE_FPS_960, 			/* Only used in 2statck sensor */
	FRS_SSM_MODE_FPS_480, 			/* Only used in 2statck sensor */
	FRS_SSM_MANUAL_MODE_START, 		/* Only used in 2statck sensor */
	FRS_SSM_AUTO_MODE_START, 		/* Only used in 2statck sensor */
	FRS_SSM_MODE_MITIGATION_ENABLE, 	/* Only used in 2statck sensor */
	FRS_CMD_MAX,
};
#define V4L2_CID_SENSOR_SET_SSM_ROI			(V4L2_CID_SENSOR_BASE + 121)
#define V4L2_CID_IS_GET_DUAL_CAL			(V4L2_CID_SENSOR_BASE + 122)

#define V4L2_CID_SENSOR_SET_SSM_THRESHOLD		(V4L2_CID_SENSOR_BASE + 123)
#define V4L2_CID_SENSOR_GET_SSM_THRESHOLD		(V4L2_CID_SENSOR_BASE + 124)
#define V4L2_CID_SENSOR_GET_SSM_GMC			(V4L2_CID_SENSOR_BASE + 125)
#define V4L2_CID_SENSOR_GET_SSM_FRAMEID			(V4L2_CID_SENSOR_BASE + 126)
#define V4L2_CID_SENSOR_SET_SSM_FLICKER			(V4L2_CID_SENSOR_BASE + 127)
#define V4L2_CID_SENSOR_GET_SSM_MD_THRESHOLD		(V4L2_CID_SENSOR_BASE + 128)
#define V4L2_CID_SENSOR_SET_SSM_GMC_TABLE_IDX		(V4L2_CID_SENSOR_BASE + 129)
#define V4L2_CID_SENSOR_SET_SSM_GMC_BLOCK		(V4L2_CID_SENSOR_BASE + 130)

#define V4L2_CID_SENSOR_GET_MODEL_ID			(V4L2_CID_SENSOR_BASE + 131)

#define V4L2_CID_SENSOR_GET_BINNING_RATIO		(V4L2_CID_SENSOR_BASE + 132)
#define V4L2_CID_IS_GET_REMOSAIC_CAL			(V4L2_CID_SENSOR_BASE + 135)

#define V4L2_CID_SENSOR_SET_FACTORY_CONTROL		(V4L2_CID_SENSOR_BASE + 140)
enum v4l2_cis_factory_control_command {
	FAC_CTRL_BIT_TEST = 0,
	FAC_CTRL_CMD_MAX,
};
#define V4L2_CID_SENSOR_SET_MODE_CHANGE			(V4L2_CID_SENSOR_BASE + 141)

#define V4L2_CID_ACTUATOR_GET_STATUS                    (V4L2_CID_SENSOR_BASE + 200)
#define V4L2_CID_ACTUATOR_SET_POSITION                  (V4L2_CID_SENSOR_BASE + 201)
#define V4L2_CID_ACTUATOR_GET_ACTUAL_POSITION           (V4L2_CID_SENSOR_BASE + 202)
#define V4L2_CID_ACTUATOR_UPDATE_DYNAMIC_META           (V4L2_CID_SENSOR_BASE + 203)
#define V4L2_CID_ACTUATOR_SOFT_LANDING			(V4L2_CID_SENSOR_BASE + 204)

#define V4L2_CID_FLASH_SET_MODE                         (V4L2_CID_SENSOR_BASE + 300)
#define V4L2_CID_FLASH_SET_INTENSITY                    (V4L2_CID_SENSOR_BASE + 301)
#define V4L2_CID_FLASH_SET_FIRING_TIME                  (V4L2_CID_SENSOR_BASE + 302)
#define V4L2_CID_FLASH_SET_FIRE                         (V4L2_CID_SENSOR_BASE + 303)

#define V4L2_CID_FLASH_GET_MODE                         (V4L2_CID_SENSOR_BASE + 304)
#define V4L2_CID_FLASH_GET_INTENSITY                    (V4L2_CID_SENSOR_BASE + 305)
#define V4L2_CID_FLASH_GET_FIRING_TIME                  (V4L2_CID_SENSOR_BASE + 306)
#define V4L2_CID_FLASH_GET_DELAYED_PREFLASH_TIME        (V4L2_CID_SENSOR_BASE + 307)


#define V4L2_CID_EEPROM_GET_SENSOR_ID			(V4L2_CID_SENSOR_BASE + 310)

#define V4L2_CID_ISASB0_SET			(V4L2_CID_SENSOR_BASE + 0xC00)
#define V4L2_CID_ISASB1_SET			(V4L2_CID_SENSOR_BASE + 0xC01)
#define V4L2_CID_ISASB2_SET			(V4L2_CID_SENSOR_BASE + 0xC02)
#define V4L2_CID_ISASB0_WAITDONE		(V4L2_CID_SENSOR_BASE + 0xC03)
#define V4L2_CID_ISASB1_WAITDONE		(V4L2_CID_SENSOR_BASE + 0xC04)
#define V4L2_CID_ISASB2_WAITDONE		(V4L2_CID_SENSOR_BASE + 0xC05)

#define V4L2_CID_SET_VECTOR			(V4L2_CID_SENSOR_BASE + 0xC10)
#define V4L2_CID_GET_VECTOR			(V4L2_CID_SENSOR_BASE + 0xC11)
#define V4L2_CID_SET_ASB_INPUT_PATH			(V4L2_CID_SENSOR_BASE + 0xC12)
#define V4L2_CID_SET_CAM_DMA_PATH		(V4L2_CID_SENSOR_BASE + 0xC13)

/* Camera Post-Processing IOCTL */
#define V4L2_CID_CAMERAPP_SENSOR_NUM			(V4L2_CID_CAMERAPP_BASE + 1)
#define V4L2_CID_CAMERAPP_GDC_GRID_CROP_START	(V4L2_CID_CAMERAPP_BASE + 2)
#define V4L2_CID_CAMERAPP_GDC_GRID_CROP_SIZE	(V4L2_CID_CAMERAPP_BASE + 3)
#define V4L2_CID_CAMERAPP_GDC_GRID_SENSOR_SIZE	(V4L2_CID_CAMERAPP_BASE + 4)
#define V4L2_CID_CAMERAPP_GDC_GRID_CONTROL	(V4L2_CID_CAMERAPP_BASE + 5)

#if 1
#define V4L2_CID_CAMERA_SCENE_MODE		(V4L2_CID_PRIVATE_BASE+70)

#define V4L2_CID_CAMERA_FLASH_MODE		(V4L2_CID_PRIVATE_BASE+71)
enum v4l2_flash_mode {
	FLASH_MODE_BASE,
	FLASH_MODE_OFF,
	FLASH_MODE_AUTO,
	FLASH_MODE_ON,
	FLASH_MODE_TORCH,
	FLASH_MODE_MAX,
};

#define V4L2_CID_CAMERA_BRIGHTNESS		(V4L2_CID_PRIVATE_BASE+72)
enum v4l2_ev_mode {
	EV_MINUS_4	= -4,
	EV_MINUS_3	= -3,
	EV_MINUS_2	= -2,
	EV_MINUS_1	= -1,
	EV_DEFAULT	= 0,
	EV_PLUS_1	= 1,
	EV_PLUS_2	= 2,
	EV_PLUS_3	= 3,
	EV_PLUS_4	= 4,
	EV_MAX,
};

#define V4L2_CID_CAMERA_WHITE_BALANCE	(V4L2_CID_PRIVATE_BASE+73)
enum v4l2_wb_mode {
	WHITE_BALANCE_BASE = 0,
	WHITE_BALANCE_AUTO,
	WHITE_BALANCE_SUNNY,
	WHITE_BALANCE_CLOUDY,
	WHITE_BALANCE_TUNGSTEN,
	WHITE_BALANCE_FLUORESCENT,
	WHITE_BALANCE_MAX,
};

#define V4L2_CID_CAMERA_EFFECT			(V4L2_CID_PRIVATE_BASE+74)
enum v4l2_effect_mode {
	IMAGE_EFFECT_BASE = 0,
	IMAGE_EFFECT_NONE,
	IMAGE_EFFECT_BNW,
	IMAGE_EFFECT_SEPIA,
	IMAGE_EFFECT_AQUA,
	IMAGE_EFFECT_ANTIQUE,
	IMAGE_EFFECT_NEGATIVE,
	IMAGE_EFFECT_SHARPEN,
	IMAGE_EFFECT_MAX,
};

#define V4L2_CID_CAMERA_ISO			(V4L2_CID_PRIVATE_BASE+75)
enum v4l2_iso_mode {
	ISO_AUTO = 0,
	ISO_50,
	ISO_100,
	ISO_200,
	ISO_400,
	ISO_800,
	ISO_1600,
	ISO_SPORTS,
	ISO_NIGHT,
	ISO_MOVIE,
	ISO_MAX,
};

#define V4L2_CID_CAMERA_METERING		(V4L2_CID_PRIVATE_BASE+76)
enum v4l2_metering_mode {
	METERING_BASE = 0,
	METERING_MATRIX,
	METERING_CENTER,
	METERING_SPOT,
	METERING_MAX,
};

#define V4L2_CID_CAMERA_CONTRAST		(V4L2_CID_PRIVATE_BASE+77)
enum v4l2_contrast_mode {
	CONTRAST_MINUS_2 = 0,
	CONTRAST_MINUS_1,
	CONTRAST_DEFAULT,
	CONTRAST_PLUS_1,
	CONTRAST_PLUS_2,
	CONTRAST_MAX,
};

#define V4L2_CID_CAMERA_SATURATION		(V4L2_CID_PRIVATE_BASE+78)
enum v4l2_saturation_mode {
	SATURATION_MINUS_2 = 0,
	SATURATION_MINUS_1,
	SATURATION_DEFAULT,
	SATURATION_PLUS_1,
	SATURATION_PLUS_2,
	SATURATION_MAX,
};

#define V4L2_CID_CAMERA_SHARPNESS		(V4L2_CID_PRIVATE_BASE+79)
enum v4l2_sharpness_mode {
	SHARPNESS_MINUS_2 = 0,
	SHARPNESS_MINUS_1,
	SHARPNESS_DEFAULT,
	SHARPNESS_PLUS_1,
	SHARPNESS_PLUS_2,
	SHARPNESS_MAX,
};

#define V4L2_CID_CAMERA_WDR			(V4L2_CID_PRIVATE_BASE+80)
enum v4l2_wdr_mode {
	WDR_OFF,
	WDR_ON,
	WDR_MAX,
};

#define V4L2_CID_CAMERA_ANTI_SHAKE		(V4L2_CID_PRIVATE_BASE+81)
enum v4l2_anti_shake_mode {
	ANTI_SHAKE_OFF,
	ANTI_SHAKE_STILL_ON,
	ANTI_SHAKE_MOVIE_ON,
	ANTI_SHAKE_MAX,
};

#define V4L2_CID_CAMERA_TOUCH_AF_START_STOP	(V4L2_CID_PRIVATE_BASE+82)
enum v4l2_touch_af {
	TOUCH_AF_STOP = 0,
	TOUCH_AF_START,
	TOUCH_AF_MAX,
};

#define V4L2_CID_CAMERA_SMART_AUTO		(V4L2_CID_PRIVATE_BASE+83)
enum v4l2_smart_auto {
	SMART_AUTO_OFF = 0,
	SMART_AUTO_ON,
	SMART_AUTO_MAX,
};

#define V4L2_CID_CAMERA_VINTAGE_MODE		(V4L2_CID_PRIVATE_BASE+84)
enum v4l2_vintage_mode {
	VINTAGE_MODE_BASE,
	VINTAGE_MODE_OFF,
	VINTAGE_MODE_NORMAL,
	VINTAGE_MODE_WARM,
	VINTAGE_MODE_COOL,
	VINTAGE_MODE_BNW,
	VINTAGE_MODE_MAX,
};

#define V4L2_CID_CAMERA_JPEG_QUALITY		(V4L2_CID_PRIVATE_BASE+85)
/* (V4L2_CID_PRIVATE_BASE+86) */
#define V4L2_CID_CAMERA_GPS_LATITUDE		(V4L2_CID_CAMERA_CLASS_BASE+30)
/* (V4L2_CID_PRIVATE_BASE+87) */
#define V4L2_CID_CAMERA_GPS_LONGITUDE	(V4L2_CID_CAMERA_CLASS_BASE + 31)
/* (V4L2_CID_PRIVATE_BASE+88) */
#define V4L2_CID_CAMERA_GPS_TIMESTAMP	(V4L2_CID_CAMERA_CLASS_BASE + 32)
/* (V4L2_CID_PRIVATE_BASE+89)*/
#define V4L2_CID_CAMERA_GPS_ALTITUDE	(V4L2_CID_CAMERA_CLASS_BASE + 33)
#define V4L2_CID_CAMERA_EXIF_TIME_INFO	(V4L2_CID_CAMERA_CLASS_BASE + 34)
#define V4L2_CID_CAMERA_GPS_PROCESSINGMETHOD	(V4L2_CID_CAMERA_CLASS_BASE+35)

#define V4L2_CID_FOCUS_AUTO_MODE		(V4L2_CID_CAMERA_CLASS_BASE+36)
enum  v4l2_focus_mode_type {
	V4L2_FOCUS_AUTO_NORMAL = 0,
	V4L2_FOCUS_AUTO_MACRO,
	V4L2_FOCUS_AUTO_CONTINUOUS,
	V4L2_FOCUS_AUTO_FACE_DETECTION,
	V4L2_FOCUS_AUTO_RECTANGLE,
	V4L2_FOCUS_AUTO_MAX,
};
#define V4L2_CID_FOCUS_AUTO_RECTANGLE_LEFT	(V4L2_CID_CAMERA_CLASS_BASE+37)
#define V4L2_CID_FOCUS_AUTO_RECTANGLE_TOP	(V4L2_CID_CAMERA_CLASS_BASE+38)
#define V4L2_CID_FOCUS_AUTO_RECTANGLE_WIDTH	(V4L2_CID_CAMERA_CLASS_BASE+39)
#define V4L2_CID_FOCUS_AUTO_RECTANGLE_HEIGHT	(V4L2_CID_CAMERA_CLASS_BASE+40)
#define V4L2_CID_CAMERA_ZOOM			(V4L2_CID_PRIVATE_BASE+90)
enum v4l2_zoom_level {
	ZOOM_LEVEL_0 = 0,
	ZOOM_LEVEL_1,
	ZOOM_LEVEL_2,
	ZOOM_LEVEL_3,
	ZOOM_LEVEL_4,
	ZOOM_LEVEL_5,
	ZOOM_LEVEL_6,
	ZOOM_LEVEL_7,
	ZOOM_LEVEL_8,
	ZOOM_LEVEL_9,
	ZOOM_LEVEL_10,
	ZOOM_LEVEL_11,
	ZOOM_LEVEL_12,
	ZOOM_LEVEL_MAX = 31,
};

#define V4L2_CID_CAMERA_FACE_DETECTION		(V4L2_CID_PRIVATE_BASE+91)
enum v4l2_face_detection {
	FACE_DETECTION_OFF = 0,
	FACE_DETECTION_ON,
	FACE_DETECTION_NOLINE,
	FACE_DETECTION_MAX,
};

#define V4L2_CID_CAMERA_SMART_AUTO_STATUS	(V4L2_CID_PRIVATE_BASE+92)
enum v4l2_smart_auto_status {
	SMART_AUTO_STATUS_AUTO = 0,
	SMART_AUTO_STATUS_LANDSCAPE,
	SMART_AUTO_STATUS_PORTRAIT,
	SMART_AUTO_STATUS_MACRO,
	SMART_AUTO_STATUS_NIGHT,
	SMART_AUTO_STATUS_PORTRAIT_NIGHT,
	SMART_AUTO_STATUS_BACKLIT,
	SMART_AUTO_STATUS_PORTRAIT_BACKLIT,
	SMART_AUTO_STATUS_ANTISHAKE,
	SMART_AUTO_STATUS_PORTRAIT_ANTISHAKE,
	SMART_AUTO_STATUS_MAX,
};

#define V4L2_CID_CAMERA_SET_AUTO_FOCUS		(V4L2_CID_PRIVATE_BASE+93)
enum v4l2_auto_focus {
	AUTO_FOCUS_OFF = 0,
	AUTO_FOCUS_ON,
	AUTO_FOCUS_MAX,
};

#define V4L2_CID_CAMERA_AEAWB_LOCK_UNLOCK	(V4L2_CID_PRIVATE_BASE+95)
enum v4l2_ae_awb_lockunlock {
	AE_UNLOCK_AWB_UNLOCK = 0,
	AE_LOCK_AWB_UNLOCK,
	AE_UNLOCK_AWB_LOCK,
	AE_LOCK_AWB_LOCK,
	AE_AWB_MAX
};

#define V4L2_CID_CAMERA_FACEDETECT_LOCKUNLOCK	(V4L2_CID_PRIVATE_BASE+96)
enum v4l2_face_lock {
	FACE_LOCK_OFF = 0,
	FACE_LOCK_ON,
	FIRST_FACE_TRACKING,
	FACE_LOCK_MAX,
};

#define V4L2_CID_CAMERA_OBJECT_POSITION_X	(V4L2_CID_PRIVATE_BASE+97)
#define V4L2_CID_CAMERA_OBJECT_POSITION_Y	(V4L2_CID_PRIVATE_BASE+98)
#define V4L2_CID_CAMERA_FOCUS_MODE		(V4L2_CID_PRIVATE_BASE+99)
enum v4l2_focusmode {
	FOCUS_MODE_AUTO = 0,
	FOCUS_MODE_MACRO,
	FOCUS_MODE_FACEDETECT,
	FOCUS_MODE_AUTO_DEFAULT,
	FOCUS_MODE_MACRO_DEFAULT,
	FOCUS_MODE_FACEDETECT_DEFAULT,
	FOCUS_MODE_INFINITY,
	FOCUS_MODE_FIXED,
	FOCUS_MODE_CONTINUOUS,
	FOCUS_MODE_CONTINUOUS_PICTURE,
	FOCUS_MODE_CONTINUOUS_PICTURE_MACRO,
	FOCUS_MODE_CONTINUOUS_VIDEO,
	FOCUS_MODE_TOUCH,
	FOCUS_MODE_MAX,
	FOCUS_MODE_DEFAULT = (1 << 8),
};

#define V4L2_CID_CAMERA_OBJ_TRACKING_STATUS	(V4L2_CID_PRIVATE_BASE+100)
enum v4l2_obj_tracking_status {
	OBJECT_TRACKING_STATUS_BASE,
	OBJECT_TRACKING_STATUS_PROGRESSING,
	OBJECT_TRACKING_STATUS_SUCCESS,
	OBJECT_TRACKING_STATUS_FAIL,
	OBJECT_TRACKING_STATUS_MISSING,
	OBJECT_TRACKING_STATUS_MAX,
};

#define V4L2_CID_CAMERA_OBJ_TRACKING_START_STOP	(V4L2_CID_PRIVATE_BASE+101)
enum v4l2_ot_start_stop {
	OT_STOP = 0,
	OT_START,
	OT_MAX,
};

#define V4L2_CID_CAMERA_CAF_START_STOP	(V4L2_CID_PRIVATE_BASE+102)
enum v4l2_caf_start_stop {
	CAF_STOP = 0,
	CAF_START,
	CAF_MAX,
};

#define V4L2_CID_CAMERA_AUTO_FOCUS_RESULT	(V4L2_CID_PRIVATE_BASE+103)
enum v4l2_af_status {
	CAMERA_AF_STATUS_IN_PROGRESS = 0,
	CAMERA_AF_STATUS_SUCCESS,
	CAMERA_AF_STATUS_FAIL,
	CAMERA_AF_STATUS_1ST_SUCCESS,
	CAMERA_AF_STATUS_MAX,
};
#define V4L2_CID_CAMERA_FRAME_RATE		(V4L2_CID_PRIVATE_BASE+104)
enum v4l2_frame_rate {
	FRAME_RATE_AUTO = 0,
	FRAME_RATE_7 = 7,
	FRAME_RATE_15 = 15,
	FRAME_RATE_20 = 20,
	FRAME_RATE_30 = 30,
	FRAME_RATE_60 = 60,
	FRAME_RATE_120 = 120,
	FRAME_RATE_MAX
};

#define V4L2_CID_CAMERA_ANTI_BANDING		(V4L2_CID_PRIVATE_BASE+105)
enum v4l2_anti_banding {
	ANTI_BANDING_AUTO = 0,
	ANTI_BANDING_50HZ = 1,
	ANTI_BANDING_60HZ = 2,
	ANTI_BANDING_OFF = 3,
};

#define V4L2_CID_CAMERA_SET_GAMMA	(V4L2_CID_PRIVATE_BASE+106)
enum v4l2_gamma_mode {
	GAMMA_OFF = 0,
	GAMMA_ON = 1,
	GAMMA_MAX,
};

#define V4L2_CID_CAMERA_SET_SLOW_AE	(V4L2_CID_PRIVATE_BASE+107)
enum v4l2_slow_ae_mode {
	SLOW_AE_OFF,
	SLOW_AE_ON,
	SLOW_AE_MAX,
};

#define V4L2_CID_CAMERA_BATCH_REFLECTION	(V4L2_CID_PRIVATE_BASE+108)
#define V4L2_CID_CAMERA_EXIF_ORIENTATION	(V4L2_CID_PRIVATE_BASE+109)

/* s1_camera [ Defense process by ESD input ] */
#define V4L2_CID_CAMERA_RESET			(V4L2_CID_PRIVATE_BASE+111)
#define V4L2_CID_CAMERA_CHECK_DATALINE		(V4L2_CID_PRIVATE_BASE+112)
#define V4L2_CID_CAMERA_CHECK_DATALINE_STOP	(V4L2_CID_PRIVATE_BASE+113)

#endif

/* Modify NTTS1 */
#if defined(CONFIG_ARIES_NTT)
#define V4L2_CID_CAMERA_AE_AWB_DISABLE_LOCK	(V4L2_CID_PRIVATE_BASE+114)
#endif
#define V4L2_CID_CAMERA_THUMBNAIL_NULL		(V4L2_CID_PRIVATE_BASE+115)
#define V4L2_CID_CAMERA_SENSOR_MODE		(V4L2_CID_PRIVATE_BASE+116)
enum v4l2_sensor_mode {
	SENSOR_CAMERA,
	SENSOR_MOVIE,
};

enum stream_mode_t {
	STREAM_MODE_CAM_OFF,
	STREAM_MODE_CAM_ON,
	STREAM_MODE_MOVIE_OFF,
	STREAM_MODE_MOVIE_ON,
};

#define V4L2_CID_CAMERA_EXIF_EXPTIME		(V4L2_CID_PRIVATE_BASE+117)
#define V4L2_CID_CAMERA_EXIF_FLASH		(V4L2_CID_PRIVATE_BASE+118)
#define V4L2_CID_CAMERA_EXIF_ISO		(V4L2_CID_PRIVATE_BASE+119)
#define V4L2_CID_CAMERA_EXIF_TV			(V4L2_CID_PRIVATE_BASE+120)
#define V4L2_CID_CAMERA_EXIF_BV			(V4L2_CID_PRIVATE_BASE+121)
#define V4L2_CID_CAMERA_EXIF_EBV		(V4L2_CID_PRIVATE_BASE+122)
#define V4L2_CID_CAMERA_CHECK_ESD		(V4L2_CID_PRIVATE_BASE+123)
#define V4L2_CID_CAMERA_APP_CHECK		(V4L2_CID_PRIVATE_BASE+124)

#define V4L2_CID_CAMERA_FACE_ZOOM  (V4L2_CID_PRIVATE_BASE + 132)
enum v4l2_face_zoom {
	FACE_ZOOM_STOP = 0,
	FACE_ZOOM_START
};
/* control for post processing block in ISP */
#define V4L2_CID_CAMERA_SET_ODC			(V4L2_CID_PRIVATE_BASE+127)
enum set_odc_mode {
	CAMERA_ODC_ON,
	CAMERA_ODC_OFF
};

#define V4L2_CID_CAMERA_SET_DIS			(V4L2_CID_PRIVATE_BASE+128)
enum set_dis_mode {
	CAMERA_DIS_ON,
	CAMERA_DIS_OFF
};

#define V4L2_CID_CAMERA_SET_3DNR		(V4L2_CID_PRIVATE_BASE+129)
enum set_3dnr_mode {
	CAMERA_3DNR_ON,
	CAMERA_3DNR_OFF
};

#define V4L2_CID_EMBEDDEDDATA_ENABLE		(V4L2_CID_PRIVATE_BASE+130)

#define V4L2_CID_CAMERA_CHECK_SENSOR_STATUS	(V4L2_CID_PRIVATE_BASE+150)
#define V4L2_CID_CAMERA_DEFAULT_FOCUS_POSITION	(V4L2_CID_PRIVATE_BASE+151)
/*      Pixel format FOURCC depth  Description  */
enum v4l2_pix_format_mode {
	V4L2_PIX_FMT_MODE_PREVIEW,
	V4L2_PIX_FMT_MODE_CAPTURE,
	V4L2_PIX_FMT_MODE_HDR,
	V4L2_PIX_FMT_MODE_VT_MIRROR,
	V4L2_PIX_FMT_MODE_VT_NONMIRROR,
};

/* 12  Y/CbCr 4:2:0 64x32 macroblocks */
#define V4L2_PIX_FMT_NV12T    v4l2_fourcc('T', 'V', '1', '2')
#define V4L2_PIX_FMT_NV21T    v4l2_fourcc('T', 'V', '2', '1')
#define V4L2_PIX_FMT_INTERLEAVED    v4l2_fourcc('I', 'T', 'L', 'V')


/*
 *  * V4L2 extention for digital camera
 *   */
/* Strobe flash light */
enum v4l2_strobe_control {
	/* turn off the flash light */
	V4L2_STROBE_CONTROL_OFF		= 0,
	/* turn on the flash light */
	V4L2_STROBE_CONTROL_ON		= 1,
	/* act guide light before splash */
	V4L2_STROBE_CONTROL_AFGUIDE	= 2,
	/* charge the flash light */
	V4L2_STROBE_CONTROL_CHARGE	= 3,
};

enum v4l2_strobe_conf {
	V4L2_STROBE_OFF			= 0,	/* Always off */
	V4L2_STROBE_ON			= 1,	/* Always splashes */
	/* Auto control presets */
	V4L2_STROBE_AUTO		= 2,
	V4L2_STROBE_REDEYE_REDUCTION	= 3,
	V4L2_STROBE_SLOW_SYNC		= 4,
	V4L2_STROBE_FRONT_CURTAIN	= 5,
	V4L2_STROBE_REAR_CURTAIN	= 6,
	/* Extra manual control presets */
	/* keep turned on until turning off */
	V4L2_STROBE_PERMANENT		= 7,
	V4L2_STROBE_EXTERNAL		= 8,
};

enum v4l2_strobe_status {
	V4L2_STROBE_STATUS_OFF		= 0,
	/* while processing configurations */
	V4L2_STROBE_STATUS_BUSY		= 1,
	V4L2_STROBE_STATUS_ERR		= 2,
	V4L2_STROBE_STATUS_CHARGING	= 3,
	V4L2_STROBE_STATUS_CHARGED	= 4,
};

/* capabilities field */
/* No strobe supported */
#define V4L2_STROBE_CAP_NONE		0x0000
/* Always flash off mode */
#define V4L2_STROBE_CAP_OFF		0x0001
/* Always use flash light mode */
#define V4L2_STROBE_CAP_ON		0x0002
/* Flashlight works automatic */
#define V4L2_STROBE_CAP_AUTO		0x0004
/* Red-eye reduction */
#define V4L2_STROBE_CAP_REDEYE		0x0008
/* Slow sync */
#define V4L2_STROBE_CAP_SLOWSYNC	0x0010
/* Front curtain */
#define V4L2_STROBE_CAP_FRONT_CURTAIN	0x0020
/* Rear curtain */
#define V4L2_STROBE_CAP_REAR_CURTAIN	0x0040
/* keep turned on until turning off */
#define V4L2_STROBE_CAP_PERMANENT	0x0080
/* use external strobe */
#define V4L2_STROBE_CAP_EXTERNAL	0x0100

/* Set mode and Get status */
struct v4l2_strobe {
	/* off/on/charge:0/1/2 */
	enum	v4l2_strobe_control control;
	/* supported strobe capabilities */
	__u32	capabilities;
	enum	v4l2_strobe_conf mode;
	enum	v4l2_strobe_status status;	/* read only */
	/* default is 0 and range of value varies from each models */
	__u32	flash_ev;
	__u32	reserved[4];
};

#define VIDIOC_S_STROBE     _IOWR('V', 83, struct v4l2_strobe)
#define VIDIOC_G_STROBE     _IOR('V', 84, struct v4l2_strobe)

/* Object recognition and collateral actions */
enum v4l2_recog_mode {
	V4L2_RECOGNITION_MODE_OFF	= 0,
	V4L2_RECOGNITION_MODE_ON	= 1,
	V4L2_RECOGNITION_MODE_LOCK	= 2,
};

enum v4l2_recog_action {
	V4L2_RECOGNITION_ACTION_NONE	= 0,	/* only recognition */
	V4L2_RECOGNITION_ACTION_BLINK	= 1,	/* Capture on blinking */
	V4L2_RECOGNITION_ACTION_SMILE	= 2,	/* Capture on smiling */
};

enum v4l2_recog_pattern {
	V4L2_RECOG_PATTERN_FACE		= 0, /* Face */
	V4L2_RECOG_PATTERN_HUMAN	= 1, /* Human */
	V4L2_RECOG_PATTERN_CHAR		= 2, /* Character */
};

#define VIDIOC_S_RECOGNITION	_IOWR('V', 85, struct v4l2_recognition)
#define VIDIOC_G_RECOGNITION	_IOR('V', 86, struct v4l2_recognition)

#endif /* __LINUX_VIDEODEV2_EXYNOS_CAMERA_H */
