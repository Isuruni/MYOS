#include "common.h"

#define STRING_LEN 10

char buffer[STRING_LEN];

s8int *integer_to_string(u32int number) {
  u32int i = 0;
  while (i < STRING_LEN) {
    buffer[i] = '\0';
    i++;
  }

  if (number == 0) {
    buffer[1] = '0';
    return buffer;
  }

  u32int temp_number = number;
  s8int buffer_rev[10] = "";
  i = 0;
  while (temp_number > 0) {
    buffer_rev[i] = '0' + (temp_number % 10);
    temp_number /= 10;
    i++;
  }

  u32int j = 0;
  while (i > 1) {
    buffer[--i] = buffer_rev[j++];
  }

  buffer[--i] = buffer_rev[j];

  return buffer;
}

u32int strlen(const char *str) {
  u32int i;
  for (i = 0; str[i]; i++)
    ;

  return i;
}

void custom_memset(u8int *address, u32int val, u32int size) {
  for (u32int i = 0; i < size; ++i) {
    *address = val;
    ++address;
  }
}// common.c 

#include "common.h"

// Write len copies of val into dest.
void memset(u8int *dest, u8int val, u32int len)
{
    u8int *temp = (u8int *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}
