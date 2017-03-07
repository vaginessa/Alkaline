The Windows API SetWindowsHookEx is often used by malware to implement a key logger in user-space. There are two keyboard-related hooking options: WH_KEYBOARD and WH_KEYBOARD_LL.

###### WH_KEYBOARD

With this option you implement the callback function in a DLL that will be injected into any process that received keyboard input. Note that a 32-bit DLL will only be injected into 32-bit processes and similarly for a 64-bit DLL, so to capture all keystrokes, you’ll need two separate DLLs. The hook will be maintained until UnhookWindowsHook is called or the process that set the hook exits.

###### WH_KEYBOARD_LL

This option creates a callback function that is invoked via windows messages. It does not perform any process injection and does not require that the callback is in a DLL. It does require that the application has a Windows message pump to handle the processing. This method works against both 32 and 64 bit processes on Windows 7. The hook will be maintained until UnhookWindowsHook is called or the process that set the hook exits.
