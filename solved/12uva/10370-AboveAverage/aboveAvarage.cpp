#include <cstdio>
#include <cstring>

int main(){
    int cases;
    scanf("%i",&cases);
    while(cases--){
	int set[1000],num,total=0;
	double avarage;

	scanf("%i",&num);
	for(int i=0;i<num;i++){
	    scanf("%i",&set[i]);
	    total+=set[i];
	}
	avarage=total/num;
	
	int count=0;
	for(int i=0;i<num;++i)
	    if(set[i]>avarage) ++count;
	
	printf("%.3f\%\n",static_cast<double>(count*100)/num);
    }
    return 0;
}
