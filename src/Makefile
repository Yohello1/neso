##
# Neso Os
#
# @file
# @version 0.1

CC=riscv64-none-elf-gcc
CFLAGS=-march=rv64imac -mabi=lp64 -Oz -ffreestanding -nostdlib -mcmodel=medany

AS=riscv64-none-elf-as
ASMFLAGS=-march=rv64imac

LDER=riscv64-none-elf-ld

OBJCOPIER=riscv64-none-elf-objcopy
OBJDUMPER=riscv64-none-elf-objdump

all: neso.bin

SRC=$(wildcard **.c)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASMFLAGS) $< -c -o $@

neso.elf: start.o $(SRC:.c=.o)
	$(LDER) -Tlink.ld $^ -o $@

%.bin: %.elf
	$(OBJCOPIER) $< -O binary $@

%.list: %.elf
	$(OBJDUMPER) -D $< > $@


run: neso.bin
	qemu-system-riscv64 -bios none -machine virt -kernel neso.bin

# DTS Stuff
qemudtsData:
	qemu-system-riscv64 -machine virt,dumpdtb=virt.dtb
	dtc virt.dtb > virt.dts
