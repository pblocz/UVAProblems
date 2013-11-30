enum {MAXSIZE=100, INF=10000};
typedef int graph[MAXSIZE][MAXSIZE];

inline graph floydWarshall(graph g,const int nodes){
    static graph paths; // For finding the paths between i,j
    for(int k=0;k<nodes;k++)
	for(int i=0;i<nodes;i++)
	    for(int j=0;j<nodes;j++){
		int aux=g[i][k]+g[k][j];
		if(g[i][j]>aux){
		    g[i][j]=aux;
		    paths[i][j]=k;
		}
	    }
    return paths;
}

inline void reversePath(vector<int> &path, graph paths,int s,int d){
    int k=paths[s][d];
    reversePath(path,paths,s,k);
    path.push_back(k);
    reversePath(path,paths,k,d);
}

int main(){
    int nodes;
    graph g;
    for(int i=0;i<nodes;i++) memset(g[i],-1,nodes*sizeof(int));
    
    //READ OF PREPARE THE GRAPH HERE

    for(int i=0;i<nodes;i++)
	for(int j=0;j<nodes;j++) 
	    if(i==j) g[i][i]=0;
	    else if(g[i][j]==-1) g[i][j]=INF;
    return 0;
}
