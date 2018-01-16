#include "Parser.h"


// Default constructor
Parser::Parser(std::string sFileName) {

    // Read json file
    std::ifstream file(sFileName);
    if (file.fail()) {
        std::cerr << "Parsing error while opening file: " << strerror(errno);
        return;
    }

    // Serialize
    file >> jConfig;

    file.close();
}