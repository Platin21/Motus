// @v 1.7.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once

#include "Types.hpp"
#include "CString.hpp"

// Header
#define MT_VERSION_1_7_0
// Header

void StrSkipSpace(char*& text)
{
    while(*text == 32) text++;
}

void StrSkipNewline(char*& text)
{
    while(*text == 10) text++;
    while(text[0] == 13 && text[1] == 10) text++;
}

void StrSkipNewlineAndSpace(char*& text)
{
  while(*text == 32 || *text == 10 || (text[0] == 13 && text[1] == 10)) text++;
}

void StrSkipNumber(char*& text)
{
    while(*text <= 57 && *text >= 48) text++;
}

void StrSkipFromAtoZandatoz(char*& text)
{
    while((*text <= 90 && *text >= 65)||(*text <= 122 && *text >= 97)) text++;
}

void StrSkipFromAtoZ(char*& text)
{
    while(*text <= 90 && *text >= 65) text++;
}

void StrSkipFromatoz(char*& text)
{
    while(*text <= 122 && *text >= 97) text++;
}

void StrSkipChar(char*& text,const char toSkip)
{
    while(*text == toSkip) text++;
}

void StrSkip(char*& text,i64 amount)
{
    for(;amount >= 0; --amount) ++text;
}

void StrSkipPrefix(const char* prefix,char* OutText,i64 OutTextSize)
{
    //
}

void StrSkipPostfix(const char* prefix,char* OutText,i64 OutTextSize)
{
    //
}







