#include <iostream>

#include "Types.pch"
#include "Shared.pch"
#include "Range.pch"
#include "Unique.pch"
#include "SizeOf.pch"

int main(int argc, const char * argv[])
{
    i64 number = 0;
    printf("Typein number to count decimals:");
    scanf("%lld",&number);
    i64 count = CountOfDecimalCharsIn_i64(number);
    printf("%lld\n",count);
    
    return 0;
}
