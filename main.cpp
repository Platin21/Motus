#include <iostream>

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

#include <dirent.h>

class Directory
{
private:
    DIR *dir;
    struct dirent *dent;
public:
    Directory(utf8Char* path)
    {
        dir = opendir(Char(path));
        readdir(dir);
        readdir(dir);
        
        if(dir == nullptr) return;
    }
    
    void getFileInDir(Unique<utf8Char>& unique)
    {
     dent = readdir(dir);
     if(dent == nullptr) return;
     i64 path_size = CStringLenghtOf(UTF8(dent->d_name));
     CStringCopy(unique.ref(),UTF8(dent->d_name),path_size);
    }
    
    DirHandle getDirHandle()
    {
        return dirfd(dir);
    }
    
    ~Directory()
    {
        if(dir != nullptr) closedir(dir);
    }
};

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
    return 0;
}


