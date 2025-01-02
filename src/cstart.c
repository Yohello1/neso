#define uint unsigned int

extern unsigned int _bss_start;
extern unsigned int _bss_end;

void kmain(void);

void cstart()
{
    uint* bss = &_bss_start;
    uint* bss_end = &_bss_end;

    while (bss < bss_end)
    {
        *bss++ = 0;
    }

    kmain();

}
