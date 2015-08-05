#pragma once
#include <stdint.h>

typedef struct registers
{
    //Pushed by isr_common in idt_asm.asm
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; //Pushed by pusha.
    uint32_t interruptNumber, err_code;
    //Pushed by processor automatically
    uint32_t eip, cs, eflags, useresp, ss;
} Registers;

void interrupt_handler(Registers);
