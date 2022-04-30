unsigned int xor32(){
  static unsigned int l = 77666051UL;
  l ^= l << 17;
  l ^= l >> 12;
  return l ^= l << 19;
}

unsigned int xor32_2(){
  static unsigned int l = 37242598UL;
  l ^= l << 55;
  l ^= l >> 23;
  l ^= l >> 68;
  l ^= l << 81;
  return l ^= l << 16;
}

unsigned int xor32_2times(){
  int i = xor32();
  int ii = i % 10;
  int iii;
  while(ii < 0){
    iii = xor32_2();
    ii--;
  }
  return iii;
}
