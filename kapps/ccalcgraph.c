void ccalcgraph(){
  framebuffer_clscr(0xffffcc);
  gotoxy(X, Y); //This is gonna be the middle

  for(i=1; i<max; i++){ //max is going to be the maximum
    framebuffer_putpixel(X, i);
    framebuffer_putpixel(i, Y));
  }
  
}
