// @v 1.6.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once

#include "Types.hpp"
#include "Util.hpp"

// Header
#define MT_VERSION_1_6_0
// Header

template<typename T>
void number_to_cstr(T number, utf8Char *destination,i32 decimals)
{
    if (number == 0) {
        destination[0] = '0';
        destination[1] = '\0';
    }
    if (number < 10 && number >= 1) {
        destination[0] = number + '0';
        destination[1] = '\0';
    }
    if(number < 0)
    {
        number = -number;
        destination[0] = '-';
        destination[decimals+1] = '\0';
        while(decimals > 0)
        {
            char reminder = number % 10;
            destination[decimals--] = reminder > 9 ? (reminder - 10) + 'a' : reminder + '0';
            number /= 10;
        }
    }
    else
    {
        destination[decimals+1] = '\0';
        while(decimals >= 0)
        {
            char reminder = number % 10;
            destination[decimals--] = reminder > 9 ? (reminder - 10) + 'a' : reminder + '0';
            number /= 10;
        }
    }
}

 // fix this
template<typename T>
void decimal_to_cstr(T dbl,utf8Char* destination,i32 persicion = 4)
{
    i64 decimal_part = (i64)dbl;
    if(dbl == __builtin_inff())
    {
        destination[0] = 'i';
        destination[1] = 'n';
        destination[2] = 'f';
        destination[2] = '\0';
        
    }
    
    if(decimal_part < 0)
    {
        decimal_part = -decimal_part;
        i64 float_part = -(dbl - (T)decimal_part) * powerOf10(persicion);
        i64 pos = decimalsOf(decimal_part);
        number_to_cstr(decimal_part, &destination[1],pos-1);
        destination[pos+1] = '.';
        number_to_cstr(float_part, &destination[pos + 2],persicion-1);
        pos += decimalsOf(float_part) + 1;
        destination[pos] = '\0';
        destination[0] = '-';
    }
    else
    {
        i64 float_part = (dbl - (T)decimal_part) * powerOf10(persicion);
        i64 pos = decimalsOf(decimal_part);
        number_to_cstr(decimal_part, &destination[0],decimalsOf(decimal_part));
        destination[pos] = '.';
        number_to_cstr(float_part, &destination[pos + 1],persicion);
        pos += decimalsOf(float_part)+1;
        destination[pos] = '\0';
    }
   
}

i64 next_decimal_size(const utf8Char* text)
{
    bool is_numeric = true;
    long count = 0;
    while(is_numeric)
    {
        count += 1;
        text++;
        if(*text <= 57 && *text >= 48) is_numeric = true;
        else is_numeric = false;
    }
    return count;
}

i64 decimal_size(const utf8Char* text)
{
    i64 front;
    i64 back;
    if(text[0] == '-')
    {
        front = next_decimal_size(text+1);
        front += 1;
        back  = next_decimal_size(text+front);
    }
    else
    {
        front = next_decimal_size(text);
        front += 1;
        back = next_decimal_size(text+front);
    };
    return back + front;
}

i64 numeric_size(const utf8Char* text)
{
    if(text[0] == '-') return next_decimal_size((text + 1)) + 1;
    else return next_decimal_size(text);
}

template<typename T>
void charptr_to_numeric_value(const utf8Char *txt,T *result,i64 lenght = 0) {
    if(lenght == 0) lenght = next_decimal_size(txt);
    if(txt[0] == '-')
    {
        *result = 0;
        char *pt = (char *)txt + lenght;
        for (i64 i = 0; i < lenght; ++i) {
            *result += powerOf10(i) * (*(pt--) - '0');
        }
        *result = -*result;
    }
    else
    {
        *result = 0;
        char *pt = (char *)txt + (lenght - 1);
        for (i64 i = 0; i < lenght; ++i) {
            *result += powerOf10(i) * (*(pt--) - '0');
        }
    }
}

template<typename T>
void charptr_to_decimal_value(const utf8Char *txt,T *out) {
    i64 part = 0;
    i64 fpart = 0;
    if(txt[0] == '-')
    {
        i64 Intlenght = next_decimal_size(txt+1);
        i64 fltlenght = next_decimal_size((txt + Intlenght + 2));
        charptr_to_numeric_value(txt, &part,Intlenght);
        charptr_to_numeric_value((txt + Intlenght + 2), &fpart,fltlenght);
        *out = -powerOf10(-fltlenght) * fpart;
    }
    else
    {
        i64 Intlenght = next_decimal_size(txt);
        i64 fltlenght = next_decimal_size((txt + Intlenght + 1));
        charptr_to_numeric_value(txt, &part,Intlenght);
        charptr_to_numeric_value((txt + Intlenght + 1), &fpart,fltlenght);
        *out = powerOf10(-fltlenght) * fpart;
    }
    *out += part;
}
