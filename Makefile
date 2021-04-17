#######################################################################################################################################################
all: make_deafult

#Makes everything up
make_deafult: bboot kernel ccalc advset cbot cal art fishdic game notes osver keychar gdt idt ld buildgrub clean

#Build kernel main image
kernel: init/os_rpc.c
	gcc -m32 -c init/os_rpc.c -o image.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 
#Link everything up
ld: linker.ld linker.ld image.o ccalc.o advset.o cbot.o cal.o art.o notes.o osver.o fishdic.o credit.o game.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o
	ld -m elf_i386 -T linker.ld image.o advset.o ccalc.o cbot.o cal.o art.o notes.o osver.o fishdic.o credit.o game.o utils.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o -o ATOS1.bin -nostdlib

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

#######################################################################################################################################################
#Build GDT
gdt: init/gdt.c init/load_gdt.s
	gcc -m32 -c init/gdt.c -o gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	as --32 init/load_gdt.s -o load_gdt.o

#Build IDT
idt: 2dt/idt.c 2dt/load_idt.s
	gcc -m32 -c 2dt/idt.c -o idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	as --32 2dt/load_idt.s -o load_idt.o

ccalc: tcom/ccalcfi.c
	gcc -m32 -c tcom/ccalcfi.c -o ccalc.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

advset: tcom/advset.c
	gcc -m32 -c tcom/advset.c -o advset.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

notes: tcom/notes.c
	gcc -m32 -c tcom/notes.c -o notes.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

osver: tcom/osver.c
	gcc -m32 -c tcom/osver.c -o osver.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

cbot: tcom/cbot.c
	gcc -m32 -c tcom/cbot.c -o cbot.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

cal: tcom/cal.c
	gcc -m32 -c tcom/cal.c -o cal.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

art: tcom/art.c
	gcc -m32 -c tcom/art.c -o art.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

fishdic: tcom/fishdic.c
	gcc -m32 -c tcom/fishdic.c -o fishdic.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

credit: tcom/credit.c
	gcc -m32 -c tcom/credit.c -o credit.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

game: tcom/game.c
	gcc -m32 -c tcom/game.c -o game.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#Assemble gru(bboot)loader
bboot: boot/boot.s
	as --32 boot/boot.s -o boot.o

#Build Keychar drivers
keychar: kio/char.c kio/utils.c
	gcc -m32 -c kio/char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 
	gcc -m32 -c kio/utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

clean:
	rm *.o
#######################################################################################################################################################

#Makes VMPC up
vmpc: bboot kernel_vmpc ccalc advset cbot cal art fishdic credit game notes osver keychar gdt idt ld_vm buildgrub_vmpc clean

#Build kernel main image
kernel_vmpc: init/os_vmpc.c
	gcc -m32 -c init/os_vmpc.c -o imagei.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra 

#Link everything up
ld_vm: linker.ld linker.ld imagei.o ccalc.o advset.o cbot.o cal.o art.o notes.o osver.o fishdic.o credit.o game.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o
	ld -m elf_i386 -T linker.ld imagei.o ccalc.o advset.o cbot.o cal.o art.o notes.o osver.o credit.o fishdic.o game.o utils.o char.o boot.o gdt.o load_gdt.o idt.o load_idt.o -o ATOS2.bin -nostdlib

#Build ISO file via grub
buildgrub_vmpc: ATOS2.bin
	grub-file --is-x86-multiboot ATOS2.bin
	mkdir -p vmpc_isodir/boot/grub
	cp ATOS2.bin vmpc_isodir/boot/ATOS2.bin
	grub-mkrescue -o atos_vmpc.iso vmpc_isodir

#Run it in QEMU
qemu_vmpc: atos_vmpc.iso
	qemu-system-i386 -cdrom atos_vmpc.iso

#######################################################################################################################################################
