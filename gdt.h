#pragma once
#include <stdint.h>

//Everything related to setting the global descriptor tables.

struct gdt_pointer_struct //This is the pointer to the GDT.
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));
typedef struct gdt_pointer_struct GdtPointer;

#define NUM_GDT_ENTRIES 5

uint64_t gdt[NUM_GDT_ENTRIES];
GdtPointer gdt_ptr;

void gdt_initialize();
