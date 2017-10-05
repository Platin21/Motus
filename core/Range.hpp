// @v 1.2.0
// @n Motus_Lib
// @a Armin Hamar
#pragma once
#include <cstdlib>

// @t i64 64bit type
using i64 = long long;

template<T>
struct Range_info
{
    i64 size;
    T *begin;
    T *end;
};

template <T>
class Range {
    Range_info<T>* info;
public:
    Range(T* begin,i64 size)
    {
        info = (T*)calloc();
    }
};
