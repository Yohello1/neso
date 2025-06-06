#include <stdint.h>
#include <stddef.h>
#include <stdint.h>

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
 * Memory Mangement Code starts here! */

extern char __heap_start;
extern char __heap_end;

static char* heap_ptr = &__heap_start;
static char* heap_limit = &__heap_end;

void* malloc(size_t size) {
    if (heap_ptr + size > heap_limit) {
        return NULL;
    }
    void* mem = heap_ptr;
    heap_ptr += size;
    return mem;
}

void free(void* ptr)
{
  // Freeing your memory is for weaklings
}
/**
 * Memory Mangement code ends here */

/**
 *Context Switching Code is below */


enum ProcessState
{
    Uninitialised,
    Ready,
    Running,
    Dead,
    Stopping,
    Stopped
};

struct context
{
  int64_t ra;
  int64_t sp;

  // callee-saved
  int64_t s0;
  int64_t s1;
  int64_t s2;
  int64_t s3;
  int64_t s4;
  int64_t s5;
  int64_t s6;
  int64_t s7;
  int64_t s8;
  int64_t s9;
  int64_t s10;
  int64_t s11;
};

struct Program
{
    struct context ctx;
    uint64_t *stack;
    enum ProcessState state;
};


// This will come in useful later
struct cpu
{
    struct Program *proc;
    struct context context;
};

extern void switch_to_task(struct context* old, struct context* new);

#define STACK_SIZE 1024
void init_task_stack(struct Program* task, void*(func)())
{
    task->stack = (uint64_t*)malloc(STACK_SIZE); // Alloc stack space

    uint64_t* stack_top = task->stack + STACK_SIZE / sizeof(uint64_t);

    // setup the stack to call `func`
    stack_top--; // stack pointer to top
    *stack_top = (uint64_t)func; // Set return address to func
    task->ctx.sp = (uint64_t)stack_top; // sets stack pointer
}

#define MAX_TASKS 10

struct Program Programs[MAX_TASKS];
int current_task = 0;

// Round-Robin schedluer: Run the next task lol
void schedule()
{
  // This is bugged...
  switch_to_task(&Programs[current_task].ctx, &Programs[(current_task) % MAX_TASKS].ctx);
}

// When a timer is called, move to next task
void timer_interrupt_handler()
{
    schedule();
}
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
