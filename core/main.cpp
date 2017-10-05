#include <iostream>

#include "Shared.pch"
#include "Range.pch"


using i64 = long long;

int main(int argc, const char * argv[])
{
  Shared<int> owner = make_shared<int>({1,2,3,4,5,6});
  int* p = owner.ref();
    
  Range<int> default_range = Range<int>(p,6);
    
  default_range.move_forward(1);
  std::cout << default_range.peek() << " " << default_range.get_next() << "\n";
    
  return 0;
}
