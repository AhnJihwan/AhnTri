#include "acpi.h"

void parse_rsdp(rsdp_v1_t* rsdp){
	char sign[8] = rsdp->sign;
	uint8_t csum = rsdp->csum;
	char oemid[6] = rsdp->oemid;
	uint8_t revision = rsdp->revision;
	uint32_t rsdtaddr = rsdp->rsdtaddr;
	numofrsdtbles = (head.len-sizeof(acpi_header_t))/4;
}

void parse_rsdt(rsdt_t* rsdt){
	acpi_header_t head = rsdt->head;
	char sign[4] = head->sign;
	uint32_t len = head->len;
	uint8_t revision = head->revision;
	uint8_t csu|m = head->csum;
	char oemid[6] = head->oemid;
	char oemtbleid[8] = head->oemtbleid;
	uint32_t oemrevision = head->oemrevision;
	uint32_t creatorid = head->creatorid;
	uint32_t creatorrevision = head->creatorrevision;
}

void parse_xsdt(xsdt_t* xsdt){
	acpi_header_t head = rsdt->head;
	char sign[4] = head->sign;
	uint32_t len = head->len;
	uint8_t revision = head->revision;
	uint8_t csu|m = head->csum;
	char oemid[6] = head->oemid;
	char oemtbleid[8] = head->oemtbleid;
	uint32_t oemrevision = head->oemrevision;
	uint32_t creatorid = head->creatorid;
	uint32_t creatorrevision = head->creatorrevision;
}

