/*
 * Samsung Exynos SoC series FIMC-IS2 driver
 *
 * Copyright (c) 2018 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_HW_CHAIN_V8_10_H
#define IS_HW_CHAIN_V8_10_H

#include "is-hw-api-common.h"
#include "is-groupmgr.h"
#include "is-config.h"

enum sysreg_csis_reg_name {
	SYSREG_R_C2_SWRESET,
	SYSREG_R_CSIS_PDP_SC_CON0,
	SYSREG_R_CSIS_PDP_SC_CON1,
	SYSREG_R_CSIS_PDP_SC_CON2,
	SYSREG_R_CSIS_PDP_SC_CON3,
	SYSREG_R_CSIS_PDP_SC_CON4,
	SYSREG_R_CSIS_PDP_SC_CON5,
	SYSREG_R_CSIS_PDP_SC_CON6,
	SYSREG_R_CSIS_FRAME_ID_EN,
	SYSREG_R_CSIS_PDP_SC_PDP_IN_EN,
	SYSREG_R_LH_GLUE_CON,
	SYSREG_R_CSIS_LH_QACTIVE_CON,
	SYSREG_R_MIPI_PHY_CON,
	SYSREG_R_MIPI_PHY_SEL,
	SYSREG_CSIS_REG_CNT
};

enum sysreg_ipp_reg_name {
	SYSREG_R_IPP_USER_CON0,
	SYSREG_R_IPP_USER_CON1,
	SYSREG_R_IPP_LH_QACTIVE_CON,
	SYSREG_IPP_REG_CNT
};

enum sysreg_tnr_reg_name {
	SYSREG_R_TNR_SW_RESETn,
	SYSREG_R_TNR_LH_AST_GLUE_TYPE,
	SYSREG_R_TNR_LH_ENABLE,
	SYSREG_TNR_REG_CNT
};

enum sysreg_dns_reg_name {
	SYSREG_R_DNS_USER_CON0,
	SYSREG_R_DNS_USER_CON1,
	SYSREG_DNS_REG_CNT
};

enum sysreg_itp_reg_name {
	SYSREG_R_ITP_USER_CON,
	SYSREG_ITP_REG_CNT
};

enum sysreg_mcsc_reg_name {
	SYSREG_R_MCSC_USER_CON0,
	SYSREG_R_MCSC_USER_CON1,
	SYSREG_R_MCSC_USER_CON2,
	SYSREG_MCSC_REG_CNT
};

enum sysreg_vra_reg_name {
	SYSREG_R_VRA_USER_CON0,
	SYSREG_VRA_REG_CNT
};

enum sysreg_csis_reg_field {
	SYSREG_F_C2_CSIS_SW_RESET,
	SYSREG_F_GLUEMUX_PDP0_VAL,
	SYSREG_F_GLUEMUX_PDP1_VAL,
	SYSREG_F_GLUEMUX_PDP2_VAL,
	SYSREG_F_GLUEMUX_CSIS_DMA0_OTF_SEL,
	SYSREG_F_GLUEMUX_CSIS_DMA1_OTF_SEL,
	SYSREG_F_GLUEMUX_CSIS_DMA2_OTF_SEL,
	SYSREG_F_GLUEMUX_CSIS_DMA3_OTF_SEL,
	SYSREG_F_FRAME_ID_EN_CSIS0,
	SYSREG_F_PDP2_IN_CSIS4_EN,
	SYSREG_F_PDP2_IN_CSIS3_EN,
	SYSREG_F_PDP2_IN_CSIS2_EN,
	SYSREG_F_PDP2_IN_CSIS1_EN,
	SYSREG_F_PDP2_IN_CSIS0_EN,
	SYSREG_F_PDP1_IN_CSIS4_EN,
	SYSREG_F_PDP1_IN_CSIS3_EN,
	SYSREG_F_PDP1_IN_CSIS2_EN,
	SYSREG_F_PDP1_IN_CSIS1_EN,
	SYSREG_F_PDP1_IN_CSIS0_EN,
	SYSREG_F_PDP0_IN_CSIS4_EN,
	SYSREG_F_PDP0_IN_CSIS3_EN,
	SYSREG_F_PDP0_IN_CSIS2_EN,
	SYSREG_F_PDP0_IN_CSIS1_EN,
	SYSREG_F_PDP0_IN_CSIS0_EN,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_ZOTF2_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_ZOTF1_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_ZOTF0_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_SOTF2_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_SOTF1_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_SOTF0_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF2_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF1_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF0_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_ZOTF2_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_ZOTF1_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_ZOTF0_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_SOTF2_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_SOTF1_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_SOTF0_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF2_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF1_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF0_IPPCSIS,
	SYSREG_F_LHM_AST_ZOTF2_IPPCSIS,
	SYSREG_F_LHM_AST_ZOTF1_IPPCSIS,
	SYSREG_F_LHM_AST_ZOTF0_IPPCSIS,
	SYSREG_F_LHM_AST_SOTF2_IPPCSIS,
	SYSREG_F_LHM_AST_SOTF1_IPPCSIS,
	SYSREG_F_LHM_AST_SOTF0_IPPCSIS,
	SYSREG_F_LHM_AST_OTF2_IPPCSIS,
	SYSREG_F_LHM_AST_OTF1_IPPCSIS,
	SYSREG_F_LHM_AST_OTF0_IPPCSIS,
	SYSREG_F_MIPI_RESETN_DPHY_S2,
	SYSREG_F_MIPI_RESETN_DPHY_S1,
	SYSREG_F_MIPI_RESETN_DPHY_S,
	SYSREG_F_MIPI_RESETN_DCPHY_S1,
	SYSREG_F_MIPI_RESETN_DCPHY_S,
	SYSREG_F_MIPI_SEPARATION_SEL,
	SYSREG_CSIS_REG_FIELD_CNT
};

enum sysreg_ipp_reg_field {
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_OTF0_IPPDNS,
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_SOTF2_IPPCSIS,
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_SOTF1_IPPCSIS,
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_SOTF0_IPPCSIS,
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_ZOTF2_IPPCSIS,
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_ZOTF1_IPPCSIS,
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_ZOTF0_IPPCSIS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF2_CSISIPP,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF1_CSISIPP,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF0_CSISIPP,
	SYSREG_F_TYPE_LHS_AST_GLUE_OTF0_IPPDNS,
	SYSREG_F_TYPE_LHS_AST_GLUE_SOTF2_IPPCSIS,
	SYSREG_F_TYPE_LHS_AST_GLUE_SOTF1_IPPCSIS,
	SYSREG_F_TYPE_LHS_AST_GLUE_SOTF0_IPPCSIS,
	SYSREG_F_TYPE_LHS_AST_GLUE_ZOTF2_IPPCSIS,
	SYSREG_F_TYPE_LHS_AST_GLUE_ZOTF1_IPPCSIS,
	SYSREG_F_TYPE_LHS_AST_GLUE_ZOTF0_IPPCSIS,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF2_CSISIP,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF1_CSISIP,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF0_CSISIP,
	SYSREG_F_GLUEMUX_OTFOUT_SEL_0,
	SYSREG_F_LHS_AST_OTF0_IPPDNS,
	SYSREG_F_LHS_AST_ZOTF2_IPPCSIS,
	SYSREG_F_LHS_AST_ZOTF1_IPPCSIS,
	SYSREG_F_LHS_AST_ZOTF0_IPPCSIS,
	SYSREG_F_LHS_AST_SOTF2_IPPCSIS,
	SYSREG_F_LHS_AST_SOTF1_IPPCSIS,
	SYSREG_F_LHS_AST_SOTF0_IPPCSIS,
	SYSREG_F_LHS_AST_OTF2_IPPCSIS,
	SYSREG_F_LHS_AST_OTF1_IPPCSIS,
	SYSREG_F_LHS_AST_OTF0_IPPCSIS,
	SYSREG_IPP_REG_FIELD_CNT
};

enum sysreg_tnr_reg_field {
	SYSREG_F_SW_RESETn_GLUE_OTF_TNRITP,
	SYSREG_F_SW_RESETn_GLUE_OTF_TNRDNS,
	SYSREG_F_GLUE_OTF_TNRITP,
	SYSREG_F_GLUE_OTF_TNRDNS,
	SYSREG_F_OTF_TNRITP,
	SYSREG_F_OTF_TNRDNS,
	SYSREG_TNR_REG_FIELD_CNT
};

enum sysreg_dns_reg_field {
	SYSREG_F_GLUEMUX_DNS0_VAL,
	SYSREG_F_AxCACHE_DNS,
	SYSREG_F_Enable_OTF3_IN_ITPDNS,
	SYSREG_F_Enable_OTF0_IN_ITPDNS,
	SYSREG_F_Enable_OTF_OUT_CTL_DNSITP,
	SYSREG_F_Enable_OTF_IN_CTL_ITPDNS,
	SYSREG_F_Enable_OTF3_OUT_DNSITP,
	SYSREG_F_Enable_OTF2_OUT_DNSITP,
	SYSREG_F_Enable_OTF1_OUT_DNSITP,
	SYSREG_F_Enable_OTF0_OUT_DNSITP,
	SYSREG_F_Enable_OTF_IN_TNRDNS,
	SYSREG_F_Enable_OTF_IN_IPPDNS,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF_TNRDNS,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF_IPPDNS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF_TNRDNS,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF_IPPDNS,
	SYSREG_DNS_REG_FIELD_CNT
};

enum sysreg_itp_reg_field {
	SYSREG_F_SW_RESETn_LHS_AST_GLUE_OTF_ITPMCSC,
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF_TNRITP,
	SYSREG_F_TYPE_LHS_AST_GLUE_OTF_ITPMCSC,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF_TNRITP,
	SYSREG_F_Enable_OTF_IN_TNRITP,
	SYSREG_F_Enable_OTF_OUT_ITPMCSC,
	SYSREG_F_Enable_OTF0_OUT_ITPDNS,
	SYSREG_F_Enable_OTF3_OUT_ITPDNS,
	SYSREG_F_Enable_OTF_IN_CTL_DNSITP,
	SYSREG_F_Enable_OTF_OUT_CTL_ITPDNS,
	SYSREG_F_Enable_OTF3_IN_DNSITP,
	SYSREG_F_Enable_OTF2_IN_DNSITP,
	SYSREG_F_Enable_OTF1_IN_DNSITP,
	SYSREG_F_Enable_OTF0_IN_DNSITP,
	SYSREG_ITP_REG_FIELD_CNT
};

enum sysreg_mcsc_reg_field {
	SYSREG_F_SW_RESETn_LHM_AST_GLUE_OTF_ITPMCSC,
	SYSREG_F_TYPE_LHM_AST_GLUE_OTF_ITPMCSC,
	SYSREG_F_ARQOS_GDC,
	SYSREG_F_AWQOS_GDC,
	SYSREG_F_ARQOS_MCSC,
	SYSREG_F_AWQOS_MCSC,
	SYSREG_F_AxCACHE_GDC,
	SYSREG_F_AxCACHE_MCSC,
	SYSREG_F_C2AGENT_D2_MCSC_M6S4_C2AGENT_SW_RESET,
	SYSREG_F_C2AGENT_D1_MCSC_M6S4_C2AGENT_SW_RESET,
	SYSREG_F_C2AGENT_D0_MCSC_M6S4_C2AGENT_SW_RESET,
	SYSREG_F_MCSC_C2COM_SW_RESET,
	SYSREG_F_Enable_OTF_IN_LHM_AST_D_ITPMCSC,
	SYSREG_MCSC_REG_FIELD_CNT
};

enum sysreg_vra_reg_field {
	SYSREG_F_AxCACHE_STR,
	SYSREG_F_AxCACHE_VRA,
	SYSREG_VRA_REG_FIELD_CNT
};

#define GROUP_HW_MAX (GROUP_SLOT_MAX)

#define IORESOURCE_CSIS_DMA	0
#define IORESOURCE_PDP_CORE0	1 /*not used */
#define IORESOURCE_PDP_CORE1	2 /*not used */
#define IORESOURCE_PDP_CORE2	3 /*not used */

