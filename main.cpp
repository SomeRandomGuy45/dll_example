#include "main_lib.h"
#include <iostream>

std::string test = "hi!";

open DLLEXPORT ReturnType helper print_test(const std::vector<std::string>& args) {
    std::cout << "hi!\n";
    return nullptr;
}

open DLLEXPORT ReturnType helper add_test(const std::vector<std::string>& args) {
    return std::to_string(2 + 2);
}

open DLLEXPORT std::vector<std::string> helper listFunctions() {
    return {std::string("print_test"), std::string("add_test")};
}

open DLLEXPORT FunctionPtr helper getFunction(const char* name) {
    if (std::string(name) == "print_test") {
        return &print_test;
    } else if (std::string(name) == "add_test") {
        return &add_test;
    }
    return nullptr;
}

open DLLEXPORT std::vector<std::string> helper listVars()
{
    return {"test"};
}

open DLLEXPORT VarType helper getVariable(const char *name)
{
    std::string varName(name);
    if (varName == "test") {
        return test;
    }
    return "";
}