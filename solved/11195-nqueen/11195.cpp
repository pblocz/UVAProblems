/**
   \author Pablo Cabeza García

   \problem 11195-Another n-Queen Problem
   \time 5s

   \brief Count the solutions of the n-queen problem having the
   restriction of forbidden cells, with 3<N<15 (map sol)

   \solution Very straightforward solution of the n-queen problem
   having 3 bool arrays of used columns, diagonals and
   anti-diagonals, doing backtracking over the rows.

   An improvement to it can be to have pre-computed the solution to
   standard n-queen problem and compute the number of those solutions
   that aren't plausible with the given boards.
*/

#include <cstdio>
#include <cstring>

///
///	TYPE DEFINITIONS
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

// for(I i=l:k){ ... }
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

U M,N,Co; B t[15][15],d[30],b[30],c[15];
I nq(I i=0){  if(i==M) SEQ(j,0,N) Co+=!(c[j]|b[i+j]|d[M-i+j]|t[i][j]);
    else SEQ(j,0,N) if(!(c[j]|b[i+j]|d[M-i+j]|t[i][j])){
	    c[j]=b[i+j]=d[M-i+j]=1; nq(i+1); c[j]=b[i+j]=d[M-i+j]=0; } }
main(I ac,C *av[]){ U ca=0;
    while(N=rdui()){ gc(); MC(d,SZ(d)); MC(c,SZ(c)); MC(b,SZ(b));
	BISEQ(i,j,N)t[i][j]=gc()=='*',j==N-1?gc():0;
	Co=0; M=N-1; nq(); pf("Case %u: %i\n",++ca,Co);
    }
    return 0;
}
