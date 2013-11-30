/**
   \author Pablo Cabeza García

   Problem
   Time

   [Description]

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
//deque,list,functional,numeric,limits


using namespace std;

#ifdef ONLINE_JUDGE
	#define dout if(false) cout
	int dummy(...){return EOF;}
	#define dprintf dummy
#else
	#define dout cout
	#define dprintf printf
#endif

typedef int t;
typedef pair<t,t> ptt;
typedef vector<t> vt;
typedef vector<ptt> vptt;
typedef vector<vt> vvt;
typedef vector<vptt> vvptt;

// FOR-LOOP SHORTCUTS
#define FOR(var,inval,cond,incr) for(int (var)=(inval);(cond);(incr))
#define SEQCOMP(var,inval,lim,incr) FOR((var),(inval),(var)<(lim),(incr))
#define SEQLIN(var,inval,lim) SEQCOMP((var),(inval),(lim),++(var))
#define SEQ(var,lim) SEQLIN((var),0,(lim))



int main(int argc,char *argv[]){
    double a1,a2,b1,b2,c1,c2;
    while(scanf("%lf%lf%lf%lf%lf%lf",&a1,&a2,&b1,&b2,&c1,&c2)!=EOF){
	complex<double> a(a1,a2),b(b1,b2),c(c1,c2);
	
	long double l1=abs(a-b),l2=abs(b-c),l3=abs(c-a);
	long double s=(l1+l2+l3)/2;
	// printf("(%f,%f) ",a1,a2);
	// printf("(%f,%f) ",b1,b2);
	// printf("(%f,%f) ",c1,c2);
	// printf("%Lf ",l1);
	// printf("%Lf ",l2);
	// printf("%Lf ",l3);
	printf("%.2Lf\n",
	       acos(-1)*(l1*l2*l3)/(2*sqrt(s*(s-l1)*(s-l2)*(s-l3))));
	// printf("%.2f\n",
	//        2*acos(-1)*l1*l2*l3/
	//        ( (double)4*sqrt(s*(a+b-s)*(a+c-s)*(b+c-s)) )
	//        );
    }
    return 0;
}
