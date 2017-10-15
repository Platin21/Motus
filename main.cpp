#include <iostream>

//#define MT_SPECIAL_DEF

#include "Types.pch"
#include "Shared.pch"
#include "Range.pch"
#include "Unique.pch"
#include "Util.pch"
#include "Convert.pch"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, const char * argv[])
{
    if(FileHandle file = open("./test.txt",O_RDONLY))
    {
        struct stat file_info;
        fstat(file,&file_info);
        auto file_content = make_unique<char>(file_info.st_size);
        read(file,file_content.ref(),file_info.st_size);
    }
    f32 d = -3434.3452;
    char converted[16];
    decimal_to_cstr(d,&converted[0]);
    
    f32 rd = 0.0f;
    charptr_to_decimal_value(&converted[0],&rd);
    
    return 0;
}


