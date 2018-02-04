#include "Core.h"


std::string Core::sNexusScreenPath = "../NexusScreen.dll";


// Default constructor
Core::Core(std::string sWindowName, std::string sWindowClass) {

    LPCSTR sWindowClassConverted = NULL;
    if (!sWindowClass.empty()) sWindowClassConverted = sWindowClass.c_str();

    HWND hWindow = FindWindowEx(0, 0, sWindowClassConverted, sWindowName.c_str());
    if (!hWindow) throw std::invalid_argument("couldnt find the window [win error: " + std::to_string(GetLastError()) + "]");

    DWORD iProcessId;
    if (!GetWindowThreadProcessId(hWindow, &iProcessId)) throw std::runtime_error("couldnt retrieve process id");

    Injector::Inject(iProcessId, sNexusScreenPath);
}