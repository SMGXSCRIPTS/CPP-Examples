global _start;
[bits 32]

_start:
  [extern KERNEL_MAIN]
  call KERNEL_MAIN
  jmp $
