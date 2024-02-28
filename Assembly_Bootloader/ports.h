#progma once

#include <stdint.h>

unsigned char PORT_BYTE_IN(uint16_t PORT)
{
  unsigned char RESULT;
  asm("in %%dx, %%al" : "=a" (RESULT) : "d" (PORT));
}

void PORT_BYTE_OUT(uint16_t PORT, uint8_t DATA)
{
  asm("out %%al, %%dx" : : "a" (DATA), "d" (PORT));
}
