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


#define OUTBSIZE (1<<13)
char outbuffer[OUTBSIZE];
int obsize=0;


const char* OUTPUT[]={ // sorted in alphabetical order
    "BCG",
    "BGC",
    "CBG",
    "CGB",
    "GBC",
    "GCB",
};

int main(){
    while(true){
	int a1=rdui();
	if(fioc::eof()) break;

	int a2=rdui(),
	    a3=rdui(),
	    b1=rdui(),
	    b2=rdui(),
	    b3=rdui(),
	    c1=rdui(),
	    c2=rdui(),
	    c3=rdui();

	int idx=0,aux,v=b1+c1 + a3+c3 + a2+b2;
	if((aux=b1+c1 + a2+c2 + a3+b3)<v){ v=aux; idx=1; }
	if((aux=b3+c3 + a1+c1 + a2+b2)<v){ v=aux; idx=2; }
	if((aux=b3+c3 + a2+c2 + a1+b1)<v){ v=aux; idx=3; }
	if((aux=b2+c2 + a1+c1 + a3+b3)<v){ v=aux; idx=4; }
	if((aux=b2+c2 + a3+c3 + a1+b1)<v){ v=aux; idx=5; }

	if(obsize>OUTBSIZE-20) fwrite(outbuffer,1,obsize,stdout),obsize=0;
	outbuffer[obsize++]=OUTPUT[idx][0];
	outbuffer[obsize++]=OUTPUT[idx][1];
	outbuffer[obsize++]=OUTPUT[idx][2];
	outbuffer[obsize++]=' ';
	obsize+=wrun(outbuffer+obsize,v);
       	outbuffer[obsize++]='\n';
    }
    fwrite(outbuffer,1,obsize,stdout);
    return 0;
}

/// Local Variables:
/// compile-command: (concat "g++ -O3 " (buffer-name))
/// End:
