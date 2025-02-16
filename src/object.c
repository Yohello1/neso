// why did I make this file?
#ifndef OBJECT_C_DEF
#define OBJECT_C_DEF

#include "object.h"


uint8_t volatileLoad8(volatile uint8_t* ptr) {
    return *ptr;
}

uint16_t volatileLoad16(volatile uint16_t* ptr) {
    return *ptr;
}

uint32_t volatileLoad32(volatile uint32_t* ptr) {
    return *ptr;
}

uint64_t volatileLoad64(volatile uint64_t* ptr) {
    return *ptr;
}

void volatileStore8(volatile uint8_t* ptr, uint8_t value) {
    *ptr = value;
}

void volatileStore16(volatile uint16_t* ptr, uint16_t value) {
    *ptr = value;
}

void volatileStore32(volatile uint32_t* ptr, uint32_t value) {
    *ptr = value;
}

void volatileStore64(volatile uint64_t* ptr, uint64_t value) {
    *ptr = value;
}

#endif
