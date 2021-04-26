# COS

Custom Operating System

Tested on Linux, Windows

## What You'll Find

| path | description |
|-|-|
| docs/ | Bug fixes, version notes |
| src/ | All source files (\*.c, \*.h, \*.S, \*.ld) |
| logs/ | Debug and error logs; ignored by .gitignore because logs may be different for your build |

| src/path | description |
|-|-|
| ./ | General files (linker.ld) |
| kernel/ | Kernel and startup assembly files |

## Building

### Linux

Make sure you have the i686 toolchain. Run these commands in this order:

```bash
make all
make run
```

### Windows

Follow Linux with Ubuntu (bash terminal) from the Microsoft Store.

If you get a gtk initialization failure, try running `make run` in a native terminal or bash. This requires installing qemu.

### Mac

Not sure. Similar to Linux, figure it out.
