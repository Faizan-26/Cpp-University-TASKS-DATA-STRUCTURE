#pragma once


#ifdef DICTIONARYDLL_EXPORTS
#define DICTIONARYDLL_API __declspec(dllexport)
#else
#define DICTIONARYDLL_API __declspec(dllimport)
#endif

extern "C" {
    DICTIONARYDLL_API void insertCppFunction(const char* word);
    // Add declarations for other functions you want to call
}