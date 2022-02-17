//Codename Pari(means 'fly' in Korean)

#include "acpi.h"

uint32_t *rsdt_addr;
uint32_t *fadt_addr;

void parse_rsdp(uint8_t* addr){
	rsdp_v1_t* rsdp = (rsdp_v1_t*) addr;
	printf("\nSignature: ");
	printf(rsdp->sign);
	uint8_t csum = rsdp->csum;
	printf("\nOEMID: ");
	printf(rsdp->oemid);
	uint8_t revision = rsdp->revision;
	uint32_t rsdtaddr = rsdp->rsdtaddr;
	rsdt_addr = rsdp->rsdtaddr;
	printf("\nRSDT Address: ");
	printf_hex(rsdtaddr);
}

void parse_rsdt(uint8_t* rsdpaddr){					//Address of RSDP
	rsdp_v1_t* rsdp = (rsdp_v1_t*) rsdpaddr;
	uint32_t* addr = rsdp->rsdtaddr;
	rsdt_t* rsdt = (rsdt_t*) addr;
	acpi_header_t head = rsdt->head;
	printf("\nSigniture: ");
	printf(head.sign);
	uint32_t len = head.len;
	uint8_t revision = head.revision;
	uint8_t csum = head.csum;
	printf("\nOEMID: ");
	printf(head.oemid);
	printf("\nOEM Table ID: ");
	printf(head.oemtbleid);
	uint32_t oemrevision = head.oemrevision;
	uint32_t creatorid = head.creatorid;
	uint32_t creatorrevision = head.creatorrevision;
	int numofrsdtbles = (head.len-sizeof(acpi_header_t))/4;
}

void parse_xsdt(uint8_t* rsdpaddr){					//Address of RSDP
	rsdp_v1_t* rsdp = (rsdp_v1_t*) rsdpaddr;
	uint32_t* addr = rsdp->rsdtaddr;
	xsdt_t* xsdt = (xsdt_t*) addr;
	acpi_header_t head = xsdt->head;
	printf("\nSigniture: ");
	printf(head.sign);
	uint32_t len = head.len;
	uint8_t revision = head.revision;
	uint8_t csum = head.csum;
	printf("\nOEMID: ");
	printf(head.oemid);
	printf("\nOEM Table ID: ");
	printf(head.oemtbleid);
	uint32_t oemrevision = head.oemrevision;
	uint32_t creatorid = head.creatorid;
	uint32_t creatorrevision = head.creatorrevision;
	int numofxsdtbles = (head.len-sizeof(acpi_header_t))/4;
}

uint32_t *find_facp(uint32_t * rsdt_addr){
	rsdt_t* rsdt = (rsdt_t*) rsdt_addr;
	int entries = (rsdt->head.len - sizeof(rsdt->head)) / 4;
	print_int(entries);
	for(int i = 0; i < entries; i++){
		acpi_header_t* ssdt = (acpi_header_t*) rsdt->entry[i];
		if(strncmp(ssdt->sign, "FACP", 4)==0){
			printf("FACP found\n");
			parse_facp(ssdt);
		}
	}
	return NULL;
}

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
uint32_t SLP_EN;
uint32_t SCI_EN;

void parse_facp(acpi_header_t* addr){
	facp_t* facp = (facp_t*) addr;
	acpi_header_t head = facp->head;
	printf("\nSigniture: ");
	printf(head.sign);
	uint32_t len = head.len;
	uint8_t revision = head.revision;
	uint8_t csum = head.csum;
	printf("\nOEMID: ");
	printf(head.oemid);
	printf("\nOEM Table ID: ");
	printf(head.oemtbleid);
	uint32_t oemrevision = head.oemrevision;
	uint32_t creatorid = head.creatorid;
	uint32_t creatorrevision = head.creatorrevision;
	acpi_header_t* dsdt = (acpi_header_t*) (uintptr_t) facp->dsdt;
	PM1a_CNT_BLK = facp->PM1a_CNT_BLK;
	//...
	parse_dsdt(dsdt);
}

void parse_dsdt(acpi_header_t* head){
	printf("\nSigniture: ");
	printf(head->sign);
	uint32_t len = head->len;
	uint8_t revision = head->revision;
	uint8_t csum = head->csum;
	printf("\nOEMID: ");
	printf(head->oemid);
	printf("\nOEM Table ID: ");
	printf(head->oemtbleid);
	uint32_t oemrevision = head->oemrevision;
	uint32_t creatorid = head->creatorid;
	uint32_t creatorrevision = head->creatorrevision;
}

/*
int enable_acpi(){
	if((inw((unsigned int) PM1a_CNT) &SCI_EN) == 0){
		
*/

uint8_t checksum(const char* addr, uint8_t size){
	const char* end = addr + size;
	uint8_t sum = 0;
	while (addr < end) {
		sum += *addr;
		addr++;
	}
	return sum;
}


void searchforrsdp(){
	uint8_t* addr = (uint8_t*)0x000E0000;
	uint8_t* end = (uint8_t*)0x000FFFFF;
	printf("\nPari ACPI Manager says: ");
	while(addr<end){
		if(*(uint64_t*)addr == 0x2052545020445352 && checksum(addr, sizeof(rsdp_v1_t)) == 0){
			parse_rsdp(addr);
			parse_rsdt(addr);
			find_facp(rsdt_addr);
		}
		addr += 16;
	}
}

uint8_t parse_table_header(uint8_t* addr, uint64_t* value, char charrr[]){
	uint8_t encvalue = *addr++;
	if(encvalue==0x0){
		*value = 0;		//Zero Op
		return 1;
	} else if(encvalue==0x1){
		*value = 1;		//One Op
		return 1;
	} else if(encvalue==0x6){
		*value = 6;		//Alias Op
		return 1;
	} else if(encvalue==0x8){
		*value = 8;		//Name Op
		return 1;
	} else if(encvalue==0xA){
		*value = addr[0];	//Bytedata
		return 2;
	} else if(encvalue==0xB){
		*value = addr[0] | ((uint16_t)addr[1] << 8);	//Wordddata
		return 3;
	} else if(encvalue==0xC){
		*value = addr[0] | ((uint32_t)addr[1] << 8) | ((uint32_t)addr[2] << 16) | ((uint32_t)addr[3] << 24);	//Dworddata
		return 5;
	} else if(encvalue==0xC){
		*value = addr[0] | ((uint64_t)addr[1] << 8) | ((uint64_t)addr[2] << 16) | ((uint64_t)addr[3] << 24) | ((uint64_t)addr[4] << 32) | ((uint64_t)addr[5] << 40) | ((uint64_t)addr[6] << 48) | ((uint64_t)addr[7] << 56);	//Qworddata
		return 9;
	}
}
