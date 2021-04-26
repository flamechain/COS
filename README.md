# COS

Custom Operating System

Tested on Linux, Windows

## What You'll Find

| path | description |
|-|-|
| docs/ | Bug fixes, version notes |
| src/ | All source files (\*.c, \*.h, \*.S, \*.ld) |
| logs/ | QEMU debugging logs |

| src/path | description |
|-|-|
| ./ | Linker and general files (linker.ld) |
| kernel/ | Kernel and startup files (all assembly code is here) |

## Building

### Linux

Make sure you have the i686 toolchain. Run these commands in this order:

```bash
make all
make run
```

Alternatively you can run the kernel file directly instead of using the .iso. Not recommended, but you can by specifiying the -kernel directive on qemu.

### Windows

Follow Linux with Ubuntu (bash terminal) from the Microsoft Store.

### Mac

Not sure. Similar to Linux, figure it out.
