#include "Core.h"


std::string Core::sNexusScreenPath = "../NexusScreen.dll";


// Default constructor
Core::Core(std::string sWindowName, std::string sWindowClass) {

    HWND hWindow = FindWindowEx(0, 0, sWindowName.c_str(), sWindowClass.c_str());
    if (!hWindow) throw std::invalid_argument("couldnt find the window [win error: " + std::to_string(GetLastError()) + "]");

    DWORD iProcessId = GetProcessId(hWindow);

    Injector::Inject(iProcessId, sNexusScreenPath);
}