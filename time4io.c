#include <stdint.h>
#include "pic32mx.h"
#include "mipslab.h"

int getsw( void )
{
return (PORTD >>8) & 0xF;
}

int getbtns(void)
{
return (PORTD>>4) & 0b1110 | ((PORTF >> 1) & 0x1);
}