#define IORESOURCE_3AA0		4
#define IORESOURCE_3AA1		5
#define IORESOURCE_3AA2		6
#define IORESOURCE_3AA_DMA_TOP	7
#define IORESOURCE_MEIP		8
#define IORESOURCE_ITP0		9
#define IORESOURCE_TNR		10
#define IORESOURCE_DNS0		11
#define IORESOURCE_MCSC		12
#define IORESOURCE_CLH0		13

#define GROUP_SENSOR_MAX_WIDTH	12000
#define GROUP_SENSOR_MAX_HEIGHT	9000
#define GROUP_PDP_MAX_WIDTH	12000
#define GROUP_PDP_MAX_HEIGHT	9000
#define GROUP_3AA_MAX_WIDTH	13696
#define GROUP_3AA_MAX_HEIGHT	9000
#define GROUP_ITP_MAX_WIDTH	5760
#define GROUP_ITP_MAX_HEIGHT	4352
#define GROUP_VRA_MAX_WIDTH	640
#define GROUP_VRA_MAX_HEIGHT	480
#define GROUP_CLAHE_MAX_WIDTH	12000
#define GROUP_CLAHE_MAX_HEIGHT	9000

/* RTA HEAP: 6MB */
#define IS_RESERVE_LIB_SIZE	(0x00600000)

