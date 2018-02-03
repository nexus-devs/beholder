#include "catch.hpp"
#include "../Beholder/Injector.h"


LPCWSTR sTestExe = L"test_window.exe";
LPCWSTR sTestExe64 = L"test_window64.exe";

// Test file for the injector and general nexus screen
TEST_CASE("window gets correctly injected", "[injector]") {

    // Open up test .exe
    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    BOOL createdProcess = CreateProcess(sTestExe, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);

    // Open up test .exe 64bit
    STARTUPINFO info64 = { sizeof(info64) };
    PROCESS_INFORMATION processInfo64;
    BOOL createdProcess64 = CreateProcess(sTestExe64, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info64, &processInfo64);

    REQUIRE(createdProcess);
    REQUIRE(createdProcess64);


    SECTION("injection function works") {

        REQUIRE_NOTHROW(Injector::Inject(GetProcessId(processInfo.hProcess), "../NexusScreen.dll"));
        REQUIRE_THROWS_AS(Injector::Inject(GetProcessId(processInfo.hProcess), "../DoesntExist.dll"), std::runtime_error);
        REQUIRE_THROWS_AS(Injector::Inject(GetProcessId(processInfo64.hProcess), "../NexusScreen.dll"), std::runtime_error);
    }


    // Cleanup
    TerminateProcess(processInfo.hProcess, 0);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
}