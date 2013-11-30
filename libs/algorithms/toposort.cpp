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

typedef queue<int> container;
#define INSERT(c,i) (c).push(i)
#define TOP(c) (c).front()
#define POP(c) (c).pop()
#define EMPTY(c) (c).empty()

typedef set<int> result;
#define RINSERT(c,i) (c).insert((i))

result& toposort(container &cont, result &r){
    int indeg[GR_S]={0};
    
    SEQ(i,GR_S) FADY(ch,i) indeg[ch]++;
    SEQ(i,GR_S) if(indeg[i]==0) INSERT(cont,i);
    
    while(!EMPTY(container)){
	int t=TOP(cont); POP(cont);
	FADY(ch,t) if(--indeg[ch]==0) INSERT(ch);
	RINSERT(r,t);
    }
    
    return r;
}
