ENTRY(_start)

SECTIONS
{
    .text 0x80000000 : {
        KEEP(*(.text.boot))
        *(.text*)
    }
    .rodata : {
        . = ALIGN(8);
        *(.rodata*)
        *(.srodata*)
        . = ALIGN(8);
    }
    .data : {
        . = ALIGN(8);
        *(.sdata*)
        *(.data*)
        . = ALIGN(8);
    }
    .bss : {
        . = ALIGN(8);
        _bss_start = .;
        *(.sbss*)
        *(.bss*)
        *(COMMON)
        . = ALIGN(8);
        _bss_end = .;
    }

    .kstack : {
        . = ALIGN(16);
        _stack_start = .;
        . += 4K; /* 4 KB for stack */
        _stack_end = .;
    }

    .heap (NOLOAD) : {
        . = ALIGN(8);
        __heap_start = .;
        . += 64K; /* 64 KB heap size */
        __heap_end = .;
    }

    /DISCARD/ : { *(.comment .note .eh_frame) }
}
