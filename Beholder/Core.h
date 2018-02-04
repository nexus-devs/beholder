#pragma once

#include "stdafx.h"
#include "Injector.h"


// Beholder core class
class Core {
    public:
        Core(std::string sWindowName, std::string sWindowClass = NULL);

    private:
        static std::string sNexusScreenPath;
};