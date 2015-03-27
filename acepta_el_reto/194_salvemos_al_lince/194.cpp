/**
   \author Pablo Cabeza García

   \problem [ProblemNumber]-[ProblemName]
   \time [Time-restriction]

   \brief [Problem-Description]

   \solution [Problem-Solution]
*/

#include <cstdio>
#include <cstring>
#include <ctype.h>


///
///	TYPE DEFINITIONS AND OTHERS
/// 

typedef bool B;
typedef char C;
typedef int I;
typedef unsigned U;
typedef long L;
typedef long unsigned lU;
typedef long long LL;
typedef long long unsigned LU;
typedef double D;
typedef long double LD;

#define V(t) vector(t)
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b>
#define Q(a) queue<a>
#define S(a) stack<a>
#define T iterator

#define MC(a,b) memset((a),0,(b))
#define MS(a,b) memset((a),-1,(b))
#define SZ(a) sizeof((a))



///
///	FAST-IO
/// 

#define gc getchar
#define pc putchar
#define pf printf


template <typename type>
inline type rdunumber(){
    type out; int c;
    while((c=gc())==' ' || c=='\n');
    out=(c>='0' && c<='9')?c-'0':0;
    while((c=gc())>='0' && c<='9') 
	out=(out<<3)+(out<<1)+c-'0';
    ungetc(c,stdin);
    return out;
}
#define rdui rdunumber<unsigned int>
#define rdul rdunumber<unsigned long>
#define rdull rdunumber<unsigned long long>


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


#define OUTLEN 60000 // after some tests, big enough for whole output
char opool[OUTLEN], *oidx = opool, * const oend = opool + OUTLEN;

#define INCIDX(idx,buf) if(++(idx) == ((char*)(buf))+sizeof(buf)) { \
	fread((buf),1,sizeof(buf),stdin); (idx)=(buf); } 


///
///	PROBLEM SOLUTION
/// 

char ibuf[100000], *idx=ibuf+1, // to skip the first \n
    * const end = ibuf + sizeof(ibuf);


int main(int argc,char *argv[]){
    int cases = rdui(); fread(ibuf,1,sizeof(ibuf), stdin);

    while(cases--) {
	unsigned bridges = 0, bstripe = 0;

	while(*idx!='\n') {
	    if(*idx == '.') ++bstripe;
	    else if(bstripe != 0) ++bstripe;

	    if(bstripe == 3) { ++bridges; bstripe = 0; }
	    if(++idx == end) { fread(ibuf,1,sizeof(ibuf),stdin); idx=ibuf; }
	}
	INCIDX(idx,ibuf);
	//if(++idx == end) { fread(ibuf,1,sizeof(ibuf),stdin); idx=ibuf; }
	if(bstripe) ++bridges;

	oidx += wrun(oidx,bridges); *oidx++ = '\n';
    }
    wrs(opool, oidx - opool);

    return 0;
}
