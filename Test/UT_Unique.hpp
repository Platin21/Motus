// @u
// @v 1.4.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#include <cstdlib>
#include "Unique.hpp"
#ifdef MT_VERSION_1_4_0

#undef TEST
#define TEST(METHOD) if(!METHOD())

bool UT_unique_basic_init()
{
    auto uniq = Unique<int>( (int*)malloc(sizeof(int)*30));
    return true;
}

bool UT_unique_get_refrence()
{
    auto uniq = Unique<int>( (int*)malloc(sizeof(int)*30));
    int* u = uniq.ref();
    if(!u)
    {
        return false;
    }
    
    return true;
}

void UT_Unique()
{
    TEST(UT_unique_basic_init)
    {
        assert(false);
    }
    
    TEST(UT_unique_get_refrence)
    {
        assert(false);
    }
}

#endif
