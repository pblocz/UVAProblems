#include <cstdio>
#include <cstring>


int main(){
    int pegs;
    int sizes[50];
    int set=0;

    while(scanf("%i",&pegs),pegs){
	int count=0;
	for(int i=0;i<pegs;i++){
	    scanf("%i",&sizes[i]);
	    count+=sizes[i];
	}
	count=count/pegs;
	int moves=0;
	for(int i=0;i<pegs;i++)
	    if(sizes[i]>count) moves+=sizes[i]-count;
	printf("Set #%i\nThe minimum number of moves is %i.\n\n",++set,moves);
    }

    return 0;
}
