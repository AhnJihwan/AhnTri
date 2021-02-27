all: make_deafult

#Makes everything up
make_deafult: bboot kernel keychar ld buildgrub clean

#Makes it via i686-elf-gcc
make_i686: i686-bboot i686-kernel i686-keychar ld buildgrub clean

#Assemble via i686-elf-gcc
i686-bboot: boot/boot.s
	i686-elf-as --32 boot/boot.s -o boot.o

#Build Kernel image via i686-elf-gcc
i686-kernel: init/os_rpc.c
	i686-elf-gcc -c init/os_rpc.c -o image.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#Build kernel main image
kernel: init/os_rpc.c
	gcc -m32 -c init/os_rpc.c -o image.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 

#Build Keychar drivers
keychar: kio/char.c kio/utils.c
	gcc -m32 -c kio/char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 
	gcc -m32 -c kio/utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 

#Build KIO if i686-elf-gcc installed
#One can install via OSDev wiki tutorial
i686-keychar: kio/utils.c kio/char.c
	i686-elf-gcc -c kio/utils.c -o utils.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c kio/char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 

#Link everything up
ld: linker.ld linker.ld image.o char.o boot.o
	ld -m elf_i386 -T linker.ld image.o utils.o char.o boot.o -o ATOS1.bin -nostdlib

#Assemble gru(bboot)loader
bboot: boot/boot.s
	as --32 boot/boot.s -o boot.o

#Build ISO file via grub
buildgrub: ATOS1.bin
	grub-file --is-x86-multiboot ATOS1.bin
	mkdir -p rpc_isodir/boot/grub
	cp ATOS1.bin rpc_isodir/boot/ATOS1.bin
	cp grub.cfg rpc_isodir/boot/grub/grub.cfg
	grub-mkrescue -o atos_rpc.iso rpc_isodir

#Run it in QEMU
qemu: atos_rpc.iso
	qemu-system-i386 -cdrom atos_rpc.iso

#install packages if not via apt
installpkg_apt:
	bash -c "sudo apt install grub2-common gcc gcc-multilib binutils";

#defines elf-i686-gcc if installed
elf_i386_declare:
	export PATH="/opt/cross/bin:$PATH"

#Cleaning up files
clean:
	rm image.o char.o boot.o utils.o