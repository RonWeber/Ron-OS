#include "vga.h"
#include <stdint.h>
#include <stddef.h>
#include "string.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

uint8_t make_color(vga_color fg, vga_color bg) {
	return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

size_t terminal_row, terminal_col;
uint16_t* terminal_buffer;

void terminal_initialize() {
	terminal_row = 0;
	terminal_col = 0;
	uint8_t color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000; //I like the zen of memory address casts.  Why is this at 0xB8000?  Because it is.
	for (size_t row = 0; row < VGA_HEIGHT; row++)
	{
	    for(size_t col = 0; col < VGA_WIDTH; col++)
	    {
		const size_t index = row * VGA_WIDTH + col;
		terminal_buffer[index] = make_vgaentry(' ', color);
	    }
	}
      
}

void terminal_changeEntryTo(char c, uint8_t color, size_t x, size_t y)
{
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c, uint8_t color)
{
    if (c == '\n') //Newlines have to be supported at some point.
    {
	terminal_col = 0;
	if (++terminal_row == VGA_HEIGHT)
	{
	    terminal_row = 0;
	}
    }
    else
    {
	terminal_changeEntryTo(c, color, terminal_col, terminal_row);
	if (++terminal_col == VGA_WIDTH)
	{
	    terminal_col = 0;
	    if (++terminal_row == VGA_HEIGHT)
	    {
		terminal_row = 0;
	    }
	}
    }
}

void terminal_print(const char* data, uint8_t color)
{
    size_t datalen = strlen(data);
    for (size_t i = 0; i < datalen; i++)
	terminal_putchar(data[i], color);
}

