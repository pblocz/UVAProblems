/**
   \author Pablo Cabeza García

   \problem [ProblemNumber]-[ProblemName]
   \time [Time-restriction]

   \brief [Problem-Description]

   \solution [Problem-Solution]
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

#define V(t) vector((t))
#define P(a,b) pair<(a),(b)>
#define M(a,b) map<(a),(b)>
#define Q(a) queue<(a)>
#define S(a) s<(a)>
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



int main(int argc,char *argv[]){
    return 0;
}
