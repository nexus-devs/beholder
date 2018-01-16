#include "Parser.h"
#include <fstream>


// Default constructor
Parser::Parser(const char* sFileName) {

    // Read json file
    std::ifstream file(sFileName);
    if (file.fail()) {
        std::cerr << "Parsing error while opening file: " << strerror(errno);
        return;
    }

    // Serialize
    file >> jConfig;

    // Close file
    file.close();
}