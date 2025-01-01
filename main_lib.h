#ifndef MAIN_LIB_H
#define MAIN_LIB_H

#include <string>
#include <vector>
#include <variant>

#define open extern "C"
#ifdef _WIN32
    #define DLLEXPORT __declspec(dllexport)
    #define helper __stdcall
#else
    #define DLLEXPORT __attribute__((visibility("default")))
    #define helper
#endif

using ReturnType = std::variant<std::nullptr_t, std::string>;
using VarType = std::string;

// Function pointer type for library functions
typedef ReturnType(*FunctionPtr)(const std::vector<std::string>& args);
typedef VarType(*VariablePtr);

// Function to list all available functions in the library
open DLLEXPORT std::vector<std::string> helper listFunctions();

// Function to get a function pointer by name
open DLLEXPORT FunctionPtr helper getFunction(const char* name);

open DLLEXPORT std::vector<std::string> helper listVars();

open DLLEXPORT VarType helper getVariable(const char* name);

#endif // MAIN_LIB_H