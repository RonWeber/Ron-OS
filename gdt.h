#pragma once
#include <stdint.h>
#include <stdbool.h>


//Everything related to setting the global descriptor tables.

//This format is defined somewhere.  It's kind of a mess.
struct gdt_entry
{
    uint16_t limit_low; //Low 16 bits of the limit.
    uint16_t base_low; //Low 16 bits of the base.
    uint8_t base_middle; //Next 8 bits of the base.
    uint8_t access; //Access flags, determine where this can be used.
    uint8_t granularity;
    uint8_t base_high;  //High bits of the base.
} __attribute__((packed));

gdt_entry format_gdt_entry(uint32_t limit,  uint32_t base,
			 uint8_t segment_type, bool descriptor_type,
			 uint8_t privilege_level, bool present,
			 bool granularity_is_kb, bool operand_is_32_bit);
