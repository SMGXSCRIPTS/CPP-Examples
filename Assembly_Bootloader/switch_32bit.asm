[bits 16]
SWITCH_TO_32BIT_SYSTEMS:
  cli
  lgdt [GDT_DESCRIPTOR]
  mov eax, cr0
  or eax, 0x1
  mov cr0, eax
  jmp CODE_SEG:32BIT_INIT

[bits 32]
32BIT_INIT:
  mov ax, DATA_SEG
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  mov ebp, 0x90000
  mov esp, ebp

  call BEGIN_32BIT_SYSTEMS
