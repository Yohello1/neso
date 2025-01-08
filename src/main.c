#include <stdint.h>
#include "uart.h"

void kmain(void)
{



    Uart.tx(Uart.base, 0x68);
    Uart.tx(Uart.base, 0x61);
    Uart.tx(Uart.base, 0x69);

}
