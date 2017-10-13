#include <iostream>

#include "Types.pch"
#include "Shared.pch"
#include "Range.pch"
#include "Unique.pch"
#include "SizeOf.pch"

int main(int argc, const char * argv[])
{
    i64 number = 0;
    printf("Type in number to count decimals:");
    scanf("%lld",&number);
    i16 count = DecimalsOf<i16>(number);
    printf("%d\n",count);
    
    return 0;
}
