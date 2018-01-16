#include "catch.hpp"
#include "../Beholder/Parser.h"


std::string sTestFile = "test.cfg";

// Test file for the parser
TEST_CASE("config gets correctly parsed", "[parser]") {

    Parser hParser(sTestFile);

    REQUIRE(hParser.jConfig["scenes"][0]["name"] == "foundry");
}