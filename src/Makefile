##
# Neso-Os
#
# @file
# @version 0.1

# IDIR =../include
CC=riscv64-none-elf-gcc
CFLAGS=-O2 -mabi=lp64 -march=rv64imac

ODIR=obj
LDIR=../lib
TMPFILES=tmp

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


all:
	mkdir $(ODIR)
	mkdir $(TMPFILES)
	mkdir bin

virt.dts:
	qemu-system-riscv64 -machine virt,dumpdtb=$(TMPFILES)virt.dtb
	dtc $(TMPFILES)/virt.dtb > $(TMPFILES)/virt.dts

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o bin/ $(TMPFILES)/

# end
