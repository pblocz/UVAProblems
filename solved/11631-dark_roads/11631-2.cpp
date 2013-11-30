// In krukal algorithm, add the edges that aren't added to the tree

#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

typedef pair<unsigned,unsigned> ii;
typedef pair<unsigned,ii> edge;

template <typename type,int bufsize>
inline type rdbunumber(){
    static char buffer[bufsize]; static char* beg=buffer,* end=buffer;
    type out=0;
    if(beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    while(*beg==' ' || *beg=='\n')
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    
    while(*beg>='0' && *beg<='9'){
	out=(out<<3)+(out<<1)+*beg-'0';
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    }
    return out;
}
#define BSIZE 8192
#define rdui rdbunumber<unsigned int,BSIZE>



typedef unsigned type;
struct UFDS{
    UFDS(unsigned n=0){}
    void join(unsigned i,unsigned j){ v[find(i)]=find(j); }
    unsigned find(unsigned i){ return (v[i]==-1)? i : v[i]=find(v[i]); }
    void reset(unsigned n){ memset(v,-1,sizeof(type)*n); } // DUDA que es más rápido, esto
							       // o memcopy de uno ya preparado
    static unsigned v[200000];
};
unsigned UFDS::v[200000];


edge edges[200000];
int M,N, savings;
UFDS gr;

int main(){
    while((M=rdui()) && (N=rdui())){
	gr.reset(M); savings=0;
	for(int i=0;i<N; ++i) edges[i]=edge(rdui(),ii(rdui(),rdui()));
	sort(edges,edges+N);				  
	for(int i=0;i<N; ++i){ unsigned f=edges[i].second.first, s=edges[i].second.second;
	    if( gr.find(f) == gr.find(s)) savings+=edges[i].first;
	    else gr.join(f,s);
	}
	printf("%i\n", savings);
    }
    return 0;
}

/* what is faster?

   sizeof(type)*n
   
   (int)((type*)0 + n)
*/
