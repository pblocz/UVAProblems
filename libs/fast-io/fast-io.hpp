/**
   \author Pablo Cabeza García
   
   Version 0.11.30

   Set of functions for fast io implementation on basic types.
*/

/** Libraries used by all function */
#include <cstdio>


/* -----------------------------------------------------
   			Reading Methods
   ----------------------------------------------------- */


/** 
    It just uses mult and add to create the numbers. Mostly for
    int,long, long long, yet can be used for any other type having
    mult and add. 
*/
template <typename type>
inline type rdnumber(){
    type out; int c,sign;
    while((c=getc(stdin))==' ' || c=='\n');
    out=(c=='-')?(sign=-1,0):(sign=1,c-'0');
    while((c=getc(stdin))>='0' && c<='9') out=(out<<3)+(out<<1)+c-'0';
    ungetc(c,stdin);
    return out*sign;
}
#define rdi rdnumber<int>
#define rdl rdnumber<long>
#define rdll rdnumber<long>


/** 
    It just uses mult and add. Mostly for unsigned int,unsigned
    long,unsigned long long, It can also be used for any other type
    havin mult 
*/
template <typename type>
inline type rdunumber(){
    type out; int c;
    while((c=getc(stdin))==' ' || c=='\n');
    out=(c>='0' && c<='9')?c-'0':0;
    while((c=getc(stdin))>='0' && c<='9') out=(out<<3)+(out<<1)+c-'0';
    ungetc(c,stdin);
    return out;
}
#define rdui rdunumber<unsigned int>
#define rdul rdunumber<unsigned long>
#define rdull rdunumber<unsigned long long>


/** 
    Mostly for int, long, long long. It just uses mult and add. This
    function is buffered to speed up reading lots of ints and not
    calling getc() each time a digit is read. 
*/
template <typename type,int bufsize>
inline type rdbnumber(){
    static char buffer[bufsize]; static char* beg=buffer,* end=buffer;
    type out=0; char sign;
    if(beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    while(*beg==' ' || *beg=='\n')
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);

    out=(*beg=='-')?(sign=-1,0):(sign=1,*beg-'0');
    if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);

    while(*beg>='0' && *beg<='9'){
	out=(out<<3)+(out<<1)+*beg-'0';
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    }
    return sign*out;
}
#define BSIZE 8192
#define rdbi rdbnumber<int,BSIZE>
#define rdbl rdbnumber<long,BSIZE>
#define rdbll rdbnumber<long long,BSIZE>


/** 
    Mostly for unsigned int,unsigned long,unsigned long long. It just uses
    mult and add. This function is buffered to speed up reading lots
    of ints and not calling getc() each time a digit is read. 
*/
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
#define BSIZE 8192
#define rdbui rdbunumber<unsigned int,BSIZE>
#define rdbul rdbunumber<unsigned long,BSIZE>
#define rdbull rdbunumber<unsigned long long,BSIZE>


/** 
    Reads a string of characters to a char* string
*/
char* rdcstr(char *str){
    int c,cpy=str;
    while((c=getchar())!=' ' && c!='\n') *str++=(char)c;
    *str='\0';
    ungetc(c,stdin);
    return cpy;
}

/** 
    Reads a string of characters to a char* string
*/
void rdstr(char* buf){
    int c;
    while((c=gc())==' ' || c=='\n');
    do{ *buf++=c; } while(!((c=gc())==' ' || c=='\n')); 
    ungetc(c,stdin);
    *buf++='\0';
}

/* -----------------------------------------------------
   			Writing Methods
   ----------------------------------------------------- */

/** This macros allow fast output for strings of known size */
#define wrs(str,size) fwrite((str),1,(size),stdout)
#define wrcs(str) fwrite((str),1,sizeof((str))-1,stdout)
#define wrcsb(str) wrcs(str),putchar('\n')

/**
   Method to write numbers to standard output in a fast way, it uses a
   static buffer to represent the number as a string.
*/
template <typename T>
void wrun(T n){
    static char str[128],*e=str+128;
    char *b=e;
    do{
	*--b=n%10+'0';
	n/=10;
    } while(n!=0);
    wrs(b,e-b);
}


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


template <typename T>
void wrn(T n){
    static char str[128],*e=str+128;
    char *b=e; bool isneg=false;
    if(n<0){
	isneg=true;
	n=-n;
    }
    do{
	*--b=n%10+'0';
	n/=10;
    } while(n!=0);
    if(isneg) *--b='-';
    wrs(b,e-b);
}
