#include <stdint.h>
#include <stddef.h>
#include "uart.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif


void kmain(void)
{



    Uart.tx(0x68);
    Uart.tx(0x61);
    Uart.tx(0x69);

    rx();

    printStr("\r\nHello world!\r\n");
}
