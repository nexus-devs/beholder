#include "Parser.h"


// Default constructor
Parser::Parser(std::string sFileName) {

    // Read json file
    std::ifstream fFile(sFileName);
    if (fFile.fail()) {
        std::cerr << "Parsing error while opening file";
        return;
    }

    // Serialize
    fFile >> jConfig;

    fFile.close();
}