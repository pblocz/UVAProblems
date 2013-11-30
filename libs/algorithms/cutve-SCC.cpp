
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
using namespace std;

template <typename T> 
T& minl(T& lhs,const T& rhs){ return lhs=std::min(lhs,rhs); }

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

#define NULL_P -1
#define NULL_D -1

/* CV & CE & SCC*/
vvi graph; int counter,rootch; vi depth, low;

/* CV */vector<bool> cv; // Cut vertices are set to true
/* CE */vector<ii> ce; // Add Cut edges here

/* SCC */
vector<bool> instack; // To now if a node is in a SCC or not
vi stack; // Stack of nodes to be proccessed in this path
int numSCC;
set<set<int> > sSCC; // Sets of scc


void cutvescc(int v,int p=NULL_P){
    /* CV&CE&SCC */depth[v]=low[v]= counter++;

    /* SCC */stack.push_back(v);
    /* SCC */instack[v]=true;
    
    
    for(int i=0;i<graph[v].size();i++){
	int ch=graph[v][i];
	if(depth[ch]==NULL_D){ // Not yet visited, tree-edge
	    cutvescc(ch,v); 
	    minl(low[v],low[ch]);
	    /* CV */if(p==NULL_P) ++rootch;
	    /* CV */if(low[ch]>=depth[v]) cv[v]=true; // c-vertex
	    /* CE */if(low[ch]>depth[v]) ce.push_back(ii(ch,v));//c-edge
	} // if it is a back-edge
	/* CV & CE */else if(ch!=p) minl(low[v],depth[ch]); 	
	/* SCC */else if(instack[ch]) minl(low[v],depth[ch]);
    }
    
    /* SCC */
    if(depth[v]==low[v]){ 
	++numSCC; set<int> curset;
	for(;;){ 
	    int aux=stack.back(); stack.pop_back(); 
	    curset.insert(aux); 
	    instack[aux]=false; 
	    if(aux==v) break; 
	}
	sSCC.insert(curset); 
    }
}

int main(){
    /* CV & CE & SCC*/
    int graph_size;
    depth.assign(graph_size,NULL_D); 
    low.assign(graph_size,NULL_D); 
    counter=0;
    
    /* CV */
    cv.assign(graph_size,false);
    for(int i=0; i<graph_size;i++)
	if(depth[i]==NULL_D){
	    rootch=0;
	    cutvescc(i);
	    cv[i]= (rootch>1);
	}

    /* CE */
    ce.clear(); 
    for(int i=0;i<graph_size;i++) if(depth[i]==NULL_D) cutvescc(i);

    
    /* SCC */
    numSCC=0; stack.clear();
    instack.assign(graph_size,false);
    sSCC.clear();  // For storing the component
    for(int i=0;i<graph_size;i++) if(depth[i]==NULL_D) cutvescc(i);

    return 0;
}
