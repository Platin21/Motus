#include <iostream>

//#define MT_SPECIAL_DEF
//@CORE
#include "Types.hpp"
#include "Shared.hpp"
#include "Range.hpp"
#include "Unique.hpp"
#include "Util.hpp"
#include "CString.hpp"
//@BASE
#include "Convert.hpp"
#include "TextModifier.hpp"
#include "File.hpp"
#include "Color.hpp"
#include "Directory.hpp"

int main(int argc, const char * argv[])
{
    
    File f = File(UTF8("/Users/arminhamar/Dokumente/C++/core/Data/lese.txt"),OpenForWrite);
    utf8Char *t = UTF8("vec3(1.0,2.0,3.0)\n");
    
    f.write(t,CStringLenghtOf(t));
    
    Directory d = Directory(UTF8("/Users/arminhamar/Dokumente/C++/core/Data/"));
    
    Unique<utf8Char> filename = make_unique<utf8Char>(30);
    d.getFileInDir(filename);
    printf("%s",filename.ref());
    
    File f2 = File(filename.ref(),d.getDirHandle(),OpenForRead);
    auto content = make_unique<utf8Char>(f2.size());
    f2.safelyReadContent(content);
    
    printf("\n%s\n",content.ref());
    
    Color c = BRGA(234,253,345,0xFA);
    
    return 0;
}


