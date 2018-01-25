#pragma once

#include "stdafx.h"


// Class for actor representation
class Actor {
    public:
        Actor(std::string sActorName, std::string sTemplatePath, std::string sMaskPath = "");

        std::string sName;
        cv::Mat mTemplate;
        cv::Mat mMask;
};