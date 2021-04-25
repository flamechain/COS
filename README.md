# COS

Custom Operating System

Tested on Linux, Windows

## What You'll Find

| path | description |
|-|-|
| docs/ | Bug fixes, version notes |
| src/ | All project files, should change directory to this folder to properly use \*.sh files |

| src/path | description |
|-|-|
| isodir/ | Temp grub folder |
| sysroot/ | Temp folder |
| kernel/ | Kernel files |
| libc/ | Standard headers |

## Building

### Linux

Make sure you have the i686 toolchain. Run these makefile commands in this order:

```bash
# You can also use ./clean.sh to clear old files
./headers.sh
./iso.sh
```

If your using the grub iso, do:

```bash
./qemu.sh
```

or

```bash
qemu-system-i386 -cdrom cos.iso
```

For directly using the kernel file, do:

```bash
qemu-system-i386 -kernel kernel/cos.kernel
```

### Windows

Follow Linux with Ubuntu (bash terminal) from the Microsoft Store.

### Mac

Not sure. Similar to Linux, figure it out.
