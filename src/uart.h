#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stddef.h>
#include "object.h"

// void volatileStore8(volatile uint8_t* ptr, uint8_t value);

typedef struct {
    volatile uint8_t* base;
    void (*tx)(uint8_t b);
} Ns16650a;

extern Ns16650a Uart;

void tx(char b);
void printStr(const char* string);

#endif // UART_H_
