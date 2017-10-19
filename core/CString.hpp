// @v 1.8.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"

// Header
#define MT_VERSION_1_8_0
// Header

#define UTF8(Input) ((utf8Char*)Input)
#define Char(Input) ((char*)Input)

i64 CStringLenghtOf(const utf8Char* text)
{
    utf8Char const *it = text;
    for(; *it; ++it);
    return (it - text);
}

bool CStringCompare(const utf8Char* string1,const utf8Char* string2)
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

const utf8Char* CStringChain(utf8Char* destionation_string1,const utf8Char* string2)
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

i64 CStringNextCodePointSize(utf8Char* of_string)
{
    if (*of_string < 0x80)
        return 1;
    if ((*of_string & 0xe0) == 0xc0)
        return 2;
    if ((*of_string & 0xf0) == 0xe0)
        return 3;
    if ((*of_string & 0xf8) == 0xf0)
        return 4;
    if ((*of_string & 0xfc) == 0xf8)
        return 5;
    if ((*of_string & 0xfe) == 0xfc)
        return 6;
    
    return 0;
}

bool CStringIsNextCharRegionalIndicator(utf8Char* in_this_text,i64&& len)
{
    if(len < 3) return false;
    if(len < 6) return false;
    
    if(in_this_text[0] == 240
       && in_this_text[1] == 159
       && in_this_text[2] == 135)
    {
        if (in_this_text[4] == 240
            && in_this_text[5] == 159
            && in_this_text[6] == 135)
            return true;
        
        return false;
    }
    return false;
}

bool CStringIsNextCharRegionalIndicator(utf8Char* in_this_text,i64& len)
{
    if(len < 3) return false;
    if(len < 6) return false;
    
    if(in_this_text[0] == 240
       && in_this_text[1] == 159
       && in_this_text[2] == 135)
    {
        if (in_this_text[4] == 240
            && in_this_text[5] == 159
            && in_this_text[6] == 135)
            return true;
        
        return false;
    }
    return false;
}

i64 CStringClusters(utf8Char* of_string)
{
    i64 size = 0;
    i64 offset_in_string = 0;
    i64 len = CStringLenghtOf(of_string);
    for(i64 i = 0; i < len; i += 1)
    {
        i64 cluster_offset = CStringNextCodePointSize(of_string);
        if(cluster_offset == 4)
        {
            if(CStringIsNextCharRegionalIndicator(of_string,len - i))
            {
                size += 1;
                of_string += 8;
                offset_in_string += 8;
            }
            else
            {
                size += 1;
                of_string += 4;
                offset_in_string += 4;
            }
        }
        else
        {
            size += 1;
            of_string  += cluster_offset;
            offset_in_string += cluster_offset;
        }
        if(offset_in_string == len) return size;
    }
    return size;
}

