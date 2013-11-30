#include <cstring>
#include <cstdio>

#include <iostream> 
using namespace std;

int rdc() { return getchar(); }
int EOFF;
unsigned rdui(){ unsigned i; EOFF=scanf("%u",&i); return i;}


bool matrix[100][100];
int colors[100];
int nodes;

bool backtracking(int n=1){
    if(n==nodes) return true;
    for(int i=0;i<4;i++){
	bool pos=true;
	for(int j=0;j<n;j++){
	    if(matrix[n][j] && colors[j]==i){ pos=false; break; }
	}
	if(pos){ 
	    colors[n]=i; 
	    if(backtracking(n+1)) return true; 
	    colors[n]=-1; 
	} 
    }
    return false;
}

int main(){
    const char* sep="";
    do{
	nodes=rdui(); rdc();
	memset(colors,-1,sizeof(int)*nodes); 
	for(int i=0;i<nodes;i++) memset(matrix[i],0,nodes);
	int c;
	while((c=rdc())!='\n' && c!=EOF){ ungetc(c,stdin);
	    int a=rdui()-1; rdc(); int b=rdui()-1; rdc();
	    matrix[a][b]=matrix[b][a]=true;
	}
	colors[0]=0;
	backtracking();
	
	fputs(sep,stdout); sep="\n";
	for(int i=0;i<nodes;i++) printf("%i %i\n",i+1,colors[i]+1);
    } while(!feof(stdin));
    
    return 0;
}
