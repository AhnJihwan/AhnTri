typedef struct rsdp {
  uint8_t sign;
  uint8_t csum;
  uint8_t oemid;
  uint8_t revision;
  uint8_t rsdtaddr;
  uint8_t len;
  uint8_t xsdtaddr;
  uint8_t xcsum;
  uint8_t reserved;
} rsdp_t;

typedef struct rsdt {
  uint8_t sign;
  uint8_t len;
  uint8_t revision;
  uint8_t csum;
  uint8_t oemid;
  uint8_t oemtbleid;
  uint8_t oemrevision;
  uint8_t creatorid;
  uint8_t creatorrevision;
  uint32_t entry;
} rsdt_t;

typedef struct xsdt {
  uint8_t sign;
  uint8_t len;
  uint8_t revision;
  uint8_t csum;
  uint8_t oemid;
  uint8_t oemtbleid;
  uint8_t oemrevision;
  uint8_t creatorid;
  uint8_t creatorrevision;
  uint64_t entry;
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

