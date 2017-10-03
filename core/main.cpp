#include <cstdlib>
#include <cstdio>
#include <memory>

#include "Shared.hpp"

using i64 = long long;

int main(int argc, const char * argv[])
{
  Shared<int> owner = make_shared<int>({1,2,3,4,5,6});
  int* p = owner.ref();
    
  return 0;
}
