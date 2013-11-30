
#include <vector>
#include <iterator>

struct iter :std::iterator<std::input_iterator_tag,int>{
    iter(int i=0) :n(i){}
    inline iter& operator++(){ ++n; return *this; }
    inline iter operator++(int){ return iter(n++); }
    inline bool operator==(const iter& it) const{ return it.n==n;}
    inline bool operator!=(const iter& it) const{ return it.n!=n;}
    inline int operator*() const{ return n; }
    int n;
};

struct UFDS{
    UFDS(int n){ reset(n); }
    void join(int i,int j){ v[find(i)]=find(j); }
    int find(int i){ return (v[i]==-1)? i : v[i]=find(v[i]); }
    void reset(int n){ v.assign(n,-1); }
    std::vector<int> v;
};

int main(int argc,char* argv[]){
    int i=argv[0][0];
    UFDS set(i);
    return 0;
}
