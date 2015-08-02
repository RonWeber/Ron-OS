#include "interrupts.h"
#include "print.h"

void interrupt_handler(Registers registers)
{
    printk("Unhandled interrupt.");
    print_int(registers.interruptNumber);
}
