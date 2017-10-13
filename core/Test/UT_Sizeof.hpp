// @u
// @v 1.5.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#include "SizeOf.pch"
#ifdef MT_VERSION_1_5_0
#undef TEST
#define TEST(METHOD) if(!METHOD())

bool UT_decimals_ref_i64()
{
    i64 test_number = 24;
    if(DecimalsOf(test_number) != 2)
    {
        return false;
    }
    
    return true;
}

bool UT_decimals_i64()
{
    if(DecimalsOf(435) != 3)
    {
        return false;
    }
    
    return true;
}

void UT_Sizeof()
{
    TEST(UT_decimals_ref_i64)
    {
        assert(false);
    }
    
    TEST(UT_decimals_i64)
    {
        assert(false);
    }
}
#endif
