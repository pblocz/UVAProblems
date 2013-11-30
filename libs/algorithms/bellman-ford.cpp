
enum {edge_count=100,graph_size=10};

#define INF 10000

struct edge{
    int s; int d; int c;
};

edge pool[edge_count];
int poolS;



inline bool bellman_ford(const int nodes,const int v){
    int dist[graph_size];

    for(int i=0;i<nodes;++i) dist[i]=INF;
    dist[v]=0;

    const edge* const pend=pool+poolS;
    for(int i=0;i<nodes;++i){
	for(edge *edg=pool;edg!=pend;++edg){
	    if(dist[edg->s] > dist[edg->d] + edg->c) 
		dist[edg->s]=dist[edg->d] + edg->c;
	    if(dist[edg->d] > dist[edg->s] + edg->c) 
		dist[edg->d]=dist[edg->s] + edg->c;
	}
    }
    for(edge *edg=pool;edg!=pend;++edg){
	if(dist[edg->s] > dist[edg->d] + edg->c) 
	    return true;
	if(dist[edg->d] > dist[edg->s] + edg->c) 
	    return true;
    }
    return false;
}

int main(){
    volatile int n=10;
    bellman_ford(n,n-1);
    return 0;
}
