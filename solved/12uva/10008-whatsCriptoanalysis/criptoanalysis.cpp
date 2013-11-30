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

int counter[258];

bool order(char a,char b){
    return (counter[a]!=counter[b])?counter[a]>counter[b]:a<b;
}

int main(int argc,char *argv[]){
    int lines;
    scanf("%i",&lines); getchar();
    memset(counter+'A',0,sizeof(int)*('Z'-'A'+1));

    char let['Z'-'A'+1];
    for(int i=0;i<'Z'-'A'+1;i++) let[i]='A'+i;


    while(lines--){
	int c;
	while((c=getchar())!='\n') ++counter[toupper(c)];
    }
    sort(let,let+('Z'-'A'+1),order);
    for(int i=0;i<'Z'-'A'+1;++i){
	if(counter[let[i]]==0) break;
	printf("%c %i\n",let[i],counter[let[i]]);
    }
    
    return 0;
}
