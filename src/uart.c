#include "uart.h"


void tx(char b) {
    volatileStore8(Uart.base, b);
}

void printElement(char c)
{
    Uart.tx(c);
}

static size_t strlen(const char* str)
{
    size_t len = 0;
    while(str[len])
    {
        len++;
        if(len == SIZE_MAX)
            break;
    }
    return len;
}

void printStr(const char* string)
{
    size_t len = strlen(string);

    for(size_t i = 0; i < len; i++)
    {
        printElement(string[i]);
    }

}

Ns16650a Uart = {
    .base = (volatile uint8_t*) 0x10000000,
    .tx = tx
};
