#include "utils.h"

uint32 strlen(const char* str)
{
  uint32 length = 0;
  while(str[length])
    length++;
  return length;
}

long stoi(const char *s)
{
    long i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

uint32 digit_count(int num)
{
  uint32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}

void itoa(int num, char *number)
{
  int dgcount = digit_count(num);
  int index = dgcount - 1;
  char x;
  if(num == 0 && dgcount == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[dgcount] = '\0';
  }
}

int atoi(char* s)
{
  int len = strlen(s);
  int i = len - 1;
  int num = 0, pos = 1;
  while(i >= 0){
    num += (s[i] - '0') * pos;
    pos *= 10;
    i--;
  }
  return num;
}

int atoui(char* s)
{
  int len = strlen(s);
  int i = len - 1;
  uint16 num = 0, pos = 1;
  while(i >= 0){
    num += (s[i] - '0') * pos;
    pos *= 10;
    i--;
  }
  return num;
}
