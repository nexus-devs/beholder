#include "Actor.h"


// Default constructor
Actor::Actor(std::string sActorName, std::string sTemplatePath, std::string sMaskPath = "") {

    sName = sActorName;

    mTemplate = cv::imread(sTemplatePath);
    if (mTemplate.empty()) throw std::invalid_argument("couldnt load template image");

    if (!sMaskPath.empty()) {
        mMask = cv::imread(sMaskPath);
        if (mMask.empty()) throw std::invalid_argument("couldnt load mask image");
    }
}