// @u
// @v 1.1.0
// @n Motus_Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#include "Shared.pch"
#include <cstdlib>
#include <cassert>
#ifdef MT_VERSION_1_1_0
#undef TEST
#define TEST(METHOD) if(!METHOD())

bool UT_shared_basic_init()
{
    auto i = Shared<int>( (int*)malloc(sizeof(int) * 20) );
    return true;
}

bool UT_shared_get_refrence()
{
   auto i = Shared<int>(  (int*)malloc(sizeof(int) * 20) );
   if(i.ref())
   {
       return true;
   }
    
   return false;
}

bool UT_make_shared_no_list()
{
    auto e = make_shared<int>(20);
    if(!e.ref())
    {
        return false;
    }
    
    return true;
}

bool UT_make_shared_list()
{
    auto e = make_shared<int>({1,2,3,4,5,6,7,8,9,10});
    if(*e.ref() == 1)
    {
        return true;
    }
    
    return false;
}

bool UT_shared_test_refs_part1(Shared<int> i)
{
    if(i.getRefCount() >= 0) return true;
    
    return false;
}

bool UT_shared_test_refs()
{
  auto e = make_shared<int>(20);
  
  return UT_shared_test_refs_part1(e);
}

void UT_Shared()
{
    TEST(UT_shared_basic_init)
    {
        assert(false);
    }
    
    TEST(UT_shared_get_refrence)
    {
        assert(false);
    }
    
    TEST(UT_make_shared_no_list)
    {
        assert(false);
    }
    
    TEST(UT_make_shared_list)
    {
        assert(false);
    }
    
    TEST(UT_shared_test_refs)
    {
        assert(false);
    }
}

#endif
