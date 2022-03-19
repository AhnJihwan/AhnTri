unsigned int xor32(){
  static unsigned int l = 2200UL;
  l ^= l << 17;
  l ^= l >> 12;
  return l ^= l << 19;
}
