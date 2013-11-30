#include <cstdio>

template <typename type>
inline type rdunumber(){
    type out; int c;
    while((c=getc(stdin))==' ' || c=='\n');
    out=(c>='0' && c<='9')?c-'0':0;
    while((c=getc(stdin))>='0' && c<='9') out=(out<<3)+(out<<1)+c-'0';
    if(c!=EOF) ungetc(c,stdin);
    return out;
}
#define rdui rdunumber<unsigned int>

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
	if(feof(stdin)) break;

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
	
	printf("%s %i\n",OUTPUT[idx],v);
    }
    //while(!fioc::eof());

    return 0;
}

/// Local Variables:
/// compile-command: (concat "g++ -O3 " (buffer-name))
/// End:
