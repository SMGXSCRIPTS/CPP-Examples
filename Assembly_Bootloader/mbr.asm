[bits 16]
[org 0x7C00]

KERNEL_OFFLOAD_CONTROL equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

call LOAD_KERNEL_TO_MEMORY
call SWITCH_TO_32BIT_SYSTEMS
