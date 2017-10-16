#include <iostream>

//#define MT_SPECIAL_DEF

#include "Types.pch"
#include "Shared.pch"
#include "Range.pch"
#include "Unique.pch"
#include "Util.pch"
#include "Convert.pch"
#include "TextModifier.pch"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class File
{
    FileHandle   handle;
    i64 file_size;
public:
    File(const Char* path)
    {
      handle = open(path,O_RDONLY);
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
    
    const i64 size()
    {
        return file_size;
    }
    
    void readAll(Unique<char>& content)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,content.ref(),file_size);
            content.ref()[file_size+1] = '\0';
        }
    }
    
    void readByte(Unique<char>& content)
    {
        if(handle != 0 && file_size != 0)
        {
            read(handle,content.ref(),1);
            content.ref()[2] = '\0';
        }
    }
    
    ~File()
    {
        close(handle);
    }
};

struct vec3{ f32 x,y,z; };

int main(int argc, const char * argv[])
{
    File f = File("/Users/arminhamar/Dokumente/C++/core/Data/test.txt");
    
    auto data = make_unique<char>(f.size()+1);
    f.readAll(data);
    
    return 0;
}


