#include <windows.h>
#include <stdio.h>

// Define the IOCTL code (must match the one in the driver)
#define IOCTL_PING CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

int main()
{
    // Open a handle to the device created by the driver
    HANDLE hDevice = CreateFileA(
        "\\\\.\\KDT", // Symbolic link name
        GENERIC_READ | GENERIC_WRITE, // Access mode
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hDevice == INVALID_HANDLE_VALUE)
    {
        printf("Device opening error: %lu\n", GetLastError());
        return 1;
    }

    char output[64] = { 0 };
    DWORD bytesReturned = 0;

    // Send IOCTL_PING to the driver
    BOOL success = DeviceIoControl(
        hDevice,
        IOCTL_PING,
        NULL, 0, // No input buffer
        output, sizeof(output), // Output buffer
        &bytesReturned,
        NULL
    );

    if (!success)
    {
        printf("DeviceIoControl Error : %lu\n", GetLastError());
        CloseHandle(hDevice);
        return 1;
    }

    printf("Driver Answer : %s (Size: %lu)\n", output, bytesReturned);

    CloseHandle(hDevice);
    return 0;
}
