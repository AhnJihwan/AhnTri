unsigned int xor32(){
  static unsigned int l = 7766UL;
  l ^= l << 17;
  l ^= l >> 12;
  return l ^= l << 19;
}

unsigned int xor32_2times(){
  return xor32(xor32());
}
