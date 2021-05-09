static unsigned char memori[1024 * 1024];   //Just make my mem 1024x1024
static signed ni = 0;
 
void *malloc(signed siz){
    void *mem;                              //Void mem
    if(sizeof memori - ni < siz)
        return NULL;
 
    mem = &memori[ni];
    ni += siz;
    return mem;
}

u32int kmalloc(u32int sz, int align, u32int *phys)
{
  if (align == 1 && (placement_address & 0xFFFFF000)) // If the address is not already page-aligned
  {
    // Align it.
    placement_address &= 0xFFFFF000;
    placement_address += 0x1000;
  }
  if (phys)
  {
    *phys = placement_address;
  }
  u32int tmp = placement_address;
  placement_address += sz;
  return tmp;
}

void free(void *mem){
}

void memcpy(void *dest, void *src, signed n) 
{ 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
   for (int i=0; i<n; i++) 
       cdest[i] = csrc[i]; 
} 
