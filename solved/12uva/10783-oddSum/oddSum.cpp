#include <cstdio>

int main(){
    int cases;
    scanf("%i",&cases);
    for(int i=1;i<=cases;++i){
	int a,b;
	scanf("%i%i",&a,&b);
	b=(b+b%2)/2;
	a=(a-a%2)/2;
	printf("Case %i: %i\n",i,b*b-a*a);
    }
    return 0;
}
