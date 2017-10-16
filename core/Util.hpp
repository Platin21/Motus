// @v 1.5.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"

// Header
#define MT_VERSION_1_5_0
// Header

template<typename T>
i32 decimalsOf(T numberToCountDigits)
{
    i32 digits = 0;
    while(true)
    {
        if(numberToCountDigits < 10) return digits + 1;
        if(numberToCountDigits < 100) return digits + 2;
        if(numberToCountDigits < 1000) return digits + 3;
        if(numberToCountDigits < 10000) return digits + 4;
        if(numberToCountDigits < 100000) return digits + 5;
        if(numberToCountDigits < 1000000) return digits + 6;
        numberToCountDigits /= 1000000;
        digits += 6;
    }
    
    return 0;
};

double powerOf10(i8 exponent)
{
    switch(exponent)
    {
        case -1:
            return 0.1;
        case -2:
            return 0.01;
        case -3:
            return 0.001;
        case -4:
            return 0.0001;
        case -5:
            return 0.00001;
        case -6:
            return 0.000001;
        case -7:
            return 0.0000001;
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 100;
        case 3:
            return 1000;
        case 4:
            return 10000;
        case 5:
            return 100000;
    }
    i64 num = 100000;
    for(i64 i = 6; i <= exponent; ++i)
    {
        num *= 10;
    }
    return num;
}
