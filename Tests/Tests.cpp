#define CATCH_CONFIG_MAIN
#include "stdafx.h"

// Declare globals
std::string sTestFile = "test.cfg";
std::string sTestExe = "test_window.exe";
std::string sTestExe64 = "test_window64.exe";

// This is the entry point for catch2 tests. Don't write tests here.
TEST_CASE("All test cases reside in other .cpp files (emtpy)", "[multi-file:1]") {}