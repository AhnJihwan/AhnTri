ISO_NAME="ATOS_VMPC_"
YDM_NAME=$(date +%Y-%m-%d)
FORMAT_ISO=".iso"
FORMAT_BIN=".bin"
ISO=$ISO_NAME+$YDM_NAME+$FORMAT_ISO
BIN=$ISO_NAME+$YDM_NAME+$FORMAT_BIN

cd boot
#assemble boot.s file
as --32 boot.s -o boot.o
mv boot.o ..
cd ..

#compile kernel.c file
gcc -m32 -c os_vmpc.c -o image.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

cd kio

gcc -m32 -c utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

mv utils.o ..
mv char.o ..

cd ..
#linking the kernel with image.o and boot.o files
ld -m elf_i386 -T linker.ld image.o utils.o char.o boot.o -o TriOS2.bin -nostdlib

#check MyOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot TriOS2.bin

#building the isodir file
mkdir -p isodir/boot/grub
cp TriOS2.bin isodir/boot/TriOS2.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o $ISO isodir

#run it in qemu
qemu-system-i386 -cdrom $ISO
