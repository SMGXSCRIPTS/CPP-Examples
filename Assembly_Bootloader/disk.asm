DISK_LOADUP:
  pusha
  push dx

  mov ah, 0x02
  mov al, dh
  mov cl, 0x02
  
  mov ch, 0x00
  mov dh, 0x00

  int 0x13
  jc DISK_ERROR

  pop dx
  cmp al, dh

  jne SECTORS_ERROR
  popa
  ret

DISK_ERROR:
  jmp DISK_LOOP

SECTORS_ERROR:
  jmp DISK_LOOP

DISK_LOOP:
  jmp $
