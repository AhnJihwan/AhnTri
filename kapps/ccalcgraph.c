void graph_putpixel(uint32_t x, uint32_t y, uint32_t c){
	uint32_t graphxx=203+x;
	uint32_t graphyy=203-y;
	if(c==NULL){
		c=0x7fa49d;
	}
	framebuffer_putpixel(graphxx, graphyy, c);
}

void ccalcgraph(){
  framebuffer_clscr(0xffffcc);
  for(int i=3; i<400; i++){
    framebuffer_putpixel(203, i, 0x7fa49d);
    framebuffer_putpixel(i, 203, 0x7fa49d);
  }
  gotoxy(3, 420);
  //TODO: printf~~~~~~~~~~~~
  //TODO: select one of the graphs
  //TODO: draw the graphs
  //TODO: ETC ETC...........
}
