// @u
// @v 1.2.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#include "Range.pch"
#ifdef MT_VERSION_1_2_0
#undef TEST
#define TEST(METHOD) if(!METHOD())

// Add the Other tests
/*
 inline Range<T> subrange(i64 offset_begin,i64 offset_end)
 inline const T& get_next()
 inline const T& get()
 inline const T& get_at(i64&& position)
 inline const T& get_at(i64& position)
 inline void move_forward(i64&& by_elements)
 inline void move_forward(i64& by_elements)
 inline bool is_elment_valid_at(i64 position)
*/

bool UT_Range_init()
{
    int it_rng[5]{1};
    auto rng = Range<int>(&it_rng[0],5);
    return true;
}

bool UT_Range_peek()
{
    int it_rng[] = {1,2,3,4,5};
    auto rng = Range<int>(&it_rng[0],5);
    if(rng.peek() == 2)
    {
        return true;
    };
    
    return false;
}

void UT_Range()
{
    TEST(UT_Range_init)
    {
        assert(false);
    }
    
    TEST(UT_Range_peek)
    {
        assert(false);
    }
}

#endif
