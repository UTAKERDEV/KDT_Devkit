#pragma once

#include <ntifs.h>

// Driver entry point (called when the driver is loaded)
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);

// Called when the driver is unloaded
NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject);