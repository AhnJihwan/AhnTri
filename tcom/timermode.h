void timer(){
  int uptime = 0;
  while(1){
    suspend(5);
    uptime = uptime + 1;
    print_int(uptime);
    printf("/");
  }
}

