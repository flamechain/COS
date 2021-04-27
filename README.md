# COS

Custom Operating System

Tested on Linux, Windows

## What You'll Find

| path | description |
|-|-|
| docs/ | Version notes and error codes (for troubleshooting); go [here](https://github.com/flamechain/COS/issues) to see bugs |
| src/ | All source files (\*.c, \*.h, \*.S, \*.ld) |

| src/path | description |
|-|-|
| ./ | General files (main.c, util.h, linker.ld) |
| kernel/ | Kernel and startup assembly files |
| kernel/include/ | Header files for kernel, added to gcc path so you can include from anywhere |
| lib/ | Standard library implementations for COS |
| lib/include | Header files for libs, added to gcc path so you can include from anywhere |

## Building

### Linux

Make sure you have the i686 toolchain (i686-elf). Run these commands in this order:

```bash
$ make all
$ make run
```

### Windows

Follow Linux with Ubuntu (bash terminal) from the Microsoft Store.

If you get a gtk initialization failure when running `$ make run` in Ubuntu, try running it in a native terminal or bash instead. Note: make sure you then have qemu installed on your machine, not only in Ubuntu. You can install qemu [here](https://www.qemu.org/download/).

### Mac

For the cross-compiler: `$ brew tap nativeos/i386-elf-toolchain && brew install i386-elf-binutils i386-elf-gcc`

Then run the same make commands as Linux. The Makefile automatically switches to i386-elf instead of i686-elf.
