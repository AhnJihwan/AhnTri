all: make_deafult

#Makes everything up
make_deafult: bboot kernel keychar gdt idt ld buildgrub clean

#Makes VMPC up
vmpc: bboot kernel_vmpc keychar gdt idt ld_vm buildgrub_vmpc clean_vmpc

#Makes it via i686-elf-gcc
make_i686: i686-bboot i686-kernel i686-keychar i686-gdt ld buildgrub clean

#Assemble via i686-elf-gcc
i686-bboot: boot/boot.s
	i686-elf-as --32 boot/boot.s -o boot.o

#Build Kernel image via i686-elf-gcc
i686-kernel: init/os_rpc.c
	i686-elf-gcc -c init/os_rpc.c -o image.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#Build GDT
gdt: init/gdt.c init/load_gdt.s
	gcc -m32 -c init/gdt.c -o gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	as --32 init/load_gdt.s -o load_gdt.o

i686-gdt: init/gdt.c init/load_gdt.s
	i686-elf-gcc -c init/gdt.c -o gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	as --32 init/load_gdt.s -o load_gdt.o

#Build IDT
idt: 2dt/idt.c 2dt/load_idt.s
	gcc -m32 -c 2dt/idt.c -o idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	as --32 2dt/load_idt.s -o load_idt.o

#Build kernel main image
kernel: init/os_rpc.c
	gcc -m32 -c init/os_rpc.c -o image.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 

#Build kernel main image
kernel_vmpc: init/os_vmpc.c
	gcc -m32 -c init/os_vmpc.c -o imagei.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 

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
ld: linker.ld linker.ld image.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o
	ld -m elf_i386 -T linker.ld image.o utils.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o -o ATOS1.bin -nostdlib

#Link everything up
ld_vm: linker.ld linker.ld imagei.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o
	ld -m elf_i386 -T linker.ld imagei.o utils.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o -o ATOS2.bin -nostdlib

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

#Build ISO file via grub
buildgrub_vmpc: ATOS2.bin
	grub-file --is-x86-multiboot ATOS2.bin
	mkdir -p vmpc_isodir/boot/grub
	cp ATOS2.bin vmpc_isodir/boot/ATOS2.bin
	grub-mkrescue -o atos_vmpc.iso vmpc_isodir

#Run it in QEMU
qemu: atos_rpc.iso
	qemu-system-i386 -cdrom atos_rpc.iso

#Run it in QEMU
qemu_vmpc: atos_vmpc.iso
	qemu-system-i386 -cdrom atos_vmpc.iso

#install packages if not via apt
installpkg_apt:
	bash -c "sudo apt install grub2-common gcc gcc-multilib binutils";

#defines elf-i686-gcc if installed
elf_i386_declare:
	export PATH="/opt/cross/bin:$PATH"

#Cleaning up files
clean:
	rm image.o char.o boot.o utils.o

#Cleaning up files
clean_vmpc:
	rm imagei.o char.o boot.o utils.o
