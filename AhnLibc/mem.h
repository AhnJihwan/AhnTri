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

void free(void *mem){
}

void memcpy(void *dest, void *src, signed n) 
{ 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
   for (int i=0; i<n; i++) 
       cdest[i] = csrc[i]; 
} 
