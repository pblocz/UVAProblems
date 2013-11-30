/**
   \author Pablo Cabeza García

   Problem: Jolly Jumpers

   The problem consists on finding out if a sequence of N number is
   Jolly or not, that means, if all the absolute differences between
   every consecutive element matches the set of number from 1 to N-1.
   
   To solve it the natural way would be to calculate all those
   differences and store them in an array. Then sort it and count if
   it is ok. This runs in O(nlog(n)) time. I did it in another. Since
   boundaries are small I have a bool array of 3000 elements and
   initialize it to false. In a loop I calculate the differences and
   everytime I compare, if it is greater or equal than the actual seq
   size it can't be completed, so I stop. If two numbers are repeted I
   stop. Thus, my algorithm is able to tell in O(n) if the seq is
   Jolly or having a bool array of "difference i is already
   found". Number 0 is special, since it can't I initialize it always
   to true.
 */

#include <cstdio>
#include <cstring>

enum {MSIZE=3000};

inline int abs(int i){ return i>=0?i:-i; }
inline void skipline(){ while(getchar()!='\n');}

int main(){
    int size;
    bool diff[MSIZE];
    diff[0]=true;

    while(scanf("%i",&size)!=EOF){
	memset(diff+1,0,size);
	int oldval,newval,count=size;
	scanf("%i",&oldval);
	while(--count){
	    scanf("%i",&newval);
	    int aux=abs(newval-oldval);
	    if(aux>=size || diff[aux]){skipline();break;}
	    oldval=newval;
	    diff[aux]=true;
	}
	if(count==0) fwrite("Jolly\n",1,6,stdout);
	else fwrite("Not jolly\n",1,10,stdout);
    }

    return 0;
}
