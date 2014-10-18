/**
   \author Pablo Cabeza García

   \problem [ProblemNumber]-[ProblemName]
   \time [Time-restriction]

   \brief [Problem-Description]

   \solution [Problem-Solution]
*/

#include <climits>
#include <cstdio>

#include <algorithm>
using namespace std;

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
#define sf scanf

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

void rdstr(char* buf){
    int c;
    while((c=gc())==' ' || c=='\n');
    do{ *buf++=c; } while(!((c=gc())==' ' || c=='\n')); 
    ungetc(c,stdin);
    *buf++='\0';
}

///
///	PROBLEM SOLUTION
/// 

enum { SIZE=10000};

C names[SIZE][21];
P(lU,P(lU,U)) lb[SIZE],ub[SIZE];

int main(int argc,char *argv[]){
    I cases=rdui();
    while(cases--){
	I N=rdui();
	SEQ(i,0,N){
	    rdstr(names[i]);//scanf("%s",names[i]);
	    lU l=rdul(),u=rdul();
	    lb[i]=P(lU,P(lU,U)) (l,P(lU,U)(u,i)); 
	    ub[i]=P(lU,P(lU,U)) (u,P(lU,U)(l,i));
	}
	sort(lb,lb+N);
	sort(ub,ub+N);
	
	I q=rdui();
	while(q--){
	    lU  p=rdul();		
	    P(lU,P(lU,U)) *upper=
		upper_bound(lb,lb+N,P(lU,P(lU,U))
			    (p,P(lU,U)(UINT_MAX,UINT_MAX))),
		*lower=lower_bound(ub,ub+N,
				   P(lU,P(lU,U))(p,P(lU,U)(0,0)));
	    if(N-(lower-ub)-((lb+N)-upper) == 1)
		if(lower-ub <= (lb+N)-upper){ //search in lb		    
		    for(upper--;upper!=lb-1;upper--)
			if(upper->second.first>=p) break;
		    puts(names[upper->second.second]);
		}else{ // search in ub
		    for(;lower!=ub+N;lower++)
			if(lower->second.first<=p) break;
		    puts(names[lower->second.second]);
		}
	    else puts("UNDETERMINED");
	}
	if(cases) pc('\n');
    }
    return 0;
}
