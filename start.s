	.section ".text.boot"

	.globl _start

_start:
	la sp, __stack_start
	call mymain
_hlt:
	j _hlt
