#include <stdint.h>
#include <stddef.h>

extern unsigned int _bss_start;
extern unsigned int _bss_end;

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

/**
 *Context Switching Code is below */

struct thread_control_block
{
    void* x2; // program stack top
    void* x2_kernel; // kernel stack top
    void* satp; // I can find a total of... lim → 0 documentation on this
    thread_control_block* next;
    uint8_t state;

    /*
    ** May at some point include;
    ** Priority, Scheduling policy of task, Process ID
    */
};

void initialize_multitasking();

/**
 *Context Switching code has ended :( */

void kmain(void);

void cstart()
{
    unsigned int* bss = &_bss_start;
    unsigned int* bss_end = &_bss_end;

    while (bss < bss_end)
    {
        *bss++ = 0;
    }

    kmain();

}

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


    while(1)
    {
        char output[8];
        for(int i = 0; i < 8; i++)
        {
            output[i] = 0x0;
        }
    }


}
