#include "interrupts.h"
#include "print.h"

void interrupt_handler(Registers registers)
{
    printk("Unhandled interrupt: ");
    print_int(registers.interruptNumber);
    printk("\n");
}

void irq_handler(Registers registers)
{
    //Send an end of interrupt signal to the PICs.
    if (registers.interruptNumber >= 40) //This was on the slave PIC.
    {
	//Send reset signal to slave PIC.
	outb(0xA0, 0x20);
    }
    //Send reset signal to master PIC.
    outb(0x20, 0x20);

}

