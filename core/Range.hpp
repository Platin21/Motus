//
//  Range.hpp
//  core
//
//  Created by Armin Hamar on 04.10.17.
//  Copyright © 2017 Armin Hamar. All rights reserved.
//
#pragma once
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
    Range_info* info;
public:
    Range(T* begin,i64 size)
    {
        
    }
};
