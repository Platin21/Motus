//
//  Shared.hpp
//  core
//
//  Created by Armin Hamar on 03.10.17.
//  Copyright © 2017 Armin Hamar. All rights reserved.
//
#pragma once
#include <cstdlib>
using i64 = long long;

template<typename T>
struct Shared_Info
{
    T* origin;
    i64 refs;
};

template<typename T>
class Shared
{
private:
    T* ptr;
    Shared_Info<T>* type_info;
public:
    T* ref() const
    {
        return ptr;
    }
    
    i64 getRefCount() const
    {
        return type_info->refs;
    }
    
    Shared(T* raw_memory)
    {
        type_info = (Shared_Info<T>*)calloc(1,sizeof(type_info));
        type_info->origin = raw_memory;
        ptr = type_info->origin;
    }
    
    Shared(Shared<T>&& shared)
    {
        type_info = shared.type_info;
        type_info->refs += 1;
        ptr = type_info->origin;
    }
    
    ~Shared()
    {
        if(type_info->refs <= 0)
        {
            free(ptr);
        }
        else
        {
            type_info->refs -= 1;
        }
    }
};

template<typename T>
Shared<T> make_shared(i64 count)
{
    return Shared<T>( (T*)calloc(count,sizeof(T)) );
}

template<typename T>
Shared<T> make_shared(std::initializer_list<T> init_list)
{
    T* begin = (T*)calloc(init_list.size(),*init_list.begin());
    for(const T& e : init_list)
    {
        *begin++ = e;
    }
    begin = begin - init_list.size();
    return Shared<T>(begin);
};