/* ME/DRC DMA: 16640 kB = 16.25 MB */
/* (4 * 256 * 256) * 32 bytes per 1 3AA */
/* Max 2 3AAs can be used at the same time */
/* (4 * 256 * 256) additional buffer for reprocessing */
#define TAAISP_MEDRC_SIZE	(0x01040000)

/* ORBMCH DMA:  14.38 MB*/
/* Keypoint: 16 byte * 300 point * 9 regions */
/* Descriptor: 32 byte * 300 point * 9 regions */
/* ORB tot = Keypoint + descriptor + 16 byte for DMA align */
/* ORB DS: 3732496 bytes */
/* Max 2 3AAs can be used at the same time */
#define TAAISP_ORBMCH_SIZE	(0x00997540)

/* DDK DMA: 10.793MB */
/* 247840 bytes per 1 3AA */
/* Max 6 instances are supported */
/* 9830400 bytes need for Thumbnail & histogram */
/* 100K x 32(num of descriptor) x 3(num of 3AA */
#define IS_TAAISP_SIZE		(0x00ACB0C0)

/* TNR DMA: 123 MB*/
/* Image: ((Max width * Max height * 14 / 8) + 16) * 2 * 2(buffer) */
/* Weight: ((Max width * Max height / 2 / 2) * 2 * 2(buffer)) */
/* Max width: 4624, Max height: 3468 depends on scenario */
/* Max 3 instances are supported with SBWC margin (1.05) */
/* not used for reprocessing instance */
#define TAAISP_TNR_SIZE		(0x07B00000)

