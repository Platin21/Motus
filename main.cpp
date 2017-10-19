#include <iostream>
#include <memory>

//#define MT_SPECIAL_DEF

#include "Types.hpp"
#include "Shared.hpp"
#include "Range.hpp"
#include "Unique.hpp"
#include "Util.hpp"
#include "Convert.hpp"
#include "TextModifier.hpp"
#include "CString.hpp"
#include "File.hpp"

struct vec3{ f32 x,y,z; };

class z
{
public:
    std::unique_ptr<utf8Char> ptr;
};

int main(int argc, const char * argv[])
{
    setlocale(LC_ALL,"de_DE");
    File f = File(UTF8("/Users/arminhamar/Dokumente/C++/core/Data/käse.txt"),OpenForWrite);
    utf8Char txt[] = "lol";
    f.write(3,&txt[0]);

    return 0;
}


