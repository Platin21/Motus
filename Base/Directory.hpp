// @v 1.11.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"
#include "Unique.hpp"

// Header
#define MT_VERSION_1_11_0
// Header

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
