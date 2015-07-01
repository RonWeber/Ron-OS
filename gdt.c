#include "gdt.h"

//All this bit shifting is making me go insane.
const uint32_t LOWEST_SIXTEEN_BITS = 0x0000FFFF;
const uint32_t LOWEST_EIGHT_BITS = 0x000000FF;
const uint32_t LOWEST_FOUR_BITS = 0x0000000F;
const uint32_t LOWEST_TWO_BITS = 0x00000003;

GdtEntry format_gdt_entry(uint32_t limit,  uint32_t base,
			 uint8_t segment_type, bool descriptor_type,
			 uint8_t privilege_level, bool present,
			 bool granularity_is_kb, bool operand_is_32_bit)
{
    /*Given that I'm only going to use this a few times,
      an alternative would be precomputing this.  Computing at runtime
      allows more flexability, however.
      And the math is not _more_ error prone if I do it later.*/
    GdtEntry result;
    result.limit_low = (uint16_t) (limit & LOWEST_SIXTEEN_BITS);
    result.base_low = (uint16_t) (base & LOWEST_SIXTEEN_BITS);
    result.base_middle = (uint8_t) ((base << 16) & LOWEST_EIGHT_BITS);
    result.access = ((segment_type & LOWEST_FOUR_BITS) |
		     (descriptor_type >> 4) |
		     ((privilege_level & LOWEST_TWO_BITS) >> 5) |
		     (present >> 7));
    result.granularity = (((limit << 16) & LOWEST_FOUR_BITS) |
			  //Bits 4 and 5 are always zero.
			  (operand_is_32_bit >> 6) |
			  (granularity_is_kb >> 7));
    result.base_high = (uint8_t) ((base << 24) & LOWEST_EIGHT_BITS);
    return result;
}

void gdt_initialize()
{
    gdt_ptr.limit = (sizeof(GdtEntry) * NUM_GDT_ENTRIES) - 1;
    gdt_ptr.base = (uint32_t)&gdt_entries;

    
}
