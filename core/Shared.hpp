// @v 1.1.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include <cstdlib>
#include <initializer_list>
#include "Types.hpp"

// Header
#define MT_VERSION_1_1_0
// Header

template<typename T>
class Shared
{
private:
    T* ptr;
    
    template<typename TX>
    struct Shared_Info
    {
        TX* origin;
        i64 refs;
        i64 size;
    };
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
    
    Shared_Info<T>* getTypInfo() const
    {
        return type_info;
    }
    
    Shared(void* raw_memory)
    {
        type_info = (Shared_Info<T>*)malloc(sizeof(type_info));
        type_info->origin = (T*)raw_memory;
        type_info->refs = 0;
        type_info->size = 0;
        ptr = type_info->origin;
    }
    
    Shared(void* raw_memory,i64& size)
    {
        type_info = (Shared_Info<T>*)malloc(sizeof(type_info));
        type_info->origin = (T*)raw_memory;
        type_info->refs = 0;
        type_info->size = size;
        ptr = type_info->origin;
    }
    
    Shared(void* raw_memory,i64&& size)
    {
        type_info = (Shared_Info<T>*)malloc(sizeof(type_info));
        type_info->origin = (T*)raw_memory;
        type_info->refs = 0;
        type_info->size = size;
        ptr = type_info->origin;
    }
    
    Shared(const Shared<T>& shr)
    {
        this->type_info->origin = shr.ref();
        this->type_info = shr.getTypInfo();
        this->type_info->refs   += 1;
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
    return Shared<T>( malloc(sizeof(T)*count),count);
}

template<typename T>
Shared<T> make_shared(std::initializer_list<T> init_list)
{
    T* begin = (T*)malloc(sizeof(init_list.begin()) * init_list.size());
    for(const T& e : init_list)
    {
        *begin++ = e;
    }
    begin = begin - init_list.size();
    i64 size = init_list.size();
    return Shared<T>(begin,size);
};
