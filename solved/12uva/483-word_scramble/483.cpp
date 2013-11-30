#include <cstdio>
#include <cctype>

int main(){
    char buffer[1024],*idx=buffer; int c;
    while((c=getchar())!=EOF)
	if(c==' ' || c=='\n'){ 
	    while(idx!=buffer) putchar(*--idx); putchar(c); } 
	else *idx++=c;
    return 0;
}
