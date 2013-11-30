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

//GRAPH SHORTCUTS - Marco's trick
//* C style graph
#define GR_S 100 // Graph size
#define CH_S 10  // Child's size

t graph[GR_S][CH_S];
int sgraph[GR_S];

#define LSIZE(i,gr) s##gr[i]
#define DJOIN(i,j,gr) (gr)[(i)][s##gr[(i)]++]=(j)
#define BJOIN(i,j,gr) { DJOIN(i,j,gr); DJOIN(j,i,gr); }
#define RESET(gr,size,val) memset(s##gr,(val),(size)*sizeof(int))
/*/ //C++ style graph 
vvt graph;
#define LSIZE(i,gr) (gr)[(i)].size()
#define DJOIN(i,j,gr) (gr)[(i)].push_back((j))
#define BJOIN(i,j,gr) { DJOIN(i,j,gr); DJOIN(j,i,gr); }
#define RESETV(gr,size,val) {(gr).clear(); (gr).resize((size),(val));}
#define RESET(gr,size) {(gr).clear; (gr).resize((size),vt());}
// C++ style graph */

#define FADY(ch,i,gr) SEQ(INDEX_ADY,LSIZE(i,gr)) \
		      for(int BCOND=1,(ch)=gr[i][INDX];BCOND;BCOND=0)



// BEGIN PROBLEM SOLUTION


int main(int argc,char *argv[]){

    return 0;
}


// END PROBLEM SOLUTION
