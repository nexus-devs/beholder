#include "Injector.h"


// Basic inject function
void Injector::Inject(DWORD pId, std::string dllPath) {

    // Get const char version of std::string
    const char* cDllPath = dllPath.c_str();

    HANDLE hWnd = OpenProcess(PROCESS_ALL_ACCESS, false, pId);
    if (!hWnd) throw std::runtime_error("failed opening process: " + GetLastError());

    // Get LoadLibraryA adress
    LPVOID lpLoadLibAddr = (LPVOID)(GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"));
    if (!lpLoadLibAddr) throw std::runtime_error("failed loading LoadLibraryA adress: " + GetLastError());

    // Allocate memory
    LPVOID lpDllNameAlloc = VirtualAllocEx(hWnd, NULL, strlen(cDllPath), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!lpDllNameAlloc) throw std::runtime_error("failed allocating memory: " + GetLastError());

    if (!WriteProcessMemory(hWnd, lpDllNameAlloc, cDllPath, strlen(cDllPath), NULL)) {
        throw std::runtime_error("failed writing memory: " + GetLastError());
    }

    // Create thread in target process
    HANDLE hRemoteThread = CreateRemoteThread(hWnd, NULL, NULL, (LPTHREAD_START_ROUTINE)(lpLoadLibAddr), lpDllNameAlloc, 0, NULL);
    if (!hRemoteThread) throw std::runtime_error("failed creating remote thread: " + GetLastError());

    DWORD iWait = WaitForSingleObject(hRemoteThread, 5000);
    if (iWait) {
        if (iWait == WAIT_FAILED) throw std::runtime_error("failed waiting for thread: " + GetLastError());
        else throw std::runtime_error("waiting for thread was abandoned");
    }

    // Free up resources
    VirtualFreeEx(hWnd, lpDllNameAlloc, strlen(cDllPath), MEM_RELEASE);
    CloseHandle(hRemoteThread);
    CloseHandle(hWnd);
}