// SPDX-License-Identifier: GPL-2.0
/*
 * Samsung Exynos SoC series Pablo driver
 *
 * Copyright (c) 2019 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_HW_DVFS_H
#define IS_HW_DVFS_H

/* dvfs table idx ex.different dvfa table  pure bayer or dynamic bayer */
#define IS_DVFS_TABLE_IDX_MAX 3

/* Tick count to get some time margin for DVFS scenario transition while streaming. */
#define IS_DVFS_CAPTURE_TICK (KEEP_FRAME_TICK_DEFAULT + 3)
#define IS_DVFS_DUAL_CAPTURE_TICK (2 * IS_DVFS_CAPTURE_TICK)

/* FIMC-IS DVFS SCENARIO enum */
enum IS_SCENARIO_ID {
	IS_SN_DEFAULT,
	IS_SN_FRONT2_PREVIEW,
	IS_SN_FRONT2_CAPTURE,
	IS_SN_FRONT2_CAMCORDING,
	IS_SN_FRONT2_CAMCORDING_CAPTURE,
	IS_SN_FRONT_PREVIEW,
	IS_SN_FRONT_PREVIEW_FULL,
	IS_SN_FRONT_CAPTURE,
	IS_SN_FRONT_CAMCORDING,
	IS_SN_FRONT_CAMCORDING_WHD,
	IS_SN_FRONT_CAMCORDING_UHD,
	IS_SN_FRONT_CAMCORDING_FHD_60FPS,
	IS_SN_FRONT_CAMCORDING_UHD_60FPS,
	IS_SN_FRONT_CAMCORDING_CAPTURE,
	IS_SN_FRONT_CAMCORDING_WHD_CAPTURE,
	IS_SN_FRONT_CAMCORDING_UHD_CAPTURE,
	IS_SN_FRONT_CAMCORDING_FHD_60FPS_CAPTURE,
	IS_SN_FRONT_CAMCORDING_UHD_60FPS_CAPTURE,
	IS_SN_FRONT_DUAL_SYNC_PREVIEW,
	IS_SN_FRONT_DUAL_SYNC_CAPTURE,
	IS_SN_FRONT_DUAL_SYNC_FHD_CAMCORDING,
	IS_SN_FRONT_DUAL_SYNC_FHD_CAMCORDING_CAPTURE,
	IS_SN_FRONT_VT1,
	IS_SN_FRONT_VT2,
	IS_SN_FRONT_VT4,
	IS_SN_FRONT_PREVIEW_HIGH_SPEED_FPS,
	IS_SN_REAR3_PREVIEW_FHD,
	IS_SN_REAR3_CAPTURE,
	IS_SN_REAR3_CAMCORDING_FHD,
	IS_SN_REAR3_CAMCORDING_FHD_CAPTURE,
	IS_SN_REAR2_PREVIEW_FHD,
	IS_SN_REAR2_CAPTURE,
	IS_SN_REAR2_CAMCORDING_FHD,
	IS_SN_REAR2_CAMCORDING_UHD_8K,
	IS_SN_REAR2_CAMCORDING_FHD_CAPTURE,
	IS_SN_REAR2_CAMCORDING_UHD_8K_CAPTURE,
	IS_SN_REAR_PREVIEW_FHD,
	IS_SN_REAR_PREVIEW_WHD,
	IS_SN_REAR_PREVIEW_UHD,
	IS_SN_REAR_PREVIEW_FULL,
	IS_SN_REAR_PREVIEW_UHD_60FPS,
	IS_SN_REAR_CAPTURE,
	IS_SN_REAR_CAMCORDING_FHD,
	IS_SN_REAR_CAMCORDING_HDR,
	IS_SN_REAR_CAMCORDING_WHD,
	IS_SN_REAR_CAMCORDING_UHD,
	IS_SN_REAR_CAMCORDING_UHD_60FPS,
	IS_SN_REAR_CAMCORDING_UHD_8K,
	IS_SN_REAR_CAMCORDING_FHD_CAPTURE,
	IS_SN_REAR_CAMCORDING_HDR_CAPTURE,
	IS_SN_REAR_CAMCORDING_WHD_CAPTURE,
	IS_SN_REAR_CAMCORDING_UHD_CAPTURE,
	IS_SN_REAR_CAMCORDING_UHD_8K_CAPTURE,
	IS_SN_SECURE_FRONT,
	IS_SN_DUAL_SYNC_PREVIEW,
	IS_SN_DUAL_SYNC_CAPTURE,
	IS_SN_DUAL_SYNC_PREVIEW_WHD,
	IS_SN_DUAL_SYNC_WHD_CAPTURE,
	IS_SN_DUAL_SYNC_FHD_CAMCORDING,
	IS_SN_DUAL_SYNC_FHD_CAMCORDING_CAPTURE,
	IS_SN_DUAL_SYNC_UHD_CAMCORDING,
	IS_SN_DUAL_SYNC_UHD_CAMCORDING_CAPTURE,
	IS_SN_DUAL_PREVIEW,
	IS_SN_DUAL_CAPTURE,
	IS_SN_DUAL_FHD_CAMCORDING,
	IS_SN_DUAL_FHD_CAMCORDING_CAPTURE,
	IS_SN_DUAL_UHD_CAMCORDING,
	IS_SN_DUAL_UHD_CAMCORDING_CAPTURE,
	IS_SN_PIP_PREVIEW,
	IS_SN_PIP_CAPTURE,
	IS_SN_PIP_CAMCORDING,
	IS_SN_PIP_CAMCORDING_CAPTURE,
	IS_SN_PREVIEW_HIGH_SPEED_FPS,
	IS_SN_VIDEO_HIGH_SPEED_60FPS_SWVDIS,
	IS_SN_VIDEO_HIGH_SPEED_60FPS,
	IS_SN_VIDEO_HIGH_SPEED_120FPS,
	IS_SN_VIDEO_HIGH_SPEED_240FPS,
	IS_SN_VIDEO_HIGH_SPEED_DUALFPS,
	IS_SN_VIDEO_HIGH_SPEED_60FPS_CAPTURE,
	IS_SN_DUAL_TOF,
	IS_SN_EXT_DUAL,
	IS_SN_EXT_REAR,
	IS_SN_EXT_FRONT,
	IS_SN_EXT_SECURE,
	IS_SN_MAX,
	IS_SN_END,
};

/* for assign staic / dynamic scenario check logic data */
int is_hw_dvfs_init(void *dvfs_data);
#endif /* IS_HW_DVFS_H */
