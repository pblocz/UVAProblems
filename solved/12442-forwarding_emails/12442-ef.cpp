#include <cstdio>
#include <cstring>

#include <algorithm>

template <typename type,int bufsize>
inline type rdbunumber(){
    static char buffer[bufsize]; static char* beg=buffer,* end=buffer;
    type out=0;
    if(beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    while(*beg==' ' || *beg=='\n')
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    
    while(*beg>='0' && *beg<='9'){
	out=(out<<3)+(out<<1)+*beg-'0';
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    }
    return out;
}
#define BSIZE 8192*2
#define rdbui rdbunumber<unsigned int,BSIZE>



const int NUM=50000;
int graph[NUM]; // there is just one joined to each
int Index[NUM];
int longest[NUM];

int main(){
    int cases=rdbui();
    for(int c=1;c<=cases;++c){
	int nodes=rdbui();
	for(int j=0;j<nodes;++j) graph[rdbui()-1]=rdbui()-1;

	memset(Index,-1,sizeof(int)*nodes);
	memset(longest,-1,sizeof(int)*nodes);
	int queue[NUM],*end,max=0,midx=NUM;
	for(int n=0;n<nodes;++n){
	    end=queue; int step=0,cur=n;
	    while(1){
		if(Index[cur]==-1){ //not yet visited, continue
		    *end++=cur;
		    Index[cur]=step++;
		    cur=graph[cur];
		}
		else{ //2 posb, a cycle or just another chain
		    if(longest[cur]==-1){ //a cycle
			int length=Index[*(end-1)]-Index[cur]+1;
			while(*--end!=cur) longest[*end]=length;
			longest[cur]=length;
		    }
		    step=longest[cur];
		    while(end!=queue) longest[*--end]=++step;
		    
		    if(max<longest[n]){ max=longest[n]; midx=n; }
		    else if(max==longest[n] && n<midx){ 
			max=longest[n]; midx=n; }
		    
		    break;
		}
	    }
	}
	printf("Case %i: %i\n",c,midx+1);
    }
    return 0;
}
