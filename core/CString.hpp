// @v 1.8.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"

// Header
#define MT_VERSION_1_8_0
// Header

i64 CStringLenghtOf(const char* text)
{
    char const *it = text;
    for(; *it; ++it);
    return (it - text);
}

bool CStringCompare(const char* string1,const char* string2)
{
    i64 string1_len = CStringLenghtOf(string1);
    i64 string2_len = CStringLenghtOf(string2);
    if(string1_len != string2_len) return false;
    
    if(string1_len == 1)
    {
        if(string1[0] == string2[0])
            return true;
        else
            return false;
    }
    if(string1_len == 2)
    {
        if(string1[0] == string2[0] && string1[1] == string2[1])
            return true;
        else
            return false;
    }
    else if(string1_len == 3)
    {
        if(string1[0] == string2[0] && string1[1] == string2[1] && string1[2] == string2[2])
            return true;
        else
            return false;
    }
    
    i64 valid_len = 0;
    for(;*string1 == *string2 && *string1 != '\0' ;valid_len += 1,string1++,string2++);
    
    if(valid_len != string1_len) return false;
    
    return true;
}

const char* CStringChain(char* destionation_string1,const char* string2)
{
    i64 string1_len = CStringLenghtOf(destionation_string1);
    i64 string2_len = CStringLenghtOf(string2);
    
    if(string2_len == 1)
    {
      destionation_string1[string1_len+1] = string2[0];
    }
    else if(string2_len == 2)
    {
        destionation_string1[string1_len+1] = string2[0];
        destionation_string1[string1_len+2] = string2[1];
        destionation_string1[string1_len+2] = '\0';
    }
    
    destionation_string1 += string1_len;
    for(i64 i = 0; i < string2_len; ++i)
    {
        *destionation_string1 = *string2;
        destionation_string1 += 1;
        string2 += 1;
    };
    
    
    destionation_string1[1] = '\0';
    return (destionation_string1 - (string1_len + string2_len));
}