/* CLAHE DMA: 8.44MB :  */
/* (234912 * 8) bytes per 1 normal instance */
/* (234912 * 2) bytes per 1 reprocessing instance */
/* Max 6 instances are supported */
#define IS_CLAHE_SIZE		(0x00870000)
/* VRA: 1kB */
#define IS_VRA_SIZE			(0x00001000) /* FIXME: no need */
/* DDK HEAP: 60MB */
#define IS_HEAP_SIZE		(0x03C00000)

/* SETFILE: 9.0MB */
#define IS_SETFILE_SIZE		(0x00900000)

#define SYSREG_CSIS_BASE_ADDR	(0x15020000)
#define SYSREG_IPP_BASE_ADDR	(0x15220000)
#define SYSREG_ITP_BASE_ADDR	(0x15420000)
#define SYSREG_DNS_BASE_ADDR	(0x15520000)
#define SYSREG_VRA_BASE_ADDR	(0x15320000)
#define SYSREG_TNR_BASE_ADDR	(0x15820000)
#define SYSREG_MCSC_BASE_ADDR	(0x15620000)

#define HWFC_INDEX_RESET_ADDR	(0x15641050)

enum taaisp_chain_id {
	ID_3AA_0 = 0,	/* MEIP/DMA/3AA0 */
	ID_3AA_1 = 1,	/* MEIP/DMA/3AA1 */
	ID_ISP_0 = 2,	/* TNR/DNS/ITP0 */
	ID_ISP_1 = 3,	/* not used */
	ID_TPU_0 = 4,	/* not used */
	ID_TPU_1 = 5,	/* not used */
	ID_DCP	 = 6,	/* not used */
	ID_3AA_2 = 7,	/* DMA/3AA2 */
	ID_CLH_0 = 8,	/* CLAHE */
	ID_3AAISP_MAX
};

