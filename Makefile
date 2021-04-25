ASM=i686-elf-as
CC=i686-elf-gcc
EMU=qemu-system-i386
CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-ffreestanding -O2 -nostdlib -lgcc
AFLAGS=

boot: src/boot.s
	$(ASM) src/boot.s -o bin/boot.o $(AFLAGS)

kernel: src/kernel.c
	$(CC) -c src/kernel.c -o bin/kernel.o $(CFLAGS)

link: src/linker.ld
	$(CC) -T src/linker.ld -o bin/cos.bin bin/boot.o bin/kernel.o $(LDFLAGS)

grub:
	cp bin/cos.bin isodir/boot/cos.bin
	grub-mkrescue -o cos.iso isodir

run: bin/cos.bin
	$(EMU) -kernel bin/cos.bin

clean:
	rm ./*.iso
	rm ./bin/*.o
	rm ./bin/*.bin
	rm ./isodir/boot/*.bin
