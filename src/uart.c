#include "uart.h"

// The idea behind the ring buffer
// and input is;
// You run the functionn called
// `getInput` to wait for input, and
// when you do get input, it gets
// put into the ring buffer.
// Then run the command `rx` to
// fetch the next thing in the
// ring buffer.
// The command `tx` puts some
// data into the ring buffer
// then the command `putOutput`
// writes it to the uart port
// in sync with the other thing
// Then we have a function called
// 'Cycle'. That function will
// run the tx, and rx functions
// and ig ingest info

// Then printStr takes a pointer
// to a character array.
//

static struct ringBuffer
{
    uint8_t lastWritten;
    uint8_t lastRead;
    char buffer[512];
}inputBuf, outputBuf;

Ns16650a Uart = {
    .base = (volatile uint8_t*) 0x10000000,
};

static void writeRingBuffer(struct ringBuffer* buff, char b)
{
    buff->lastWritten += 1;
    buff->lastWritten %= 512;
    buff->buffer[buff->lastWritten] = b;
}

static char readRingBuffer(struct ringBuffer* buff)
{
    buff->lastRead += 1;
    buff->lastRead %= 512;
    char temp = buff->buffer[buff->lastRead];
    buff->buffer[buff->lastRead] = 0x0;

    return temp;
}

void tx()
{
    volatileStore8(Uart.base, readRingBuffer(&outputBuf));
    volatileStore8(Uart.base, 0x0);
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

void rx()
{
    char temp = 0x0;
    while( temp == 0x0)
    {
        temp = volatileLoad8(Uart.base);

    }
    writeRingBuffer(&inputBuf, temp);
    volatileStore8(Uart.base, 0x0);
}

// 512 char max size
void printStr(const char* string)
{
    size_t len = strlen(string);

    for(size_t i = 0; i < len; i++)
    {
        writeRingBuffer(&outputBuf, string[i]);
    }

}

void cycle()
{
    rx();
    tx();

}
