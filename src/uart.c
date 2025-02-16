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
    char buffer[128];
}inputBuf, outputBuf;

Ns16650a Uart = {
    .base = (volatile uint8_t*) 0x10000000,
};

static void writeRingBuffer(struct ringBuffer* buff, char b)
{
    uint8_t nextPos = (buff->lastWritten + 1) % 128;
    if (nextPos != buff->lastRead)
    {
        buff->buffer[buff->lastWritten] = b;
        buff->lastWritten = nextPos;
    }
}

static char readRingBuffer(struct ringBuffer* buff)
{
    if (buff->lastRead == buff->lastWritten)
        return 0;

    buff->lastRead = (buff->lastRead + 1) % 128;
    return buff->buffer[buff->lastRead];
}

void tx()
{
    char temp = readRingBuffer(&outputBuf);
    if (temp != 0)
    {
        volatileStore8(Uart.base, temp);
    }
}
void rx()
{
    char temp = volatileLoad8(Uart.base);
    if(temp != 0x0)
        writeRingBuffer(&inputBuf, temp);
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

// 512 char max size
void printStr(const char* string)
{
    size_t len = strlen(string);

    for(size_t i = 0; i < len; i++)
    {
        writeRingBuffer(&outputBuf, string[i]);
    }
}

void getStr(char* string, size_t maxLen)
{
    size_t i = 0;
    while(i < (maxLen - 1))
    {
        char temp = readRingBuffer(&inputBuf);
        if(temp == 0 || temp == '\n')
            break;

        string[i++] = temp;
    }

    string[i] = '\0';

}

void cycle()
{
    rx();
    tx();
}
