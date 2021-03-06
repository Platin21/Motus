// @v 1.2.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"

// Header
#define MT_VERSION_1_2_0
// Header

template <typename T>
class Range {
    // @s represents the range in memmory
    template<typename TX>
    struct Range_info
    {
        i64 size;
        TX *begin;
    };
    Range_info<T> info;
public:
    Range(T* begin,i64&& size)
    {
        info = Range_info<T>();
        info.begin = begin;
        info.size = size;
    }
    
    Range(T* begin,i64& size)
    {
        info = Range_info<T>();
        info.begin = begin;
        info.size = size;
    }
    
    Range(T* begin,T* end)
    {
        info = Range_info<T>();
        info.begin = begin;
        info.size = (i64)(end - begin);
    }
    
    inline bool is_elment_valid_at(i64 position)
    {
        if(!( (info.begin + position) >= (info.begin + info.size) )) return true;
        return false;
    }
    
    //@todo rethink
    inline void move_forward(i64& by_elements)
    {
        if(is_elment_valid_at(by_elements))
        {
            info.begin += by_elements;
            info.size  -= by_elements;
        }
    }
    
    //@todo rethink
    inline void move_forward(i64&& by_elements)
    {
        if(is_elment_valid_at(by_elements))
        {
            info.begin += by_elements;
            info.size  -= by_elements;
        }
    }
    
    inline const T& get_at(i64& position)
    {
        return *(info.begin + position);
    }
    
    inline const T& get_at(i64&& position)
    {
        return *(info.begin + position);
    }
    
    inline const T& get()
    {
        return *info.begin;
    }
    
    inline const T& get_next()
    {
        move_forward(1);
        return get();
    }
    
    inline Range<T> subrange(i64 offset_begin = 0,i64 offset_end = 0)
    {
        if(offset_end >= info.size)
            return Range<T>((info.begin+offset_begin),info.size);
        
        return Range<T>((info.begin+offset_begin),info.size - offset_end);
    }
    
    inline const T& peek()
    {
        if(is_elment_valid_at(1))
            return get_at(1);
        
        return get();
    }
    
    T* begin()
    {
        return info.begin;
    }
    
    T* end()
    {
        return info.begin + info.size;
    }
};
