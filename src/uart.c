#include "uart.h"

void tx(volatile uint8_t* base, uint8_t b) {
    volatileStore8(base, b);
}
