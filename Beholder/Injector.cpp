#include "Injector.h"


// Basic inject function
void Injector::Inject(DWORD pId, std::string dllPath) {

    // Get const char version of std::string
    const char* cDllPath = dllPath.c_str();

    std::ifstream sFileExistsStream(cDllPath);
    if (!sFileExistsStream.good()) throw std::invalid_argument("file doesnt exist");

    HANDLE hWnd = OpenProcess(PROCESS_ALL_ACCESS, false, pId);
    if (!hWnd) ThrowWindowsRuntime("failed opening process");

    // Get LoadLibraryA adress
    LPVOID lpLoadLibAddr = (LPVOID)(GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"));
    if (!lpLoadLibAddr) ThrowWindowsRuntime("failed loading LoadLibraryA adress");

    // Allocate memory
    LPVOID lpDllNameAlloc = VirtualAllocEx(hWnd, NULL, strlen(cDllPath), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!lpDllNameAlloc) ThrowWindowsRuntime("failed allocating memory");

    if (!WriteProcessMemory(hWnd, lpDllNameAlloc, cDllPath, strlen(cDllPath), NULL)) {
        ThrowWindowsRuntime("failed writing memory");
    }

    // Create thread in target process
    HANDLE hRemoteThread = CreateRemoteThread(hWnd, NULL, NULL, (LPTHREAD_START_ROUTINE)(lpLoadLibAddr), lpDllNameAlloc, 0, NULL);
    if (!hRemoteThread) ThrowWindowsRuntime("failed creating remote thread");

    DWORD iWait = WaitForSingleObject(hRemoteThread, 5000);
    if (iWait) {
        if (iWait == WAIT_FAILED) ThrowWindowsRuntime("failed waiting for thread");
        else throw std::runtime_error("waiting for thread was abandoned");
    }

    // Free up resources
    VirtualFreeEx(hWnd, lpDllNameAlloc, strlen(cDllPath), MEM_RELEASE);
    CloseHandle(hRemoteThread);
    CloseHandle(hWnd);
}


// Helper function for windows error throwing
void Injector::ThrowWindowsRuntime(std::string sErrMsg) {
    throw std::runtime_error(sErrMsg + " [win error: " + std::to_string(GetLastError()) + "]");
}