GDT_START:
  dq 0x0

GDT_CODE:
  dw 0xffff
  dw 0x0
  db 0x0
  db 10011010b
  db 11001111b
  db 0x0

GDT_DATA:
  dw 0xffff
  dw 0x0
  db 0x0
  db 10011010b
  db 11001111b
  db 0x0

GDT_END:

GDT_DESCRIPTOR:
  dw GDT_END - GDT_START - 1
  dd GDT_START

CODE_SEG equ GDT_CODE - GDT_START
DATA_SEG equ GDT_DATA - GDT_START
