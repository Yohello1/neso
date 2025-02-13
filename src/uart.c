#include "uart.h"
#include "stdint.h"


void tx(char b) {
    volatileStore8(Uart.base, b);
}

void printElement(char c)
{
    Uart.tx(c);
}

static int8_t strlen(const char* str)
{
    int8_t len = 0;
    while(str[len])
        len++;
    return len;
}

Ns16650a Uart = {
    .base = (volatile uint8_t*) 0x10000000,
    .tx = tx
};
