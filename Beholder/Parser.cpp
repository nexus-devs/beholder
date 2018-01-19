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
    if (jSceneObj.is_object()) throw std::invalid_argument("json value isn't an object");

    // Construct scene object
    Scene hScene(jSceneObj["name"]);

    return hScene;
}