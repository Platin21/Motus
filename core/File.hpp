// @v 1.9.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"

// Header
#define MT_VERSION_1_9_0
// Header

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class File
{
    FileHandle   handle;
    i64 file_size;
public:
    File()
    {
        file_size = 0;
        handle = 0;
    }
    
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
