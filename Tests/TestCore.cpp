#include "catch.hpp"
#include "../Beholder/Core.h"


// Test if the general construction works
TEST_CASE("core gets correctly initialized", "[core]") {

    // Open up test .exe
    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    BOOL createdProcess = CreateProcess("test_window.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);

    REQUIRE(createdProcess);


    SECTION("window gets found") {

        Core hCore("Example");

        REQUIRE_NOTHROW(hCore);
        REQUIRE_THROWS_AS(Core("doesnt exist"), std::invalid_argument);
    }   
}