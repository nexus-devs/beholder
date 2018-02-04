#include "stdafx.h"
#include "../Beholder/Parser.h"


std::string sTestFile = "test.cfg";

// Test file for the parser
TEST_CASE("config gets correctly parsed", "[parser]") {

    Parser hParser(sTestFile);

    REQUIRE_THROWS_AS(Parser("not_existing_file"), std::runtime_error);


    SECTION("scenes get properly constructed") {

        // Test for proper construction
        json jSampleScene = { {"name", "sample_scene"} };
        jSampleScene["actors"] = json::array();
        jSampleScene["actors"].push_back({ { "name", "test_actor" }, { "template", "test_chat.jpg" } });
        jSampleScene["actors"].push_back({ { "name", "test_actor2" }, { "template", "test_chat.jpg" } });

        Scene hScene = hParser.ConstructScene(jSampleScene);

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

        REQUIRE(hActor.sName == "sample_actor");
        REQUIRE(!hActor.mTemplate.empty());
        REQUIRE(hActor.mMask.empty());


        // Test for optional params
        jSampleActor.push_back({ "mask", "test_chat_mask.jpg" });
        Actor hActorOpt = hParser.ConstructActor(jSampleActor);

        REQUIRE(!hActorOpt.mMask.empty());


        // Test for correct error handling
        json jNotActorObj = false;
        json jNoNameFieldObj = { { "test", "no" }, { "template", "no" } };
        json jNoTemplateObj = { { "name", "no" } };
        json jNoExistingTemplateObj = { { "name", "no" }, { "template", "doesntexist.jpg" } };

        REQUIRE_THROWS_AS(hParser.ConstructActor(jNotActorObj), std::invalid_argument);
        REQUIRE_THROWS_AS(hParser.ConstructActor(jNoNameFieldObj), json::type_error);
        REQUIRE_THROWS_AS(hParser.ConstructActor(jNoTemplateObj), json::type_error);
        REQUIRE_THROWS_AS(hParser.ConstructActor(jNoExistingTemplateObj), std::invalid_argument);
    }
}