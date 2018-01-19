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