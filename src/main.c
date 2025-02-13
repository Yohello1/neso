#include <stdint.h>
#include "uart.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

size_t tempFunc()
{
    return sizeof(char);
}

void kmain(void)
{



    Uart.tx(0x68);
    Uart.tx(0x61);
    Uart.tx(0x69);

}
