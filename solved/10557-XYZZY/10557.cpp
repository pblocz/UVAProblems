#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

// To test if from a cycle you can reach the end node
void endisreachable(char mat[],int adylist[][100],int adysize[],int size,int node=0){
    bool reach=(node==size-1); mat[node]=-2;
    for(int j=0;j<adysize[node];j++){
	if(mat[adylist[node][j]]==-1){
	    endisreachable(mat,adylist,adysize,size,adylist[node][j]);
	    reach=reach || mat[adylist[node][j]];
	}
    }
    mat[node]=reach;
}

bool bellmanford(int adylist[][100],int adysize[],int ncost[],int size){
    int costs[100]; char endreachable[100];
    memset(endreachable,-1,size*sizeof(char));
    memset(costs,-1,size*sizeof(int)); costs[0]=100;

    endisreachable(endreachable,adylist,adysize,size);

    for(int k=0;k<size-1;k++){
	for(int i=0;i<size;i++){
	    for(int j=0;j<adysize[i];j++){ //aristas de i a adylist[j]
		if(costs[i]==-1) continue;
		int &ref=costs[adylist[i][j]];
		ref=max(ref,costs[i]+ncost[adylist[i][j]]);
		if(ref==0) ref=-1;
	    }
	}
    }

    if(costs[size-1]>0) return true;
    for(int i=0;i<size;i++){
    	for(int j=0;j<adysize[i];j++){ //aristas de i a adylist[j]
    	    if(costs[i]==-1 || costs[adylist[i][j]]==-1) continue;
    	    if(costs[adylist[i][j]] < costs[i]+ncost[adylist[i][j]]) 
    		if(endreachable[adylist[i][j]]) return true;
    	}
    }
    return false;
}


int main(){
    int adylist[100][100], adysize[100], ncosts[100], size;
    while(scanf("%i",&size),size!=-1){
	for(int i=0;i<size;i++){
	    scanf("%i %i",&ncosts[i], &adysize[i]);
	    for(int j=0;j<adysize[i];j++){ 
		scanf("%i",&adylist[i][j]); --adylist[i][j]; }
	}

	if(bellmanford(adylist,adysize,ncosts,size)) puts("winnable");
	else puts("hopeless");	
    }
    return 0;    
}
