##
# Neso-Os
#
# @file
# @version 0.1

# IDIR =../include
CC=riscv64-none-elf-gcc
CFLAGS=-march=rv64imac -mabi=lp64 -Oz -ffreestanding -nostdlib -mcmodel=medlow

AS=riscv64-none-elf-as
ASMFLAGS=-march=rv64imac

LDER=riscv64-none-elf-ld

OBJCOPIER=riscv64-none-elf-objcopy
OBJDUMPER=riscv64-none-elf-objdump


SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: prog.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASMFLAGS) $< -c -o $@

prog.elf: start.o $(OBJ)
	$(LDER) -Tlink.ld $^ -o $@

%.bin: %.elf
	$(OBJCOPIER) $< -O binary $@

%.list: %.elf
	$(OBJDUMPER) -D $< > $@

run: prog.bin
	qemu-system-riscv64 -bios none -machine virt -kernel prog.bin

clean:
	rm -f *.bin *.list *.o *.elf
