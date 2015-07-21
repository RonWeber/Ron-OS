#include "interrupts.h"

void idt_initialize()
{
    idt_pointer.limit = sizeof(InterruptTableEntry) * 256 - 1;
    idt_pointer.base = (uint32_t)&idt;

    memset(&idt, 0, sizeof(InterruptTableEntry)*256);
    
}


