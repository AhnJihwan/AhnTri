#include "../libc/atclib.h"

typedef struct rsdp_v1 {
  char sign[8];
  uint8_t csum;
  char oemid[6];
  uint8_t revision;
  uint32_t rsdtaddr;
} __attribute__ ((packed)) rsdp_v1_t;

typedef struct rsdp_v2 {
  char sign[8];
  uint8_t csum;
  char oemid[6];
  uint8_t revision;
  uint32_t rsdtaddr;
  uint32_t len;
  uint64_t xsdtaddr;
  uint8_t xcsum;
  uint8_t reserved;
} __attribute__ ((packed)) rsdp_v2_t;

typedef struct acpi_header {
  char sign[4];
  uint32_t len;
  uint8_t revision;
  uint8_t csum;
  char oemid[6];
  char oemtbleid[8];
  uint32_t oemrevision;
  uint32_t creatorid;
  uint32_t creatorrevision;
} __attribute__ ((packed)) acpi_header_t;

typedef struct rsdt {
  acpi_header_t head;
  uint32_t entry[];
} rsdt_t;

typedef struct xsdt {
  acpi_header_t head;
  uint64_t entry[];
} xsdt_t;

typedef struct gas {
  uint8_t addr_spid;  //Address space ID
                      /*0x00 System Memory space
                        0x01 System I/O space
                        0x02 PCI Configuration space
                        0x03 Embedded Controller
                        0x04 SMBus
                        0x05 SystemCMOS
                        0x06 PciBarTarget
                        0x07 IPMI
                        0x08 General PurposeIO
                        0x09 GenericSerialBus
                        0x0A Platform Communications Channel (PCC)
                        0x0B to 0x7E Reserved
                        0x7F Functional Fixed Hardware
                        0x80 to 0xBF Reserved
                        0xC0 to 0xFF OEM Defined
                        */
  uint8_t regbw;
  uint8_t regbo;
  uint8_t accesssize;
  uint8_t addr;
} gas_t;


//Working on FACP

typedef struct addr_type_t {
  uint8_t addr_space;
  uint8_t bit_widtht;
  uint8_t bit_offset;
  uint8_t access_size;
  uint64_t addr;
} addr_type_t;

typedef struct facp {
  acpi_header_t head;
  uint32_t firmware_ctrl;
  uint32_t dsdt;
  uint8_t reserved;
  uint8_t pref_pm_prof;
  uint16_t sci_int;
  uint32_t smi_cmd;
  uint8_t acpi_enable;
  uint8_t acpi_disable;
  uint8_t pstate_cnt;
  uint32_t PM1a_EVT_BLK;
  uint32_t PM1b_EVT_BLK;
  uint32_t PM1a_CNT_BLK;
  uint32_t PM1b_CNT_BLK;
  uint32_t PM2_CNT_BLK;
  uint32_t PM_TMR_BLK;
  uint32_t GPE0_BLK;
  uint32_t GPE1_BLK;
  uint8_t PM1_EVT_len;
  uint8_t PM1_CNT_len;
  uint8_t PM2_CNT_LEN;
  uint8_t PM_TMR_LEN;
  uint8_t GPE0_BLK_LEN;
  uint8_t GPE1_BLK_LEN;
  uint8_t GPE1_BASE;
  uint8_t CST_CNT;
  uint16_t P_LVL2_LAT;
  uint16_t P_LVL3_LAT;
  uint16_t FLUSH_SIZE;
  uint16_t FLUSH_STRIDE;
  uint8_t duty_offset;
  uint8_t duty_width;
  uint8_t day_alrn;
  uint8_t mon_alrm;
  uint8_t century;
  uint16_t iapc_boot_arch;
  uint8_t reservedi;
  uint32_t flags;
  addr_type_t reset_reg;
  uint8_t reset_value;
  uint16_t arm_boot_arch;
  uint8_t fadt_minor_version;
  uint64_t x_firmware_ctrl;
  uint64_t x_dsdt;
  addr_type_t X_PM1a_EVT_BLK;
  addr_type_t X_PM1b_EVT_BLK;
  addr_type_t X_PM1a_CNT_BLK;
  addr_type_t X_PM1b_CNT_BLK;
  addr_type_t X_PM2_CNT_BLK;
  addr_type_t X_PM_TMR_BLK;
  addr_type_t X_GPE0_BLK;
  addr_type_t X_GPE1_BLK;
  addr_type_t SLEEP_CONTROL_REG;
  addr_type_t SLEEP_STATUS_REG;
  uint64_t hv_vendor_identity;
  //More going to be added
} facp_t;

typedef struct madt_item {
  uint8_t entry_type;
  uint8_t record_len;
} __attribute__((packed)) madt_item_t;

typedef struct madt_ent_tzero {                   // Processor Local ACPI
  uint8_t acpi_processor_id;
  uint8_t apic_id;
  uint32_t flags;
} __attribute__((packed)) madt_ent_tzero_t;

typedef struct madt_ent_ti {                      // IO APIC
  uint8_t ioapicid;
  uint8_t reserved;
  uint32_t ioapicaddr;
  uint32_t gsib;
} __attribute__((packed)) madt_ent_ti_t;
