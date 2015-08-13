#pragma once
#include <stdint.h>

struct interrupt_table_entry_struct
{
    uint16_t offset_low;//Lower 16 bits of address to jump to when this fires
    uint16_t selector; //Kernel segment selector
    uint8_t zero; //Always zero.
    uint8_t flags; //More flags.
    uint16_t offset_high; //Upper 16 bits of address to jump to.
} __attribute__((packed));
typedef struct interrupt_table_entry_struct InterruptTableEntry;

//This is what "lidt" wants.
struct interrupt_pointer_struct
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));
typedef struct interrupt_pointer_struct InterruptPointer;

#define NUM_IDT_ENTRIES 256
InterruptTableEntry idt[NUM_IDT_ENTRIES];
InterruptPointer idt_pointer;

extern void load_idt(uint32_t); //In idt_asm.asm

void idt_initialize();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
