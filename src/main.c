#include <stdint.h>
#include <stddef.h>
#include "uart.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif


void kmain(void)
{
    printStr("\r\nHello world!\r\n");

    while(1)
    {
        cycle();
    }


}
