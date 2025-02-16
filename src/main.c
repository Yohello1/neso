#include <stdint.h>
#include <stddef.h>
#include "uart.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

void fillMemory(size_t size, char* data)
{
    for(size_t i = 0; i < size; i++)
        data[i] = 0;
}

void kmain(void)
{
    printStr("\r\nHello world!\r\n");


    while(1)
    {
        char output[8];
        for(int i = 0; i < 8; i++)
        {
            output[i] = 0x0;
        }
        // cycle();
        //
        tx();
        rx();
        tx();
        rx();        tx();
        rx();        tx();
        rx();        tx();
        rx();        tx();
        rx();        tx();
        rx();        tx();
        rx();        tx();
        rx();        tx();
        rx();
        getStr(output, 128);
        printStr(output);
    }


}
