/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021 Google LLC.
 */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/tpuv2_ioctl.h>

#include "drivers/gasket/gasket_core.h"
#include "tpu_common.h"
#include "tpuv2_core.h"
#define TPUV2_DRIVER_VERSION "1.3.0"
#define TPUV2_PCI_SUBSYSTEM_DEVICE_ID 0x004E
static int __init tpuv2_init(void);
static void tpuv2_exit(void);
static const struct pci_device_id tpuv2_pci_ids[] = {
    {PCI_DEVICE_SUB(TPUV2_PCI_VENDOR_ID, TPUV2_PCI_DEVICE_ID, PCI_ANY_ID,
                    TPUV2_PCI_SUBSYSTEM_DEVICE_ID)},
    {0}};
struct legacy_gasket_interrupt_desc tpuv2_interrupts[] = {
    {TPUV2_INTERRUPT_TN0_HBM_WRITE_QUEUE,
     TPUV2_BAR2_REG_TN0_HBM_WRITE_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_NF_DESCRIPTOR_QUEUE,
     TPUV2_BAR2_REG_TN0_NF_DESCRIPTOR_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_CHIP_DEBUG_QUEUE,
     TPUV2_BAR2_REG_TN0_CHIP_DEBUG_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_TC_INFEED_QUEUE,
     TPUV2_BAR2_REG_TN0_TC_INFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_EE_INFEED_QUEUE,
     TPUV2_BAR2_REG_TN0_EE_INFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_TC_OUTFEED_QUEUE,
     TPUV2_BAR2_REG_TN0_TC_OUTFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_EE_OUTFEED_QUEUE,
     TPUV2_BAR2_REG_TN0_EE_OUTFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_EE_FSM_MICROCODE_QUEUE,
     TPUV2_BAR2_REG_TN0_FSM_MICROCODE_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_NF_OUTFEED_QUEUE,
     TPUV2_BAR2_REG_TN0_NF_OUTFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN0_TC_HOST_0, TPUV2_BAR2_REG_TN0_TC_HOST_INT_INTVECCTL,
     PACK_0},
    {TPUV2_INTERRUPT_TN0_TC_HOST_1, TPUV2_BAR2_REG_TN0_TC_HOST_INT_INTVECCTL,
     PACK_1},
    {TPUV2_INTERRUPT_TN0_TC_HOST_2, TPUV2_BAR2_REG_TN0_TC_HOST_INT_INTVECCTL,
     PACK_2},
    {TPUV2_INTERRUPT_TN0_TC_HOST_3, TPUV2_BAR2_REG_TN0_TC_HOST_INT_INTVECCTL,
     PACK_3},
    {TPUV2_INTERRUPT_TN0_TC_HALTED, TPUV2_BAR2_REG_TN0_TC_HALTED_INTVECCTL,
     UNPACKED},
    {TPUV2_INTERRUPT_TN1_HBM_WRITE_QUEUE,
     TPUV2_BAR2_REG_TN1_HBM_WRITE_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_NF_DESCRIPTOR_QUEUE,
     TPUV2_BAR2_REG_TN1_NF_DESCRIPTOR_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_CHIP_DEBUG_QUEUE,
     TPUV2_BAR2_REG_TN1_CHIP_DEBUG_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_TC_INFEED_QUEUE,
     TPUV2_BAR2_REG_TN1_TC_INFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_EE_INFEED_QUEUE,
     TPUV2_BAR2_REG_TN1_EE_INFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_TC_OUTFEED_QUEUE,
     TPUV2_BAR2_REG_TN1_TC_OUTFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_EE_OUTFEED_QUEUE,
     TPUV2_BAR2_REG_TN1_EE_OUTFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_EE_FSM_MICROCODE_QUEUE,
     TPUV2_BAR2_REG_TN1_FSM_MICROCODE_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_NF_OUTFEED_QUEUE,
     TPUV2_BAR2_REG_TN1_NF_OUTFEED_QUEUE_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_TN1_TC_HOST_0, TPUV2_BAR2_REG_TN1_TC_HOST_INT_INTVECCTL,
     PACK_0},
    {TPUV2_INTERRUPT_TN1_TC_HOST_1, TPUV2_BAR2_REG_TN1_TC_HOST_INT_INTVECCTL,
     PACK_1},
    {TPUV2_INTERRUPT_TN1_TC_HOST_2, TPUV2_BAR2_REG_TN1_TC_HOST_INT_INTVECCTL,
     PACK_2},
    {TPUV2_INTERRUPT_TN1_TC_HOST_3, TPUV2_BAR2_REG_TN1_TC_HOST_INT_INTVECCTL,
     PACK_3},
    {TPUV2_INTERRUPT_TN1_TC_HALTED, TPUV2_BAR2_REG_TN1_TC_HALTED_INTVECCTL,
     UNPACKED},
    {TPUV2_INTERRUPT_ERROR, TPUV2_BAR2_REG_MGT_ERROR_INTVECCTL, UNPACKED},
    {TPUV2_INTERRUPT_LINK, TPUV2_BAR2_REG_MGT_LINK_INTERRUPT_VECTOR, UNPACKED}};
