#include "uart.h"

void tx(volatile uint8_t* base, uint8_t b) {
    volatileStore8(base, b);
}

Ns16650a Uart = {
    .base = (volatile uint8_t*) 0x10000000,
    .tx = tx
};
