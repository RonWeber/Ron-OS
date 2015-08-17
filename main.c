#if defined(__linux__)
#error "You should be cross-compiling this."
#endif

#if !defined(__i386__)
#error "64 bit support will come later."
#endif

#include <stddef.h>
#include <stdint.h>

#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "print.h"


void main()
{
    terminal_initialize();

    printk("ROS once again managed to boot, despite all odds.\n");

    printk("Initializing GDT...\n");

    gdt_initialize();

    printk("Preparing interrupt table...\n");

    idt_initialize();

    printk("Running test interrupt 0x3\n");

    asm volatile ("int $0x03");

    printk("Returned from interrupt handler.\n");

    asm volatile ("hlt"); //Wait for an interrupt.
}
