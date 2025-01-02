.section ".text.boot"

.global _start
_start:
    la sp, _stack_start
    call cstart
_hlt:
    j _hlt
