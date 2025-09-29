#include <cstring>
#include <cctype>
#include "string_handle.hpp"

void toUpper(char * inputString)
{
    for(size_t i = 0; i < strlen(inputString); ++i)
    {
        inputString[i] = toupper(inputString[i]);
    }
}