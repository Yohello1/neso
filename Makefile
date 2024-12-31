.PHONY: hello

arch = rv64imac
as = riscv64-none-elf-as -march=$(arch)
cc = riscv64-none-elf-gcc -mno-fdiv -mabi=lp64 -march=$(arch)

hello:
	echo "Hello World!"

virt.dtc:
	qemu-system-riscv64 -machine virt,dumpdtb=virt.dtc
virt.dts: virt.dtc
	dtc virt.dtc > virt.dts

prog.bin:
	riscv64-none-elf-objcopy -O binary prog.elf prog.bin
%.o: %.c
	$(cc) -c $< -o $@
%.o: %.s
	$(as) -c $< -o $@
