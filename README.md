![AhnTriLogo](at.jpg)
# AhnTri OS
This is my hobby OS, now it can be run on real hardware, focused on bootable USBs.
Can be used as multipurpose like calculators and more. 
Has a simple code art in it and you can try it out at forker.h.
Now supporting text I/O, not NumDOS.
However, NumDOS is available at GeX(something like GUI, I mean, like Samsung DeX or Kali KeX)
Recommend Ventoy for USB.
Since I am just 13, my code will be super bad. 
And sorry for my slow updates; I need to go to school and I have exams.
OK, um... I have found out I have missed malloc h here and it wont build giving the error no function malloc and free
And I just made a new feature: memory copy.
Now it can memorize chars like a or b
I am looking forward to usernames and passwords, and some AI funtions for cbot.
# Current status
Added feature(Accomplished)
- Terminal instead of NumDOS
- Better system
- UI change
- Additional functions in CCalc
- Renamed function `os_print_string` to `printf`
- Updated math.h for more efficient math
- small other changes
- PS/2 Mouse but it has a bug which makes the OS a mess.(So sorry but don't move your mouse when running in real hardware. I've done it and this but killed me.)
- GDT and malloc() memory managements
- memcpy() function
- Timer

WIW(What I Want, Unaccomplished yet)
- Directory access
- Graphichs
- Fonts

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
