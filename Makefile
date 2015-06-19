
SOURCES=start.o main.o

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
CC = i686-elf-gcc
LDFLAGS=-Tlink.ld
ASFLAGS=-felf32

all: $(SOURCES) link 

clean:
	-rm *.o ros.bin

link:
	i686-elf-gcc $(LDFLAGS) -o ros.bin -ffreestanding -O2 -nostdlib $(SOURCES) -lgcc

start.o: start.asm
	nasm $(ASFLAGS) $<

main.o: main.c
	$(CC) -c $< -o $@ $(CFLAGS)
