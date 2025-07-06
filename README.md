# KernelDriverTest + IOCTL_Test

Two small projects to test Windows kernel driver IOCTL communication.
- **KDT**: Kernel driver creating device `\\.\KDT`
- **IOCTL_Test**: User app sending an IOCTL and reading the reply
---
## What’s going on?
The driver listens for `IOCTL_PING`. When it gets it, it replies `"pong"`.
The user app opens the device and sends this IOCTL to test the link.
---
## How to build
- **Driver:** Use Visual Studio + WDK  
  Target: x64, Release, test signing mode enabled
- **User app:** Compile with any Windows C compiler (cl, gcc...)
---
## How to run
1. Load the driver:
2. sc create krnltest type= kernel binPath= "C:\path\to\KDT.sys"  sc start krnltest
3. Run the user app:
       You should see:  
       `Driver Answer : pong (Size: 5)`
---
## How to crash the driver (on purpose)
Add this in `IoControl()` in the driver:
```c
*(int*)0 = 0;
```
Reload driver, run user app → BSOD.
Do this only on a VM!

## Why i make that ?
For Learn kernel-user communication,
Understand IOCTL basics and IRP and
Practice debugging kernel drivers.

## Debugging tips:
Use DbgView to see driver debug messages,
Check errors with GetLastError() in user app.

## Importants Notes:
No fancy security or validation here,
For learning and quick tests only,
Don’t use in production.

