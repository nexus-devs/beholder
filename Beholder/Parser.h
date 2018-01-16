#pragma once

#include "stdafx.h"
#include "json.hpp"
#include <fstream>


// Namespaces
using json = nlohmann::json;

// Class for parsing Beholder config files
class Parser {
    public:
        Parser(std::string sFileName);

    private:
        json jConfig;
};