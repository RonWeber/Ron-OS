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

    terminal_print("ROS super early dev version.\nHoly crap, it actually worked!\n", make_color(COLOR_LIGHT_BLUE, COLOR_BLACK));
}
