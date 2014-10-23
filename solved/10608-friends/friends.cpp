/**
   \author Pablo Cabeza García

   \problem 10608-Friends
   \time 3s

   \brief The problem can be translated to: given a bidirectional
   	  graph, find the size of the biggest connected component.

   \solution An efficient and simple way to solve it is to use an
             Union Find Disjoint Set (UFDS) to compute each connected
             components and at the same time, when doing a
             *UFDS.join()*, we update the size of the connected
             component of the element representing the
             component. Afterwards we just need to compute the maximum
             of the sizes of components since it will be the biggest
             connected component.
*/

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <complex>
#include <utility>
#include <limits>
#include <functional>
using namespace std;


///
///	DEBUGGING INFORMATION
/// 


#ifdef ONLINE_JUDGE
	#define dout if(false) cout
	int dprintf(...){return EOF;}
#else
	#define dout cout
	#define dprintf printf
#endif


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
///	SEQ-Definitions
/// 

// Equivalent to: for(I i=0...) for(I j=0...){  }
// To do something after every i loop use if(j==k-1){ ... }
#define BISEQ(i,j,k) for(I (i)=0,(j)=0;(i)<(k);(i)+=0==((j)=++(j)%(k)))

// does for loop in range [l,k) (if l>k it does the reverse)
#define SEQ(i,l,k) for(I (i)=(l),_i_=(k)-(l)>=0?1:-1;(i)!=(k);(i)+=_i_)


///
///	FAST-IO
/// 

#define gc getchar
#define pc putchar
#define pf printf

template <typename type>
inline type rdnumber(){
    type out; int c,sign;
    while((c=gc())==' ' || c=='\n');
    out=(c=='-')?(sign=-1,0):(sign=1,c-'0');
    while((c=gc())>='0' && c<='9') 
	out=(out<<3)+(out<<1)+c-'0';
    ungetc(c,stdin);
    return out*sign;
}
#define rdi rdnumber<int>
#define rdl rdnumber<long>
#define rdll rdnumber<long>


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


///
///	PROBLEM SOLUTION
/// 


struct UFDS {
    void join(int i,int j){ 
	int t = find(i);
	v[t]=find(j); 

	// not sure of the representant, update both
	if(v[t]!=t) { s[t]+=s[v[t]]; s[v[t]] = s[t];}

    }
    int find(int i){ return (v[i]==-1 || v[i]==i)? i : v[i]=find(v[i]); }
    void reset(unsigned n){
	memset(v,-1,n*sizeof(unsigned)); 
	SEQ(i,0,n) s[i]=1;
    }
    int v[30000];
    unsigned s[30000]; // sizes
};
UFDS ufds; // global ufds

int main(int argc,char *argv[]){
    unsigned C = rdui(); bool f=true;
    while(C--) {
	unsigned N=rdui(), M=rdui();
	ufds.reset(N);

	for(unsigned i=1;i<=M;++i) ufds.join(rdui()-1,rdui()-1);
	pf("%u\n",*max_element(ufds.s,ufds.s+N));
    }
    return 0;
}
