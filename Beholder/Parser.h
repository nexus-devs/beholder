#pragma once

#include "stdafx.h"
#include "json.hpp"


// Namespaces
using json = nlohmann::json;

// Class for parsing Beholder config files
class Parser {
    public:
        Parser(const char* sFilePath);

    private:
        json jConfig;
};