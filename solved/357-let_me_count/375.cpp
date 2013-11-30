#include <cstdio>
#include <cstring>

//#define UNGETC

template <int bufsize>
class fio{
public:
    template <typename type>
    static type rdbunumber(){
	type out=0;
	if(beg==end && lread==bufsize) end=(beg=buffer)+(lread=fread(buffer,1,bufsize,stdin));
	
	while(beg!=end && *beg==' ' || *beg=='\n')
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

#define BSIZE 8192*8
#define rdui fio<BSIZE>::rdbunumber<unsigned>
#define rdc   fio<BSIZE>::getc

typedef fio<BSIZE> fioc;



template <typename T>
int wrun(char* cstr,T n){
    static char str[128]={'\0'},*e=str+127;
    char *b=e;
    do{
	*--b=n%10+'0';
	n/=10;
    } while(n!=0);
    memcpy(cstr,b,e-b);
    return e-b;
}


// 1,5,10,25 50

// 		     f(c,m) = f(c,m+1) + f(c-v[m],m)

long dp[30001][5];

const unsigned v[]={1,5,10,25,50};

template <unsigned i>
long dodp(unsigned ch){
    if(dp[ch][i]!=-1) return dp[ch][i];

    if(ch < v[i]) return dp[ch][i]=dodp<i-1>(ch);
    else return dp[ch][i]=dodp<i-1>(ch) + dodp<i>(ch-v[i]);
}

template <>
inline long dodp<0>(unsigned ch){
    return 1;
}

int main(){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<5;i++) dp[0][i]=1;
    for(;;){
	unsigned n=rdui(); if(fioc::eof()) break; long res=dodp<4>(n);
	if(res!=1) printf("There are %li ways to produce %u cents change.",res,n);
	else printf("There is only 1 way to produce %u cents change.",n);
	putchar('\n');
    }
    return 0;
}

/// Local Variables:
/// compile-command: (concat "g++ -O3 " (buffer-name))
/// End:
