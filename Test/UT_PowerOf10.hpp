// @u
// @v 1.6.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#include "Util.hpp"
#ifdef MT_VERSION_1_5_0
#undef TEST
#define TEST(METHOD) if(!METHOD())

bool UT_PowerTest()
{
    if(powerOf10(7) != 10000000)
    {
        return false;
    }
    return true;
}

void UT_PowerOf10()
{
    TEST(UT_PowerTest)
    {
        assert(false);
    }
}


#endif



