#include "uart.h"

void tx(char b) {
    volatileStore8(Uart.base, b);
}

Ns16650a Uart = {
    .base = (volatile uint8_t*) 0x10000000,
    .tx = tx
};
