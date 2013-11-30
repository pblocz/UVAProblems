#include <cstdio>

int f(long n){
    long m=0;
    while(n!=0){ m+=n%10; n/=10; }
    return m;
}

int main(){
    int num;
    while(scanf("%i",&num),num!=0){ 
	while(num>=10) num=f(num); printf("%i\n",num); }
    return 0;
}
