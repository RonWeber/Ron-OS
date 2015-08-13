#include <limits.h>
#include "print.h"
#include "vga.h"

const vga_color DEFAULT_FOREGROUND = COLOR_LIGHT_BLUE;
const vga_color DEFAULT_BACKGROUND = COLOR_BLACK;
void printk(const char* string)
{
    terminal_print(string, make_color(DEFAULT_FOREGROUND, DEFAULT_BACKGROUND));
}

//TODO: Move this to a different file.  We're not really in VGA at this point
char* int_to_string(char* buffer, int toBeConverted)
{
    //buffer should be at least 12 bytes.
    //My memory protection strategy could use some work.

    if (toBeConverted == INT_MIN)
    {
	//INT_MIN = -INT_MIN.
	//I'm going to have to handle that in some capacity, so I might as well do it obviously.
	buffer = "INT_MIN";
	return buffer;
    }
    
    if (toBeConverted < 0)
    {
	buffer[0] = '-';
	toBeConverted *= -1;
    }
    else
    {
	buffer[0] = '+';
    }

    buffer[11] = '\0'; //Make it a string.
    int bufferIndex = 10;
    while (bufferIndex > 0)//0 is the negative sign.
    {
	buffer[bufferIndex] = (toBeConverted % 10) + '0';
	bufferIndex--;
	toBeConverted /= 10;
    }

    return buffer;
}

void print_int(int toBePrinted)
{
    char buffer[13];
    printk(int_to_string(buffer, toBePrinted));
}