/* the number of interrupt source at each IP */
enum hwip_interrupt_map {
	INTR_HWIP1 = 0,
	INTR_HWIP2 = 1,
	INTR_HWIP3 = 2,
	INTR_HWIP4 = 3,
	INTR_HWIP5 = 4,
	INTR_HWIP6 = 5,
	INTR_HWIP_MAX
};

enum base_reg_index {
	REG_SETA = 0,
	REG_SETB = 1,
	REG_EXT1 = 2,
	REG_EXT2 = 3,
	REG_SET_MAX
};

#define INTR_ID_BASE_OFFSET	(INTR_HWIP_MAX)
#define GET_IRQ_ID(y, x)	(x - (INTR_ID_BASE_OFFSET * y))
#define valid_3aaisp_intr_index(intr_index) \
	(intr_index >= 0 && intr_index < INTR_HWIP_MAX)

/* TODO: update below for 9630 */
/* Specific interrupt map belonged to each IP */

/* MC-Scaler */
#define USE_DMA_BUFFER_INDEX		(0) /* 0 ~ 7 */
#define MCSC_WIDTH_ALIGN		(4)
#define MCSC_HEIGHT_ALIGN		(2)
#define MCSC_PRECISION			(20)
#define MCSC_POLY_RATIO_UP		(16)
#define MCSC_POLY_QUALITY_RATIO_DOWN	(4)
#define MCSC_POLY_RATIO_DOWN		(16)
#define MCSC_POLY_MAX_RATIO_DOWN	(256)
#define MCSC_POST_RATIO_DOWN		(16)
#define MCSC_POST_MAX_WIDTH		(1440)
/* #define MCSC_POST_WA */
/* #define MCSC_POST_WA_SHIFT	(8)*/	/* 256 = 2^8 */
#define MCSC_USE_DEJAG_TUNING_PARAM	(true)
/* #define MCSC_DNR_USE_TUNING		(true) */	/* DNR and DJAG TUNING PARAM are used exclusively. */
#define MCSC_SETFILE_VERSION		(0x14027434)
#define MCSC_DJAG_ENABLE_SENSOR_BRATIO	(2000)
#define MCSC_LINE_BUF_SIZE		(5760)

enum mc_scaler_interrupt_map {
	INTR_MC_SCALER_FRAME_END		= 0,
	INTR_MC_SCALER_FRAME_START		= 1,
	INTR_MC_SCALER_WDMA_FINISH		= 2,
	INTR_MC_SCALER_CORE_FINISH		= 3,
	INTR_MC_SCALER_INPUT_HORIZONTAL_OVF	= 7,
	INTR_MC_SCALER_INPUT_HORIZONTAL_UNF	= 8,
	INTR_MC_SCALER_INPUT_VERTICAL_OVF	= 9,
	INTR_MC_SCALER_INPUT_VERTICAL_UNF	= 10,
	INTR_MC_SCALER_OVERFLOW			= 11,
	INTR_MC_SCALER_OUTSTALL			= 12,	/* INPUT_FRAME_CRUSH */
	INTR_MC_SCALER_SHADOW_COPY_FINISH	= 16,
	INTR_MC_SCALER_SHADOW_COPY_FINISH_OVF	= 17,
	INTR_MC_SCALER_FM_SUB_FRAME_FINISH	= 20,
	INTR_MC_SCALER_FM_SUB_FRAME_START	= 21,
	INTR_MC_SCALER_STALL_TIMEOUT		= 24,
};
#define MCSC_INTR_MASK		((1 << INTR_MC_SCALER_WDMA_FINISH) \
				| (1 << INTR_MC_SCALER_CORE_FINISH) \
				| (1 << INTR_MC_SCALER_FM_SUB_FRAME_START) \
				| (1 << INTR_MC_SCALER_FM_SUB_FRAME_FINISH))

