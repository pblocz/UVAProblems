#include <cstdio>

int main(){
    long int a,b; 
    while(scanf("%li%li",&a,&b)!=EOF) printf("%li\n",(b-a<0)?a-b:b-a);
    return 0;
}
