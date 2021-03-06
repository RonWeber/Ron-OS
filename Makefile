
SOURCES=start.o main.o vga.o gdt.o gdt_asm.o idt.o idt_asm.o string.o print.o interrupts.o io.o keyboard.o

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -m32 -Wa,--32
CC = i686-elf-gcc
LDFLAGS=-Tlink.ld
ASFLAGS=-felf32

all: ros.bin

clean:
	-rm *.o ros.bin

ros.bin: $(SOURCES) link.ld
	i686-elf-gcc $(LDFLAGS) -o ros.bin -ffreestanding -O2 -nostdlib $(SOURCES) -lgcc

%.o: %.asm
	nasm $(ASFLAGS) $<

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
