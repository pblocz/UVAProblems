/**
   \author Pablo Cabeza García

   \problem 234-Carreras de coches
   \time 2-5 sec

   \brief Encontrar el max num de parejas que suman >= v

   \solution ordenas los números y vas comprobando por los extremos,
   ya que si el más pequeño no *encaja* con el mayor, entonces no
   encaja con ninguno.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;



///
///	FAST-IO
/// 

#define gc getchar
#define pc putchar
#define pf printf

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
#define BSIZE 1 << 15
#define rdui rdbunumber<unsigned int,BSIZE>
#define rdul rdbunumber<unsigned long,BSIZE>
#define rdull rdbunumber<unsigned long long,BSIZE>


#define wrs(str,size) fwrite((str),1,(size),stdout)
#define wrcs(str) fwrite((str),1,sizeof((str))-1,stdout)
#define wrcsb(str) wrcs(str),putchar('\n')

template <typename T>
int wrun(char* cstr,T n){
    static char str[128]={'\0'},*e=str+127;
    char *b=e;
    do{
	*--b=n%10+'0';
	n/=10;
    } while(n!=0);
    memcpy(cstr,b,e-b);
    return e-b;
}




///
///	PROBLEM SOLUTION
/// 

#define LENGTH 100000
#define OUTLEN 20000 // for one go, minimum length is 100000 -> many cases
#define OUTOFFSET 10

int pool[LENGTH], *pend, *pidx;
char opool[OUTLEN], *oidx = opool, *oend = opool + OUTLEN;


int main() {
    int cases = rdui();
	
    while(cases--) {
	unsigned pilas = rdui(), v = rdui(), stacks = 0;
	// printf("%u %u", pilas, v);
	for(pend = (pidx=pool) + pilas; pidx != pend; ++pidx) *pidx = rdui();

	sort(pool,pend);

	pidx=pool; --pend;
	while(pidx < pend) {
	    if(*pend+*pidx >= v){ ++stacks; --pend; }
	    ++pidx;
	}
	
	if(oidx+OUTOFFSET >= oend){wrs(opool, oidx-opool); oidx=opool;}
	oidx += wrun(oidx,stacks); *oidx++ = '\n';
    }
    wrs(opool, oidx - opool);
}
