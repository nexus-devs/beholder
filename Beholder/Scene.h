#pragma once

#include "stdafx.h"
#include "Actor.h"


// Class for scene representation
class Scene {
    public:
        Scene(std::string sSceneName);

        std::string sName;
        std::vector<Actor> vActors;
};