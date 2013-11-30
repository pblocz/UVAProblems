#include <cstdlib>

template <class T>
struct darray{
    inline darray() :s_(0) , c_(16) , ptr_( malloc(sizeof(T)*16) ) {}

    inline T* duplicate(){ return realloc(ptr,c_*=2); }
    
    inline T& operator[](int i){ return ptr[i]; }

    int c_;
    int s_;
    T *ptr_;
};

