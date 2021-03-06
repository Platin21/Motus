// @v 1.4.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include <cstdlib>

// Header
#define MT_VERSION_1_4_0
// Header

template<typename T>
class Unique
{
    T* ptr;
public:
    Unique(T* raw_memory)
    {
        ptr = raw_memory;
    }
    
    T* ref()
    {
        return ptr;
    }
    
    ~Unique()
    {
        free(ptr);
    }
};

template<typename T>
Unique<T> make_unique(i64 count)
{
    return Unique<T>( (T*)calloc(count,sizeof(T)) );
};

template<typename T>
Unique<T> make_unique(std::initializer_list<T> init_list)
{
    T* begin = (T*)calloc(init_list.size(),*init_list.begin());
    for(const T& e : init_list)
    {
        *begin++ = e;
    }
    begin = begin - init_list.size();
    return Unique<T>(begin);
};

