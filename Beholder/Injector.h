#pragma once

#include "stdafx.h"
#include <Windows.h>
#include <fstream>


// Class for injecting DLLs
class Injector {
    public:
        static void Inject(DWORD pId, std::string dllPath);

    private:
        static void ThrowWindowsRuntime(std::string sErrMsg);
};