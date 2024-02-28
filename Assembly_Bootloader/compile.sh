nasm kernel-entry.asm -f elf -o kernel-entry.o
nasm mbr.asm -f bin -o mbr.bin
gcc -m32 -ffreestanding -c dummy-kernel.c -o kernel.o
ld -m elf_i386 -o kernel.bin -Ttext 0x1000 kernel-entry.o kernel.o --oformat binary
cat mbr.bin kernel.bin > boot-os.bin
rm -rf kernel.o kernel-entry.o kernel.bin mbr.bin
