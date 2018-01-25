#include "Actor.h"


// Default constructor
Actor::Actor(std::string sActorName, cv::Mat mTemplateObj, cv::Mat mMaskObj = cv::Mat()) {

}

// Constructor with paths
Actor::Actor(std::string sActorName, std::string sTemplatePath, std::string sMaskPath = "") {

    sName = sActorName;
}