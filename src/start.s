.section ".text.boot"

.global
_start:
    la sp, _stack_start
    call dstart
_hlt:
    j _hlt
