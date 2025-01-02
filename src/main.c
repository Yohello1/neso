#include <stdint.h>
#include "uart.h"

void kmain(void)
{
    Ns16650a Uart = {
        .base = (volatile uint8_t*) 0x10000000,
        .tx = tx
    };


    Uart.tx(Uart.base, 0x55);

}
