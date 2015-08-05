	;; This is designed to boot from a multiboot (ie. GRUB) bootloader

	MBOOT_MAGIC equ 0x1BADB002     ;Convince GRUB we're a member of its fan club or something.
	
	MBOOT_PAGE_ALIGN_FLAG equ 1<<0 ;Ask GRUB to page-align boot modules
	MBOOT_GET_MEM_INFO_FLAG equ 1<<1 ;Ask GRUB to get a memory information table
	MBOOT_REQUEST_VIDEO_MODE_FLAG equ 1<<2 ;Request a video mode.  Not used for now.
	MBOOT_FLAGS equ MBOOT_PAGE_ALIGN_FLAG | MBOOT_GET_MEM_INFO_FLAG 
	
	MBOOT_CHECKSUM equ -(MBOOT_MAGIC + MBOOT_FLAGS)

	GLOBAL mboot096	;So we can get at the header in C.

mboot096:
	section .multiboot
	align 4
	dd MBOOT_MAGIC 		;GRUB will look through the file for this.
	dd MBOOT_FLAGS
	dd MBOOT_CHECKSUM

	;; We don't have a real stack yet.  Let's make a fake one.

	section .bootstrap_stack, nobits
	align 4
stack_bottom:
	resb 16348
stack_top:	

	section .text
	global start
start:
	EXTERN main
	;; Linker script specifies "start" as important.

	call main		;Call main()

	;; After cli, the hlt will stop everything.
	global shut_down_everything
shut_down_everything:
	cli
	hlt
	jmp $ 			;If main() exits, we don't want to be executing random memory.
