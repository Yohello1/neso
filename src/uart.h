#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stddef.h>
#include "object.h"

// voi
typedef struct {
    volatile uint8_t* base;
} Ns16650a;

extern Ns16650a Uart;

void tx();
void rx();
void printStr(const char* string);
void cycle();

#endif // UART_H_
