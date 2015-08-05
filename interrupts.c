#include "interrupts.h"
#include "print.h"

int total_interrupts = 0;

extern void shut_down_everything();

void interrupt_handler(Registers registers)
{
    printk("Unhandled interrupt: ");
    print_int(registers.interruptNumber);
    printk("\n");
}
