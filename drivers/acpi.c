#include "acpi.h"

void parse_rsdp(uint8_t* addr){
	rsdp_v1_t* rsdp = (rsdp_v1_t*) addr;
	char sign[8] = rsdp->sign;
	printf("Signature: ");
	printf(sign);
	uint8_t csum = rsdp->csum;
	char oemid[6] = rsdp->oemid;
	printf("\nOEMID: ");
	printf(oemid);
	uint8_t revision = rsdp->revision;
	uint32_t rsdtaddr = rsdp->rsdtaddr;
	printf_hex(rsdtaddr);
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
	numofrsdtbles = (head.len-sizeof(acpi_header_t))/4;
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

void searchforrsdp(){
	uint8_t* addr = (uint8_t*)0x000E0000;
	uint8_t* end = (uint8_t*)0x000FFFFF;
	// TODO: checksum
	while(addr<end){
		if(*(uint64_t*)start == 0x2052545020445352){
			parse_rsdt(addr);
		}
	}
}
