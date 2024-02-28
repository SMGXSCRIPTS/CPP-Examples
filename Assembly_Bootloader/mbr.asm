[bits 16]
[org 0x7C00]

KERNEL_OFFLOAD_CONTROL equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

call LOAD_KERNEL_TO_MEMORY
call SWITCH_TO_32BIT_SYSTEMS

jmp $

%include "switch_32bit.asm"
%include "disk.asm"
%include "gdt.asm"

[bits 16]
LOAD_KERNEL_TO_MEMORY:
  mov bx, KERNEL_OFFLOAD_CONTROL
  mov dh, 2
  mov dl, [BOOT_DRIVE]
  call DISK_LOADUP
  ret

[bits 32]
BEGIN_32BIT_SYSTEMS:
  call KERNEL_OFFLOAD_CONTROL
  jmp $

BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xAA55
