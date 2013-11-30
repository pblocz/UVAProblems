#include <cstdio>
#include <cstring>

#include <algorithm>

const int NUM=50000;
int graph[NUM]; // there is just one joined to each
int Index[NUM];
int longest[NUM];

int main(){
    int cases; scanf("%i",&cases);
    for(int c=1;c<=cases;++c){
	int nodes; scanf("%i",&nodes);
	for(int j=0;j<nodes;++j){ 
	    int aux1,aux2; scanf("%i%i",&aux1,&aux2); 
	    graph[aux1-1]=aux2-1; }

	memset(Index,-1,sizeof(int)*nodes);
	memset(longest,-1,sizeof(int)*nodes);
	int queue[NUM],*end,max=0,midx=NUM;
	for(int n=0;n<nodes;++n){
	    end=queue; int step=0,cur=n;
	    while(1){
		// printf("now processing %i\n",cur+1);
		if(Index[cur]==-1){ //not yet visited, continue
		    *end++=cur;
		    Index[cur]=step++;
		    cur=graph[cur];
		}
		else{ //2 posb, a cycle or just another chain
		    if(longest[cur]==-1){ //a cycle
			int length=Index[*(end-1)]-Index[cur]+1;
			// printf("there is a cicle in %i of %i\n",cur+1,length);
			while(*--end!=cur) longest[*end]=length;
			longest[cur]=length;
		    }
		    //else{
			step=longest[cur];
			// printf("from %i to (%i,%i) there is a link\n",
			//        *(end-1)+1,cur+1,step);
			while(end!=queue) longest[*--end]=++step;
			//		    }
		    if(max<longest[n]){ max=longest[n]; midx=n; }
		    else if(max==longest[n] && n<midx){ 
			max=longest[n]; midx=n; }
		    break;
		}
	    }
	}
	// for(int i=0;i<nodes;i++) printf("%i\t",i+1);putchar('\n');
	// for(int i=0;i<nodes;i++) printf("%i\t",longest[i]);puts("");
	printf("Case %i: %i\n",c,midx+1);
    }
    return 0;
}
