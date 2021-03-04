![AhnTriLogo](at.jpg)
# AhnTri OS
This is my hobby OS, now it can be run on real hardware, focused on bootable USBs.
Can be used as multipurpose like calculators and more. 
Has a simple code art in it and you can try it out at forker.h.
Now supporting text I/O, not NumDOS.
However, NumDOS is available at GeX(something like GUI, I mean, like Samsung DeX or Kali KeX)
Recommend Ventoy for USB.
# Current status
Added feature(Accomplished)
- Terminal instead of NumDOS
- Better system
- UI change
- Additional functions in CCalc
- Renamed function `os_print_string` to `printf`
- Updated math.h for more efficient math
- small other changes
- PS/2 Mouse but it has a bug which makes the OS a mess.
- GDT and malloc() memory managements
- Timer

WIW(What I Want, Unaccomplished yet)
- Directory access
- Graphichs

#Multiboot
In able to run it in your PC, copy and paste the code below.
```INI
menuentry "AhnTriOS" {
	multiboot /boot/directory/of/your/os/ATOS1.bin
}
```
# Screenshots
![Screenshot of 1.2.3](sshot.png)
![Screenshot of 1.2.3](sshot2.png)
![Screenshot of 1.2.3](sshot3.png)
![Screenshot of 1.2.3](sshot4.png)
