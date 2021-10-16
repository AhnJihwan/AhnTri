#include "bitmap.h"

static unsigned char memori[1024 * 1024];   //Just make my mem 1024x1024
static signed ni = 0;

void free(){
}

void memcpy_old(void *dest, void *src, signed n) 
{ 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
   for (int i=0; i<n; i++) 
       cdest[i] = csrc[i]; 
}

void memcpy(u8int *dest, const u8int *src, u32int len)
{
    const u8int *sp = (const u8int *)src;
    u8int *dp = (u8int *)dest;
    for(; len != 0; len--) *dp++ = *sp++;
}

void *memset(void *str, int a, uint8_t n){
        int i = 0;
        uint8_t *ptr = str;
        while(n>0){
                *ptr = a;
                n--;
                ptr++;
        }
}