/* TODO: remove this, compile check only */
/* VRA */
#define VRA_CH1_INTR_CNT_PER_FRAME	(6)

/* Deprecated register. These are maintained for backward compatibility */
enum vra_chain0_interrupt_map {
	CH0INT_CIN_FR_ST			= 0,
	CH0INT_CIN_FR_END			= 1,
	CH0INT_CIN_LINE_ST			= 2,
	CH0INT_CIN_LINE_END			= 3,
	CH0INT_CIN_SP_LINE			= 4,
	CH0INT_CIN_ERR_SIZES			= 5,
	CH0INT_CIN_ERR_YUV_FORMAT		= 6,
	CH0INT_CIN_FR_ST_NO_ACTIVE		= 7,
	CH0INT_DMA_IN_ERROR			= 8,
	CH0INT_DMA_IN_FLUSH_DONE		= 9,
	CH0INT_DMA_IN_FR_END			= 10,
	CH0INT_DMA_IN_INFO			= 11,
	CH0INT_OUT_DMA_ERROR			= 12,
	CH0INT_OUT_DMA_FLUSH_DONE		= 13,
	CH0INT_OUT_DMA_FR_END			= 14,
	CH0INT_OUT_DMA_INFO			= 15,
	CH0INT_RWS_TRIGGER			= 16,
	CH0INT_END_FRAME			= 17,
	CH0INT_END_ISP_DMA_OUT			= 18,
	CH0INT_END_ISP_INPUT			= 19,
	CH0INT_FRAME_SIZE_ERROR			= 20,
	CH0INT_ERR_FR_ST_BEF_FR_END		= 21,
	CH0INT_ERR_FR_ST_WHILE_FLUSH		= 22,
	CH0INT_ERR_VRHR_INTERVAL_VIOLATION	= 23,
	CH0INT_ERR_HFHR_INTERVAL_VIOLATION	= 24,
	CH0INT_ERR_PYRAMID_OVERFLOW		= 25
};

enum vra_chain1_interrupt_map {
	CH1INT_IN_CONT_SP_LINE		= 0,
	CH1INT_IN_STOP_IMMED_DONE	= 1,
	CH1INT_IN_END_OF_CONTEXT	= 2,
	CH1INT_IN_START_OF_CONTEXT	= 3,
	CH1INT_END_LOAD_FEATURES	= 4,
	CH1INT_SHADOW_TRIGGER		= 5,
	CH1INT_OUT_OVERFLOW		= 6,
	CH1INT_MAX_NUM_RESULTS		= 7,

	CH1INT_IN_ERROR			= 8,
	CH1INT_IN_FLUSH_DONE		= 9,
	CH1INT_IN_FR_END		= 10,
	CH1INT_IN_INFO			= 11,

	CH1INT_OUT_ERROR		= 12,
	CH1INT_OUT_FLUSH_DONE		= 13,
	CH1INT_OUT_FR_END		= 14,
	CH1INT_OUT_INFO			= 15,
	CH1INT_WATCHDOG			= 16
};

enum ext_chain_id {
	ID_ORBMCH_0 = 0,
	ID_ORBMCH_1 = 1,
};

#define CSIS0_QCH_EN_ADDR		(0x15030004)
#define CSIS1_QCH_EN_ADDR		(0x15040004)
#define CSIS2_QCH_EN_ADDR		(0x15050004)
#define CSIS3_QCH_EN_ADDR		(0x15060004)
#define CSIS4_QCH_EN_ADDR		(0x15070004)

#define CSIS3_1_QCH_EN_ADDR		(0x15070004)

#define ALIGN_UPDOWN_STRIPE_WIDTH(w) \
	(w & STRIPE_WIDTH_ALIGN >> 1 ? ALIGN(w, STRIPE_WIDTH_ALIGN) : ALIGN_DOWN(w, STRIPE_WIDTH_ALIGN));

int exynos9630_is_dump_clk(struct device *dev);

#endif
