#pragma once

#include "stdafx.h"
#include "json.hpp"
#include "Scene.h"
#include <fstream>


using json = nlohmann::json;

// Class for parsing Beholder config files
class Parser {
    public:
        Parser(std::string sFileName);
        Scene ConstructScene(json jSceneObj);

    private:
        json jConfig;
};