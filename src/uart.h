#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stddef.h>
#include "object.h"

// voi
typedef struct {
    volatile uint8_t* base;
    void (*tx)(uint8_t b);
} Ns16650a;

extern Ns16650a Uart;

static char* ringBuffer[8];

void tx(char b);
char rx();
void printStr(const char* string);

#endif // UART_H_
