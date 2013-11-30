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
