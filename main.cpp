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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class File
{
    FileHandle   handle;
    i64 file_size;
public:
    File(const utf8Char* path)
    {
      handle = open(Char(path),O_RDONLY);
      if(handle)
      {
          struct stat info;
          fstat(handle,&info);
          file_size = info.st_size;
      }
      else
      {
          file_size = 0;
          handle = 0;
      }
    }
    
    const i64& size() const
    {
        return file_size;
    }
    
    void safelyReadContent(Unique<utf8Char>& to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to.ref(),size());
            to.ref()[size()+1] = '\0';
        }
    }
    
    void safelyReadByte(Unique<utf8Char>& to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to.ref(),1);
            to.ref()[2] = '\0';
            file_size -= 1;
        }
    }
    
    void readContent(Unique<utf8Char>& to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to.ref(),size());
            file_size = 0;
        }
    }
    
    void readByte(Unique<utf8Char>& to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to.ref(),1);
            file_size -= 1;
        }
    }
    
    //
    void safelyReadContent(utf8Char* to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to,size());
            to[size()+1] = '\0';
            file_size = 0;
        }
    }
    
    void safelyReadByte(utf8Char* to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to,1);
            to[2] = '\0';
            file_size -= 1;
        }
    }
    
    void readContent(utf8Char* to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to,size());
            file_size = 0;
        }
    }
    
    void readByte(utf8Char* to)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,to,1);
            file_size -= 1;
        }
    }
    //
    
    ~File()
    {
        close(handle);
    }
};

struct vec3{ f32 x,y,z; };

int main(int argc, const char * argv[])
{
    File f = File(UTF8("/Users/arminhamar/Dokumente/C++/core/Data/käse.txt"));
    
    auto data = make_unique<utf8Char>(f.size()+1);
    f.readContent(data.ref());
    
    return 0;
}


