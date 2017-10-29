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
public:
    Directory(utf8Char* path)
    {
        dir = opendir(Char(path));
        if(dir == nullptr) return;
    }
    
    bool getFileInDir(Unique<utf8Char>& unique,bool discard = false)
    {
        struct dirent *dent = readdir(dir);
        if(dent == nullptr) return false;
        if(!discard)
        {
            i64 path_size = CStringLenghtOf(UTF8(dent->d_name));
            CStringCopy(unique.ref(),UTF8(dent->d_name),path_size);
        }
        return true;
    }
    
    bool isFileInDir(utf8Char* filename)
    {
      struct dirent *dent = readdir(dir);
      while(dent != nullptr)
      {
          if(CStringCompare(filename,UTF8(dent->d_name))) return true;
          dent = readdir(dir);
      }
      return false;
    }
    
    i64 getCountOfFilesInDir()
    {
        i64 files = 0;
        while(readdir(dir) != nullptr)
        {
            files++;
        }
        rewinddir(dir);
        return files;
    }
    
    void skipFileInDir()
    {
      readdir(dir);
    }
    
    void reset()
    {
        rewinddir(dir);
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
