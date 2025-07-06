#pragma once

// Prints a formatted debug message to the kernel debugger
#define DebugMessage(x, ...) DbgPrintEx(0, 0, x, __VA_ARGS__)