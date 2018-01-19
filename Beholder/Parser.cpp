#include "Parser.h"


// Default constructor
Parser::Parser(std::string sFileName) {

    // Read json file
    std::ifstream fFile(sFileName);
    if (fFile.fail()) throw std::runtime_error("failed opening file stream");

    // Serialize
    fFile >> jConfig;

    fFile.close();
}


// Constructs a single scene from a json object
Scene Parser::ConstructScene(json jSceneObj) {

    // Check if its an actual object
    if (!jSceneObj.is_object()) throw std::invalid_argument("json value isn't an object");

    // Construct scene object
    std::string sSceneName = jSceneObj["name"];
    Scene hScene(sSceneName);

    // Add actor objects to scene
    json jActorArray = jSceneObj["actors"];
    for (json::iterator it = jActorArray.begin(); it != jActorArray.end(); ++it) {
        hScene.vActors.push_back(ConstructActor(*it));
    }

    return hScene;
}


// Constructs a single actor from a json object
Actor Parser::ConstructActor(json jActorObj) {

    // Check if its an actual object
    if (!jActorObj.is_object()) throw std::invalid_argument("json value isn't an object");

    // Construct actor object
    std::string sActorName = jActorObj["name"];
    Actor hActor(sActorName);

    return hActor;
}