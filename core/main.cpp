#include <cstdlib>
#include <cstdio>
#include <memory>

using i64 = long long;

template<typename T>
class Shared
{
private:
    T* ptr;
    i64* refs;
public:
    T* ref() const
    {
        return ptr;
    }
    
    i64 getRefCount() const
    {
        return *refs;
    }
    
    Shared(T* raw_memory)
    {
        refs = (i64*)calloc(1,sizeof(i64));
        ptr = raw_memory;
    }
    
    Shared(Shared<T>&& shared)
    {
        refs = shared.refs;
        *refs += 1;
        ptr = shared.ptr;
    }
    
    ~Shared()
    {
        if(*refs <= 0)
        {
            free(ptr);
        }
        else
        {
            *refs -= 1;
        }
    }
};

template<typename T>
Shared<T> make_shared(i64 count)
{
    return Shared<T>( (T*)calloc(count,sizeof(T)) );
}


int main(int argc, const char * argv[])
{
 Shared<int> owner = make_shared<int>(30);
 int* p = owner.ref();
    
 printf("%lu",sizeof(owner));
    
  return 0;
}
