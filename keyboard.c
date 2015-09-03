#include "keyboard.h"
#include "io.h"
#include "print.h"

//This sends information to the PS2 controller, not devices.
#define DATA_PORT 0x60
#define STATUS_REGISTER 0x64 //Read only
#define COMMAND_REGISTER 0x64 //Write only

#define OUTPUT_BUFFER_STATUS 0x01
void wait_for_output();

void keyboard_initialize()
{
  //Todo: Actually go through the initialization process.  The BIOS will usually have this configured before booting, but not always.

  //Pump the controller output if it exists.
  if(inb(STATUS_REGISTER) & OUTPUT_BUFFER_STATUS)
    {
      inb(DATA_PORT); 
    }
  
  outb(COMMAND_REGISTER, 0xAD); //Disable first PS/2 port.
  outb(COMMAND_REGISTER, 0xA7); //Disable second PS/2 port
  outb(COMMAND_REGISTER, 0x20);

  printk("Controller configuration is\n"); 

  wait_for_output();

  print_int(inb(DATA_PORT));
}



inline void wait_for_output()
{
  while((inb(STATUS_REGISTER) & OUTPUT_BUFFER_STATUS) == 0 ) {};
}

