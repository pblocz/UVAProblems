#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

template <typename T> 
T& minl(T& lhs,const T& rhs){ return lhs=std::min(lhs,rhs); }

typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


#define NULL_P -1
#define NULL_D -1

vvi graph;

int counter;
vi depth, low; //Used for both algorithms

/* SCC */
vector<bool> instack; // To now if a node is in a SCC or not
vi stack; // Stack of nodes to be proccessed in this path
int numCC;

void cutvescc(int v){
    /* SCC */depth[v]=low[v]=counter++;
    /* SCC */stack.push_back(v);
    /* SCC */instack[v]=true;

    for(int i=0;i<graph[v].size();i++){ int ch=graph[v][i];
	if(depth[ch]==NULL_D){ // Not yet visited, tree-edge
	    cutvescc(ch); 
	    minl(low[v],low[ch]);
	}
	// if it is a back-edge
	/* SCC */else if(instack[ch]) minl(low[v],depth[ch]);
    }
    
    /* SCC */
    if(depth[v]==low[v]){ ++numCC;
	for(;;){ int aux=stack.back(); stack.pop_back();
	    instack[aux]=false;
	    if(aux==v) break; 
	}
    }
}

int main(){
    int graph_size; int edges;
    while(scanf("%i%i",&graph_size,&edges),graph_size){
	depth.assign(graph_size,NULL_D); low.assign(graph_size,NULL_D);
	graph.assign(graph_size,vi());
	
	for(int i=0;i<edges;i++){
	    int v,w,p; scanf("%i%i%i",&v,&w,&p); --v; --w;
	    graph[v].push_back(w); if(p==2) graph[w].push_back(v);
	}
	
	/* SCC */
	counter=0; numCC=0;stack.clear(); instack.assign(graph_size,false);
	for(int i=0;i<graph_size;i++) if(depth[i]==NULL_D) cutvescc(i);
	printf("%i\n",numCC==1);
    }
    return 0;
}
