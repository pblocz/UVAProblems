/**
   \author Pablo Cabeza García

   \problem [ProblemNumber]-[ProblemName]
   \time [Time-restriction

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
///	TYPE DEFINITIONS
/// 

typedef int I;
typedef long L;
typedef long long LL;
typedef double D;
typedef long double LD;

#define v(t) vector((t))
#define p(a,b) pair<(a),(b)>
#define m(a,b) map<(a),(b)>
#define q(a) queue<(a)>
#define s(a) s<(a)>
#define IT iterator


///
///	FAST-IO
/// 

template <typename type>
inline type rdnumber(){
    type out; int c,sign;
    while((c=getc(stdin))==' ' || c=='\n');
    out=(c=='-')?(sign=-1,0):(sign=1,c-'0');
    while((c=getc(stdin))>='0' && c<='9') 
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
    while((c=getc(stdin))==' ' || c=='\n');
    out=(c>='0' && c<='9')?c-'0':0;
    while((c=getc(stdin))>='0' && c<='9') 
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
