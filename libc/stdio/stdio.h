#include "../../kernel.h"

#define OS_suspend 16

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

uint16 inw(uint16 port)
{
  uint16 data;
  asm volatile("inw %1, %0" : "=a"(data) : "Nd"(port));
  return data;
}

void outb(uint16 port, uint16 data)
{
  asm volatile("outw %0, %1" : : "a"(data), "Nd"(port));
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
  printf("\n");
}

void print_int(int num)
{
  char str_num[digit_count(num)+1];
  itoa(num, str_num);
  printf(str_num);
}

int read_char()
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

  return data;
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

int read_uint()
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

  return atoui(data);
}

void printf_hex(uint32_t n)
{
    int tmp;
    printf("0x");
    char noZeroes = 1;
    int i;
    for (i = 28; i > 0; i -= 4){
        tmp = (n >> i) & 0xF;
        if (tmp == 0 && noZeroes != 0){
            continue;
        }
        if (tmp >= 0xA){
            noZeroes = 0;
            framebuffer_putchar(tmp-0xA+'a' );
        } else{
            noZeroes = 0;
            framebuffer_putchar( tmp+'0' );
        }
    }
    tmp = n & 0xF;
    if (tmp >= 0xA){
        framebuffer_putchar(tmp-0xA+'a');
    } else{
        framebuffer_putchar(tmp+'0');
    }
}

char getchar()
{
  char keycode = 0;
  suspend(OS_suspend);
  keycode = get_input_keycode();
  suspend(OS_suspend);
  return get_ascii_char(keycode);
}
