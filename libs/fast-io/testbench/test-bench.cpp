/** Libraries used by all function */
#include <cstdio>
#include <cctype>

#ifdef MULT
template <typename type>
inline type rdnumber(){
    type out; int c,sign;
    while((c=getc(stdin))==' ' || c=='\n');
    out=(c=='-')?(sign=-1,0):(sign=1,c-'0');
    while((c=getc(stdin))>='0' && c<='9') out=out*10+c-'0';
    ungetc(c,stdin);
    return out*sign;
}
#define rdi rdnumber<int>
#define rdl rdnumber<long>
#define rdll rdnumber<long>

#elif defined SHIFT
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

#else
int rdi(){ int AUX;scanf("%i",&AUX);return AUX;};
#endif

int main(){
    
    // max 70590000
    for(long long i=0;i<10000000;i++) printf("%i ",rdi());
    
    return 0;
}
