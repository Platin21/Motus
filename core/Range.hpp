// @v 1.2.0
// @n Motus_Lib
// @a Armin Hamar
#pragma once
#include <cstdlib>

// @t i64 64bit type
using i64 = long long;

// @s represents the range in memmory
template<typename T>
struct Range_info
{
    i64 size; 
    T *begin;
    T *end;
};

template <typename T>
class Range {
    Range_info<T>* info;
public:
    Range(T* begin,i64 size)
    {
        info = (Range_info<T>*)calloc(1,sizeof(Range<int>));
        info->begin = begin;
        info->end = begin + size;
        info->size = size;
    }
    
    void move(i64 by_elements)
    {
        if(!((by_elements + info->begin) == info->end))
        {
            info->begin += by_elements;
        }
    }
    
    T get()
    {
        return *info->begin;
    }
    
    T get_next()
    {
        info->begin += 1;
        return get();
    }
    
};
