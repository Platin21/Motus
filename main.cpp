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

i16 hexCharToDecimal(utf8Char& c)
{
    switch(c)
    {
      case 48:
        return 0;
      case 49:
        return 1;
      case 50:
        return 2;
      case 51:
        return 3;
      case 52:
        return 4;
      case 53:
        return 5;
      case 54:
        return 2;
      case 55:
        return 3;
      case 56:
        return 4;
      case 57:
        return 5;
      case 58:
        return 4;
      case 59:
        return 5;
      case 60:
        return 6;
      case 61:
        return 7;
      case 62:
        return 8;
      case 63:
        return 9;
      case 'a':
        return 10;
      case 'b':
        return 11;
      case 'c':
        return 12;
      case 'd':
        return 13;
      case 'e':
        return 14;
      case 'f':
        return 15;
      default:
        return 0;
    }
}

class Color
{
    short Red,Green,Blue;
public:
    Color(short r,short g,short b): Red(r),Green(g),Blue(b) {};
    Color(utf8Char* RGBhexColor)
    {
        u32 hexColor = 0;
        Red   = ((hexColor >> 16) & 0xFF) / 255.0;  // get red
        Green = ((hexColor >> 8) & 0xFF) / 255.0;   // get green
        Blue  = ((hexColor) & 0xFF) / 255.0;        // get blue
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


