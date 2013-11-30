#include <cstdio>
#include <algorithm>
using std::max;

typedef long long unsigned L;

int main(){
    unsigned a,b,c; 
    while(scanf("%u%u%u",&a,&b,&c),a && b && c){
	L M=max(a,max(b,c));
#define LONG(a) ((L)(a))
#define a LONG(a)
#define b LONG(b)
#define c LONG(c)
	if( ((M*M)<<1) == a*a + b*b + c*c ) puts("right");
	else puts("wrong");
    }
    return 0;
}
