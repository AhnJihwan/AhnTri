#ifndef _STRING_H
#define _STRING_H

int strcmp(char str1[], char str2[]) {
    int i;
    for (i = 0; str1[i] == str2[i]; i++) {
        if (str1[i] == '\0') return 0;
    }
    return str1[i] - str2[i];
}

int strrlen(const char* str)
{
  int length = 0;
  while(str[length])
    length++;
  return length;
}

void strcpy(char dest[], const char source[]) {
    int i = 0;
    while (1)
    {
        dest[i] = source[i];

        if (dest[i] == '\0')
        {
            break;
        }

        i++;
    }
}

int strlen(const char* str)
{
  int length = 0;
  while(str[length])
    length++;
  return length;
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

#endif
