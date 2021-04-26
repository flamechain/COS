UNAME := $(shell uname)

CC=i686-elf-gcc
AS=i686-elf-as
LD=i686-elf-ld
EMU=qemu-system-i386

GFLAGS=
CCFLAGS=-m32 -std=c11 -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CCFLAGS+=-Wno-pointer-arith -Wno-unused-parameter
CCFLAGS+=-nostdlib -nostdinc -ffreestanding -fno-pie -fno-stack-protector
CCFLAGS+=-fno-builtin-function -fno-builtin
ASFLAGS=
LDFLAGS=
EFLAGS=

BOOTSECT_SRCS=\
	src/kernel/stage0.S

BOOTSECT_OBJS=$(BOOTSECT_SRCS:.S=.o)

KERNEL_C_SRCS=$(wildcard src/kernel/*.c)
KERNEL_C_SRCS+=$(wildcard src/*.c)
KERNEL_S_SRCS=$(filter-out $(BOOTSECT_SRCS), $(wildcard src/kernel/*.S))
KERNEL_OBJS=$(KERNEL_C_SRCS:.c=.o) $(KERNEL_S_SRCS:.S=.o)

BOOTSECT=bootsect.bin
KERNEL=kernel.bin
ISO=boot.iso

all: dirs bootsect kernel

%.o: %.c
	$(CC) -o $@ -c $< $(GFLAGS) $(CCFLAGS)

%.o: %.S
	$(AS) -o $@ -c $< $(GFLAGS) $(ASFLAGS)

dirs:
	mkdir -p bin

bootsect: $(BOOTSECT_OBJS)
	$(LD) -o ./bin/$(BOOTSECT) $^ -Ttext 0x7C00 --oformat=binary

kernel: $(KERNEL_OBJS)
	$(LD) -o ./bin/$(KERNEL) $^ $(LDFLAGS) -Tsrc/linker.ld

iso: dirs bootsect kernel
	dd if=/dev/zero of=boot.iso bs=512 count=2880
	dd if=./bin/$(BOOTSECT) of=boot.iso conv=notrunc bs=512 seek=0 count=1
	dd if=./bin/$(KERNEL) of=boot.iso conv=notrunc bs=512 seek=1 count=2048

run: boot.iso
	$(EMU) $^ $(EFLAGS)

clean:
	rm -f ./**/**/*.o
	rm -f ./**/*.o
	rm -f ./**/*.bin
	rm -f ./*.iso
