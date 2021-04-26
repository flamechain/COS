# Errors

This document goes through all the error codes if you happen to stumble upon one.

For all errors try the following if you get stuck:

- Make sure that all files are present and unmodified.
- Check that you built correctly for your platform.
- Check for assembler errors and go from there.

| # | Description | Possible Solutions |
|:-:|-|-|
| 0 | Debugging error. | Check that you dont have a debug distribution. |
| 1 | Failed to initalize kernel.serial module. | Check that serial.h and serial.c are present in the src/kernel directory. |
