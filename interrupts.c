#include "interrupts.h"
#include "string.h"
#include <stdint.h>

void idt_initialize()
{
    idt_pointer.limit = sizeof(InterruptTableEntry) * 256 - 1;
    idt_pointer.base = (uint32_t)&idt;

    memset(&idt, 0, sizeof(InterruptTableEntry)*256);
    
}


void idt_set_gate(uint8_t entryNumber, uint32_t offset, uint16_t selector, uint8_t flags)
{
    idt[num].offset_low = offset & 0xFFFF;
    idt[num].offset_high = (offset >> 16) & 0xFFFF;

    idt[num].selector = selector;
    idt[num].zero = 0;

    idt[num].flags = flags;
    //In user mode, this would be
    //idt[num].flags = flags | 0x60
}
