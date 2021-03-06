/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021 Google LLC.
 */
#ifndef __TPUV2_CORE_H__
#define __TPUV2_CORE_H__ 
#include "drivers/gasket/gasket_core.h"
#include "drivers/gasket/gasket_interrupt.h"
#include "drivers/gasket/gasket_logging.h"
#include "drivers/gasket/gasket_page_table.h"
#include "drivers/gasket/gasket_sysfs.h"
#define TPUV2_PCI_VENDOR_ID 0x1AE0
#define TPUV2_PCI_DEVICE_ID 0x0027
#define TPUV2_LBUS_BAR_BYTES 0x1000000
#define TPUV2_TN_BAR_BYTES 0x4000000
#define TPUV2_NUM_TN_RANGES 3
#define TPUV2_NUM_LBUS_RANGES 1
#define TPUV2_NUM_TENSOR_NODES 2
#define TPUV2_NUM_MAPPABLE_BARS 2
extern struct gasket_page_table_config tpuv2_page_table_configs[];
enum tpuv2_bar2_regs {
 TPUV2_BAR2_REG_LTSSM_STATE = 0x1088,
 TPUV2_BAR2_REG_SERDES0_DEBUG_STATUS = 0x10D0,
 TPUV2_BAR2_REG_SERDES1_DEBUG_STATUS = 0x10D8,
 TPUV2_BAR2_REG_SERDES2_DEBUG_STATUS = 0x10E0,
 TPUV2_BAR2_REG_SERDES3_DEBUG_STATUS = 0x10E8,
 TPUV2_BAR2_REG_SERDES4_DEBUG_STATUS = 0x10F0,
 TPUV2_BAR2_REG_SERDES5_DEBUG_STATUS = 0x10F8,
 TPUV2_BAR2_REG_SERDES6_DEBUG_STATUS = 0x1100,
 TPUV2_BAR2_REG_SERDES7_DEBUG_STATUS = 0x1108,
 TPUV2_BAR2_REG_SERDES8_DEBUG_STATUS = 0x1110,
 TPUV2_BAR2_REG_SERDES9_DEBUG_STATUS = 0x1118,
 TPUV2_BAR2_REG_SERDES10_DEBUG_STATUS = 0x1120,
 TPUV2_BAR2_REG_SERDES11_DEBUG_STATUS = 0x1128,
 TPUV2_BAR2_REG_SERDES12_DEBUG_STATUS = 0x1130,
 TPUV2_BAR2_REG_SERDES13_DEBUG_STATUS = 0x1138,
 TPUV2_BAR2_REG_SERDES14_DEBUG_STATUS = 0x1140,
 TPUV2_BAR2_REG_SERDES15_DEBUG_STATUS = 0x1148,
 TPUV2_BAR2_REG_MGT_KERNEL_NM_0_FATAL_ERROR_STATUS = 0x3030,
 TPUV2_BAR2_REG_MGT_KERNEL_NM_0_FIRST_ERROR_STATUS = 0x3040,
 TPUV2_BAR2_REG_MGT_KERNEL_NM_0_FIRST_ERROR_TIMESTAMP = 0x3048,
 TPUV2_BAR2_REG_MGT_KERNEL_NM_1_FATAL_ERROR_STATUS = 0x4030,
 TPUV2_BAR2_REG_MGT_KERNEL_NM_1_FIRST_ERROR_STATUS = 0x4040,
 TPUV2_BAR2_REG_MGT_KERNEL_NM_1_FIRST_ERROR_TIMESTAMP = 0x4048,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_0_FATAL_ERROR_STATUS = 0x5068,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_0_FIRST_ERROR_STATUS = 0x5078,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_0_FIRST_ERROR_TIMESTAMP = 0x5080,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_1_FATAL_ERROR_STATUS = 0x6068,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_1_FIRST_ERROR_STATUS = 0x6078,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_1_FIRST_ERROR_TIMESTAMP = 0x6080,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_2_FATAL_ERROR_STATUS = 0x7068,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_2_FIRST_ERROR_STATUS = 0x7078,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_2_FIRST_ERROR_TIMESTAMP = 0x7080,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_3_FATAL_ERROR_STATUS = 0x8068,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_3_FIRST_ERROR_STATUS = 0x8078,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_3_FIRST_ERROR_TIMESTAMP = 0x8080,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_4_FATAL_ERROR_STATUS = 0x9068,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_4_FIRST_ERROR_STATUS = 0x9078,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_4_FIRST_ERROR_TIMESTAMP = 0x9080,
 TPUV2_BAR2_REG_MGT_KERNEL_DFT_KERNEL_TAP = 0xC000,
 TPUV2_BAR2_REG_MGT_KERNEL_DFT_KERNEL_EFUSE_LSB = 0xC050,
 TPUV2_BAR2_REG_MGT_KERNEL_DFT_KERNEL_EFUSE_MSB = 0xC058,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_0_PLL_DLL_STATUS = 0x5048,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_1_PLL_DLL_STATUS = 0x6048,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_2_PLL_DLL_STATUS = 0x7048,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_3_PLL_DLL_STATUS = 0x8048,
 TPUV2_BAR2_REG_MGT_KERNEL_PLL_4_PLL_DLL_STATUS = 0x9048,
 TPUV2_BAR2_REG_MGT_KERNEL_PCIE_PLL_PLL_DLL_STATUS = 0xA048,
 TPUV2_BAR2_REG_MGT_KERNEL_PCIE_PLL_FATAL_ERROR_STATUS = 0xA060,
 TPUV2_BAR2_REG_MGT_KERNEL_PCIE_PLL_FIRST_ERROR_STATUS = 0xA070,
 TPUV2_BAR2_REG_MGT_KERNEL_PCIE_PLL_FIRST_ERROR_TIMESTAMP = 0xA078,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_0 = 0xD008,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_1 = 0xD010,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_2 = 0xD018,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_3 = 0xD020,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_4 = 0xD028,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_5 = 0xD030,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_6 = 0xD038,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_7 = 0xD040,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_8 = 0xD048,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_9 = 0xD050,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_10 = 0xD058,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_TO_MIRROR_11 = 0xD060,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_0 = 0xD068,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_1 = 0xD070,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_2 = 0xD078,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_3 = 0xD080,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_4 = 0xD088,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_5 = 0xD090,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_6 = 0xD098,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_7 = 0xD0A0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_8 = 0xD0A8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_9 = 0xD0B0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_10 = 0xD0B8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_0_MIRRORED_11 = 0xD0C0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_0 = 0xE008,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_1 = 0xE010,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_2 = 0xE018,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_3 = 0xE020,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_4 = 0xE028,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_5 = 0xE030,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_6 = 0xE038,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_7 = 0xE040,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_8 = 0xE048,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_9 = 0xE050,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_10 = 0xE058,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_TO_MIRROR_11 = 0xE060,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_0 = 0xE068,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_1 = 0xE070,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_2 = 0xE078,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_3 = 0xE080,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_4 = 0xE088,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_5 = 0xE090,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_6 = 0xE098,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_7 = 0xE0A0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_8 = 0xE0A8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_9 = 0xE0B0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_10 = 0xE0B8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_1_MIRRORED_11 = 0xE0C0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_0 = 0xF008,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_1 = 0xF010,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_2 = 0xF018,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_3 = 0xF020,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_4 = 0xF028,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_5 = 0xF030,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_6 = 0xF038,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_7 = 0xF040,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_8 = 0xF048,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_9 = 0xF050,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_10 = 0xF058,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_TO_MIRROR_11 = 0xF060,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_0 = 0xF068,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_1 = 0xF070,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_2 = 0xF078,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_3 = 0xF080,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_4 = 0xF088,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_5 = 0xF090,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_6 = 0xF098,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_7 = 0xF0A0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_8 = 0xF0A8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_9 = 0xF0B0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_10 = 0xF0B8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_2_MIRRORED_11 = 0xF0C0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_0 = 0x10008,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_1 = 0x10010,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_2 = 0x10018,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_3 = 0x10020,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_4 = 0x10028,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_5 = 0x10030,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_6 = 0x10038,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_7 = 0x10040,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_8 = 0x10048,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_9 = 0x10050,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_10 = 0x10058,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_TO_MIRROR_11 = 0x10060,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_0 = 0x10068,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_1 = 0x10070,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_2 = 0x10078,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_3 = 0x10080,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_4 = 0x10088,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_5 = 0x10090,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_6 = 0x10098,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_7 = 0x100A0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_8 = 0x100A8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_9 = 0x100B0,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_10 = 0x100B8,
 TPUV2_BAR2_REG_MGT_KERNEL_LST_3_MIRRORED_11 = 0x100C0,
 TPUV2_BAR2_REG_TN0_PAGE_TABLE_SIZE = 0x0800000,
 TPUV2_BAR2_REG_TN0_EXTENDED_TABLE = 0x0800008,
 TPUV2_BAR2_REG_TN0_HBM_WRITE_QUEUE_INTVECCTL = 0x0800018,
 TPUV2_BAR2_REG_TN0_NF_DESCRIPTOR_QUEUE_INTVECCTL = 0x0800020,
 TPUV2_BAR2_REG_TN0_CHIP_DEBUG_QUEUE_INTVECCTL = 0x0800028,
 TPUV2_BAR2_REG_TN0_TC_INFEED_QUEUE_INTVECCTL = 0x0800030,
 TPUV2_BAR2_REG_TN0_EE_INFEED_QUEUE_INTVECCTL = 0x0800038,
 TPUV2_BAR2_REG_TN0_TC_OUTFEED_QUEUE_INTVECCTL = 0x0800040,
 TPUV2_BAR2_REG_TN0_EE_OUTFEED_QUEUE_INTVECCTL = 0x0800048,
 TPUV2_BAR2_REG_TN0_FSM_MICROCODE_QUEUE_INTVECCTL = 0x0800050,
 TPUV2_BAR2_REG_TN0_NF_OUTFEED_QUEUE_INTVECCTL = 0x0800058,
 TPUV2_BAR2_REG_TN0_TC_HOST_INT_INTVECCTL = 0x0800060,
 TPUV2_BAR2_REG_TN0_TC_HALTED_INTVECCTL = 0x0800068,
 TPUV2_BAR2_REG_TN0_DEBUG_TC_CSR_ACCESS = 0x0800078,
 TPUV2_BAR2_REG_TN0_PAGE_TABLE = 0x0880000,
 TPUV2_BAR2_REG_TN0_DMA_PAUSE = 0x0a00be8,
 TPUV2_BAR2_REG_TN0_DMA_PAUSED = 0x0a00bf0,
 TPUV2_BAR2_REG_TN1_PAGE_TABLE_SIZE = 0x1800000,
 TPUV2_BAR2_REG_TN1_EXTENDED_TABLE = 0x1800008,
 TPUV2_BAR2_REG_TN1_HBM_WRITE_QUEUE_INTVECCTL = 0x1800018,
 TPUV2_BAR2_REG_TN1_NF_DESCRIPTOR_QUEUE_INTVECCTL = 0x1800020,
 TPUV2_BAR2_REG_TN1_CHIP_DEBUG_QUEUE_INTVECCTL = 0x1800028,
 TPUV2_BAR2_REG_TN1_TC_INFEED_QUEUE_INTVECCTL = 0x1800030,
 TPUV2_BAR2_REG_TN1_EE_INFEED_QUEUE_INTVECCTL = 0x1800038,
 TPUV2_BAR2_REG_TN1_TC_OUTFEED_QUEUE_INTVECCTL = 0x1800040,
 TPUV2_BAR2_REG_TN1_EE_OUTFEED_QUEUE_INTVECCTL = 0x1800048,
 TPUV2_BAR2_REG_TN1_FSM_MICROCODE_QUEUE_INTVECCTL = 0x1800050,
 TPUV2_BAR2_REG_TN1_NF_OUTFEED_QUEUE_INTVECCTL = 0x1800058,
 TPUV2_BAR2_REG_TN1_TC_HOST_INT_INTVECCTL = 0x1800060,
 TPUV2_BAR2_REG_TN1_TC_HALTED_INTVECCTL = 0x1800068,
 TPUV2_BAR2_REG_TN1_DEBUG_TC_CSR_ACCESS = 0x1800078,
 TPUV2_BAR2_REG_TN1_PAGE_TABLE = 0x1880000,
 TPUV2_BAR2_REG_TN1_DMA_PAUSE = 0x1a00be8,
 TPUV2_BAR2_REG_TN1_DMA_PAUSED = 0x1a00bf0,
 TPUV2_BAR2_REG_MGT_ERROR_INTVECCTL = 0x2008,
 TPUV2_BAR2_REG_MGT_CHIP_INIT_DONE = 0x470200,
 TPUV2_BAR2_REG_MGT_CHIP_RESET_REGISTER = 0xb000,
 TPUV2_BAR2_REG_MGT_GLOBAL_FATAL_ERROR_STATUS = 0x400028,
 TPUV2_BAR2_REG_MGT_LINK_INTERRUPT_VECTOR = 0x0b008,
 TPUV2_BAR2_REG_MGT_KERNEL_IS_DEVICE_OWNED_REGISTER = 0x0b018,
};
int tpuv2_add_dev_cb(struct gasket_dev *gasket_dev);
int tpuv2_remove_dev_cb(struct gasket_dev *gasket_dev);
int tpuv2_sysfs_setup_cb(struct gasket_dev *gasket_dev);
int tpuv2_device_cleanup(struct gasket_filp_data *filp_data, struct file *file);
int tpuv2_device_open_cb(struct gasket_filp_data *filp_data, struct file *file);
int tpuv2_reset(struct gasket_dev *gasket_dev, uint type);
enum gasket_status tpuv2_get_status(struct gasket_dev *gasket_dev);
int tpuv2_get_mappable_regions_cb(
 struct gasket_filp_data *filp_data, int bar_index,
 struct gasket_mappable_region **mappable_regions,
 int *num_mappable_regions);
long tpuv2_ioctl(struct file *file, uint cmd, ulong arg);
extern const struct gasket_mappable_region
 tn_mappable_regions[];
extern const struct gasket_mappable_region
 lbus_mappable_regions[];
#endif
