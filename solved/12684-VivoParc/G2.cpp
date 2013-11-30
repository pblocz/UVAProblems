#include <cstring>
#include <cstdio>

#include <iostream> 
using namespace std;

#define UNGETC

template <int bufsize>
class fio{
public:
    template <typename type>
    static type rdbunumber(){
	type out=0;
	if(beg==end && lread==bufsize) end=(beg=buffer)+(lread=fread(buffer,1,bufsize,stdin));
	
	for(c=*beg;beg!=end && *beg==' ' || *beg=='\n';c=*beg)
	    if(++beg==end && lread==bufsize) end=(beg=buffer)+(lread=fread(buffer,1,bufsize,stdin));
	
	while(beg!=end && *beg>='0' && *beg<='9'){
	    out=(out<<3)+(out<<1)+*beg-'0';
	    if(++beg==end && lread==bufsize) end=(beg=buffer)+(lread=fread(buffer,1,bufsize,stdin));
	}
	return out;
    }

    static int getc(){
	#ifdef UNGETC
 	if(ungetchar>=0){ char c=ungetchar; ungetchar=-1; return c; }
	#endif

	if(beg==end) end=(beg=buffer)+(lread=fread(buffer,1,bufsize,stdin));
	return (beg!=end)?*beg++:EOF;
    }

    static bool eof(){
	return beg==end && lread<bufsize;
    }

private:
    static char* beg,* end;
    static int lread;
    #ifdef UNGETC
    static int ungetchar;
    #endif
    static char buffer[bufsize]; 
};

template <int bufsize>
char fio<bufsize>::buffer[bufsize];

template <int bufsize>
char *fio<bufsize>::beg=buffer;

template <int bufsize>
char *fio<bufsize>::end=buffer;

template <int bufsize>
int fio<bufsize>::lread=bufsize;

#ifdef UNGETC
template <int bufsize> 
fio<bufsize>::ungetchar=-1;
#endif

#define BSIZE 8192
#define rdui fio<BSIZE>::rdbunumber<unsigned>
#define rdc   fio<BSIZE>::getc

typedef fio<BSIZE> fioc;


bool matrix[100][100];
char colors[100];
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
	memset(colors,-1,nodes); for(int i=0;i<nodes;i++) memset(matrix[i],0,nodes);

	int c;
	while((c=rdc())!='\n' && !fioc::eof()){ ungetc(c,stdin);
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
