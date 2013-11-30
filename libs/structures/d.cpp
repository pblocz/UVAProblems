#include <cstdlib>
template <class T>
struct darray{
    inline darray() 
	:s_(0) , 
	 c_(16) , 
	 ptr_( reinterpret_cast<int*>(malloc(sizeof(T)*16)) ) {}

    inline void duplicate(){ realloc(ptr_,c_*=2); }
    
    inline T& operator[](int i){ return ptr_[i]; }

    int c_;
    int s_;
    T *ptr_;
};

int main(){
    darray<int> array;
    for(int i=0;i<10000000;i++){
	if(i==array.c_) array.duplicate();
	array[i]=i;
    }
    return 0;
}
