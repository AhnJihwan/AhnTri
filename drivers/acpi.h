struct rsdp_v1 {
  char sign[8];
  uint8_t csum;
  char oemid[6];
  uint8_t revision;
  uint32_t rsdtaddr;
} __attribute__ ((packed)) rsdp_v1_t;

struct rsdp_v2 {
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
} acpi_header_t;

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

