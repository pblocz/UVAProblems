#include <cstdio>

int main(){
    int cases;
    scanf("%i",&cases);
    while(cases--){
	int a,b;
	scanf("%i%i",&a,&b);
	if(a<b) puts("<");
	else if(a==b) puts("=");
	else puts(">");
    }
    return 0;
}
