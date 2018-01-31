#include "catch.hpp"
#include "../Beholder/Injector.h"


LPCWSTR sTestExe = L"test_window.exe";

// Test file for the injector and general nexus screen
TEST_CASE("window gets correctly injected", "[injector]") {

    // Open up test .exe
    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    BOOL createdProcess = CreateProcess(sTestExe, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);

    REQUIRE(createdProcess);


    SECTION("injection function works") {

        REQUIRE_NOTHROW(Injector::Inject(GetProcessId(processInfo.hProcess), "../NexusScreen.dll"));
    }


    // Cleanup
    TerminateProcess(processInfo.hProcess, 0);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
}