#if defined(__linux__)
#error "You should be cross-compiling this."
#endif

#if !defined(__i386__)
#error "64 bit support will come later."
#endif

#include <stddef.h>
#include <stdint.h>

#include "vga.h"


void main()
{
    terminal_initialize();

    printk("ROS once again managed to boot, despite all odds.\n");
}
