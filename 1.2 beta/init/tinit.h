#define OS_suspend 4

uint32 vga_index;
uint16 cursor_pos = 0, cursor_next_line_index = 1;
static uint32 next_line_index = 1;
uint8 g_fg_color = GREEN, g_bg_color = BLACK;

uint16 vga_entry(unsigned char ch, uint8 fg_color, uint8 bg_color) 
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = bg_color;
  ah <<= 4;
  ah |= fg_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void clear_vga_buffer(uint16 **buffer, uint8 fg_color, uint8 bg_color)
{
	uint32 i;
	for(i = 0; i < BUFSIZE; i++){
		(*buffer)[i] = vga_entry(NULL, fg_color, bg_color);
	}
	next_line_index = 1;
	vga_index = 0;
}

void clear_screen()
{
  clear_vga_buffer(&vga_buffer, g_fg_color, g_bg_color);
  cursor_pos = 0;
  cursor_next_line_index = 1;
}

void init_vga(uint8 fg_color, uint8 bg_color)
{
  vga_buffer = (uint16*)VGA_ADDRESS;
  clear_vga_buffer(&vga_buffer, fg_color, bg_color);
  g_fg_color = fg_color;
  g_bg_color = bg_color;
}

uint8 inb(uint16 port)
{
  uint8 data;
  asm volatile("inb %1, %0" : "=a"(data) : "Nd"(port));
  return data;
}

void outb(uint16 port, uint8 data)
{
  asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
}

void movcur(uint16 pos)
{
  outb(0x3D4, 14);
  outb(0x3D5, ((pos >> 8) & 0x00FF));
  outb(0x3D4, 15);
  outb(0x3D5, pos & 0x00FF);
}

void movcur_next_line()
{
  cursor_pos = 80 * cursor_next_line_index;
  cursor_next_line_index++;
  movcur(cursor_pos);
}

void gotoxy(uint16 x, uint16 y)
{
  vga_index = 80*y;
  vga_index += x;
  if(y > 0){
    cursor_pos = 80 * cursor_next_line_index * y;
    cursor_next_line_index++;
    movcur(cursor_pos);
  }
}

char get_input_keycode()
{
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

void wait_for_io(uint32 timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}

void suspend(uint32 timer_count)
{
  wait_for_io(timer_count*0x02FFFFFF);
}

void print_new_line()
{
  if(next_line_index >= 55){
    next_line_index = 0;
    clear_vga_buffer(&vga_buffer, g_fg_color, g_bg_color);
  }
  vga_index = 80*next_line_index;
  next_line_index++;
  movcur_next_line();
}

void print_char(char ch)
{
  vga_buffer[vga_index] = vga_entry(ch, g_fg_color, g_bg_color);
  vga_index++;
  movcur(++cursor_pos);
}

void print_char_notepad(char ch)
{
  vga_buffer[vga_index] = vga_entry(ch, g_fg_color, g_bg_color);
  vga_index++;
}

void os_print_string(char *str)
{
  uint32 index = 0;
  while(str[index]){
    if(str[index] == '\n'){
      print_new_line();
      index++;
    }else{
      print_char(str[index]);
      index++;
    }
  }
}

void os_print_color(char *str, uint8 fore_color, uint8 back_color)
{
  uint32 index = 0;
  uint8 fc, bc;
  fc = g_fg_color;
  bc = g_bg_color;
  g_fg_color = fore_color;
  g_bg_color = back_color;
  while(str[index]){
    if(str[index] == '\n'){
      print_new_line();
      index++;
    }else{
      print_char(str[index]);
      index++;
    }
  }
  g_fg_color = fc;
  g_bg_color = bc;
}

void print_int(int num)
{
  char str_num[digit_count(num)+1];
  itoa(num, str_num);
  os_print_string(str_num);
}

int read_int()
{
  char ch = 0;
  char keycode = 0;
  char data[32];
  int index = 0;
  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      data[index] = '\0';
      print_new_line();
      break;
    }else{
      ch = get_ascii_char(keycode);
      print_char(ch);
      data[index] = ch;
      index++;
    }
    suspend(OS_suspend);
  }while(ch > 0);

  return atoi(data);
}

char getchar()
{
  char keycode = 0;
  suspend(OS_suspend);
  keycode = get_input_keycode();
  suspend(OS_suspend);
  return get_ascii_char(keycode);
}
