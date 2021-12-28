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

