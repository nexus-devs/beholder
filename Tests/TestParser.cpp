#include "catch.hpp"
#include "../Beholder/Parser.h"


std::string sTestFile = "test.cfg";

// Test file for the parser
TEST_CASE("config gets correctly parsed", "[parser]") {

    Parser hParser(sTestFile);

    REQUIRE_NOTHROW(hParser);
    REQUIRE_THROWS_AS(Parser("not_existing_file"), std::runtime_error);


    SECTION("scenes get properly constructed") {

        // Test for proper construction
        json jSampleScene = { {"name", "sample_scene"} };
        jSampleScene["actors"] = json::array();
        jSampleScene["actors"].push_back({ { "name", "test_actor" }, { "template", "test_chat.jpg" } });
        jSampleScene["actors"].push_back({ { "name", "test_actor2" }, { "template", "test_chat.jpg" } });

        Scene hScene = hParser.ConstructScene(jSampleScene);

        REQUIRE_NOTHROW(hScene);
        REQUIRE(hScene.sName == "sample_scene");

        // Test for correct error handling
        json jNotSceneObj = false;
        json jNoNameFieldObj = { {"test", "no"} };
        REQUIRE_THROWS_AS(hParser.ConstructScene(jNotSceneObj), std::invalid_argument);
        REQUIRE_THROWS_AS(hParser.ConstructScene(jNoNameFieldObj), json::type_error);
    }

    SECTION("actors get properly constructed") {

        // Test for proper construction
        json jSampleActor = { { "name", "sample_actor" }, { "template", "test_chat.jpg" } };
        Actor hActor = hParser.ConstructActor(jSampleActor);

        REQUIRE_NOTHROW(hActor);
        REQUIRE(hActor.sName == "sample_actor");

        // Test for correct error handling
        json jNotActorObj = false;
        json jNoNameFieldObj = { { "test", "no" }, { "template", "no" } };
        REQUIRE_THROWS_AS(hParser.ConstructActor(jNotActorObj), std::invalid_argument);
        REQUIRE_THROWS_AS(hParser.ConstructActor(jNoNameFieldObj), json::type_error);
    }
}