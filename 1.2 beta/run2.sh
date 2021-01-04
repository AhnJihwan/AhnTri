cd boot
#assemble boot.s file
as --32 boot.s -o boot.o
mv boot.o ..
cd ..

#compile kernel.c file
gcc -m32 -c os.c -o kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

cd kio

gcc -m32 -c utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

mv utils.o ..
mv char.o ..

cd ..
#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T linker.ld kernel.o utils.o char.o boot.o -o TriOS2.bin -nostdlib

#check MyOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot TriOS2.bin

#building the iso file
mkdir -p iso/boot/grub
cp TriOS2.bin iso/boot/TriOS2.bin
grub-mkrescue -o os.iso iso

#run it in qemu
qemu-system-x86_64 -cdrom os.iso
