#include "catch.hpp"
#include "../Beholder/Parser.h"


std::string sTestFile = "test.cfg";

// Test file for the parser
TEST_CASE("config gets correctly parsed", "[parser]") {

    Parser hParser(sTestFile);

    REQUIRE_NOTHROW(hParser);


    SECTION("scenes get properly constructed") {

        // Test for proper construction
        json jSampleScene = { {"name", "sample_scene"} };
        Scene hScene = hParser.ConstructScene(jSampleScene);

        REQUIRE_NOTHROW(hScene);
        REQUIRE(hScene.sName == "sample_scene");

        // Test for correct error handling
        json jNotSceneObj = false;
        REQUIRE_THROWS(hParser.ConstructScene(jNotSceneObj));
    }
}