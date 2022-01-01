#include "acpi.h"

void parse_rsdp(rsdp_v1_t* rsdp){
	char sign[8] = rsdp->sign;
	uint8_t csum = rsdp->csum;
	char oemid[6] = rsdp->oemid;
	uint8_t revision = rsdp->revision;
	uint32_t rsdtaddr = rsdp->rsdtaddr;
	numofrsdtbles = (head.len-sizeof(acpi_header_t))/4;
}

void parse_rsdt(uint8_t* ){
	
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
	uint8_t* start = (uint8_t*)0x000E0000;
	uint8_t* end = (uint8_t*)0x000FFFFF;
	while(start<end){
		if(*(uint32_t*)start == 0x5253442050545220){
			parse_rsdt(
