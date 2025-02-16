#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdint.h>
#include "uart.h"

// Load & Store files

uint8_t volatileLoad8(volatile uint8_t* ptr);
uint16_t volatileLoad16(volatile uint16_t* ptr);
uint32_t volatileLoad32(volatile uint32_t* ptr);
uint64_t volatileLoad64(volatile uint64_t* ptr);

void volatileStore8(volatile uint8_t* ptr, uint8_t value);
void volatileStore16(volatile uint16_t* ptr, uint16_t value);
void volatileStore32(volatile uint32_t* ptr, uint32_t value);
void volatileStore64(volatile uint64_t* ptr, uint64_t value);


#endif // OBJECT_H_
