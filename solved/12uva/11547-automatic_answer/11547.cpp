#include <cstdio>

/*
For each test case, output the answer to the following skill testing question on a line by itself:  Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide by 47, then subtract 498. What is the digit in the tens column?  
*/
 
int main(){
    long long inp; int cases; scanf("%i",&cases);
    while(cases--){
	scanf("%lli",&inp);
	inp*=567;
	inp/=9;
	inp+=7492;
	inp*=235;
	inp/=47;
	inp-=498;
	
	printf("%lli\n",((inp>0?inp:-inp)/10)%10);
    }
    return 0;
}
