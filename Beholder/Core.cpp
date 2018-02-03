#include "Core.h"


std::string sNexusScreenPath = "../NexusScreen.dll";


// Default constructor
Core::Core() {

    Injector::Inject(20, sNexusScreenPath);
}