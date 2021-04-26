# COS

Custom Operating System

Tested on Linux, Windows

## What You'll Find

| path | description |
|-|-|
| old/ | Old code that I cant bring my self to delete, ignored by git |
| docs/ | Bug fixes, version notes |
| src/ | All project files, should change directory to this folder to properly use \*.sh files |

## Building

### Linux

Make sure you have the i686 toolchain. Run these commands in this order:

```bash
make all
```

To run do:

```bash
qemu-system-i386 -kernel cos.kernel
```

### Windows

Follow Linux with Ubuntu (bash terminal) from the Microsoft Store.

### Mac

Not sure. Similar to Linux, figure it out.
