	[global load_idt]

load_idt:
	mov eax, [esp + 4]
	lidt [eax]
	ret

%macro ISR_NO_ERRCODE 1
	[global isr%1]
isr%1:
	cli
	push byte 0		;An error code is pushed here by the processor in ISR_ERRCODE.  We make one up so the stack looks the same.
	push byte %1
	jmp isr_common
%endmacro
	
%macro ISR_ERRCODE 1
	[global isr%1]
isr%1:
	cli
	push byte %1
	jmp isr_common
%endmacro

	ISR_NO_ERRCODE 0
	ISR_NO_ERRCODE 1
	ISR_NO_ERRCODE 2
	ISR_NO_ERRCODE 3
	ISR_NO_ERRCODE 4
	ISR_NO_ERRCODE 5
	ISR_NO_ERRCODE 6
	ISR_NO_ERRCODE 7
	ISR_ERRCODE 8
	ISR_NO_ERRCODE 9
	ISR_ERRCODE 10
	ISR_ERRCODE 11
	ISR_ERRCODE 12
	ISR_ERRCODE 13
	ISR_ERRCODE 14
	ISR_NO_ERRCODE 15
	ISR_NO_ERRCODE 16
	ISR_NO_ERRCODE 17
	ISR_NO_ERRCODE 18
	ISR_NO_ERRCODE 19
	ISR_NO_ERRCODE 20
	ISR_NO_ERRCODE 21
	ISR_NO_ERRCODE 22
	ISR_NO_ERRCODE 23
	ISR_NO_ERRCODE 24
	ISR_NO_ERRCODE 25
	ISR_NO_ERRCODE 26
	ISR_NO_ERRCODE 27
	ISR_NO_ERRCODE 28
	ISR_NO_ERRCODE 29
	ISR_NO_ERRCODE 30
	ISR_NO_ERRCODE 31

	[extern interrupt_handler] //In interrupts.c
isr_common:
	
	pusha 			;Pushed edi, esi, ebp, esp, ebx, edx, ecx,eax
	call interrupt_handler
	
	popa
	add esp,8		;Cleans up the 2 bytes pushed in the ISR macros above.
	sti

	iret
	
%macro IRQ 2
	;;%1 is the number from 0-15, %2 is from 32-47.
	;;%2 will be %1 + 32
	[global irq%1]
irq%1:
	cli
	push byte 0
	push byte %2
	jmp irq_common_stub
%endmacro
	
irq_common_stub:	