static struct gasket_driver_desc tpuv2_desc = {
    .chip_version = "1.0.0",
    .driver_version = TPUV2_DRIVER_VERSION,
    .num_page_tables = TPUV2_NUM_TENSOR_NODES,
    .page_table_configs = tpuv2_page_table_configs,
    .bar_descriptions = {{TPUV2_LBUS_BAR_BYTES, VM_READ, TPUV2_LBUS_BAR_OFFSET,
                          TPUV2_NUM_LBUS_RANGES, lbus_mappable_regions},
                         GASKET_UNUSED_BAR,
                         {TPUV2_TN_BAR_BYTES, (VM_WRITE | VM_READ),
                          TPUV2_TN_BAR_OFFSET, TPUV2_NUM_TN_RANGES,
                          tn_mappable_regions},
                         GASKET_UNUSED_BAR,
                         GASKET_UNUSED_BAR,
                         GASKET_UNUSED_BAR},
    .legacy_interrupt_bar_index = TPUV2_TN_BAR_INDEX,
    .num_interrupts = TPUV2_INTERRUPT_COUNT,
    .legacy_interrupts = tpuv2_interrupts,
    .legacy_interrupt_pack_width = 7,
    .add_dev_cb = tpuv2_add_dev_cb,
    .remove_dev_cb = tpuv2_remove_dev_cb,
    .enable_dev_cb = NULL,
    .disable_dev_cb = NULL,
    .sysfs_setup_cb = tpuv2_sysfs_setup_cb,
    .sysfs_cleanup_cb = NULL,
    .device_open_cb = tpuv2_device_open_cb,
    .device_release_cb = NULL,
    .device_close_cb = tpuv2_device_cleanup,
    .get_mappable_regions_cb = tpuv2_get_mappable_regions_cb,
    .ioctl_handler_cb = tpuv2_ioctl,
    .device_status_cb = tpuv2_get_status,
    .hardware_revision_cb = NULL,
    .device_reset_cb = tpuv2_reset,
};
static struct gasket_device_desc device_desc = {
    .name = TPU_COMMON_ACCEL_TYPE,
    .legacy_support = 1,
    .legacy_major = 120,
    .legacy_minor = 0,
    .module = THIS_MODULE,
    .pci_id_table = tpuv2_pci_ids,
    .driver_desc = &tpuv2_desc,
};
MODULE_DESCRIPTION("Google tpu_v2 driver");
MODULE_VERSION(TPUV2_DRIVER_VERSION);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Googler <noreply@google.com>");
MODULE_DEVICE_TABLE(pci, tpuv2_pci_ids);
module_init(tpuv2_init);
module_exit(tpuv2_exit);
int __init tpuv2_init(void) { return gasket_register_device(&device_desc); }
void tpuv2_exit(void) { gasket_unregister_device(&device_desc); }
