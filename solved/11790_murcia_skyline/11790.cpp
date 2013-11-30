#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int N,cases;
    vector<int> height,width,incre,decr;

    scanf("%i",&cases);
    for(int c=1;c<=cases;c++){
	scanf("%i",&N); height.clear(); width.clear();
	for(int i=0;i<N;i++){ int h; scanf("%i",&h); height.push_back(h); }
	for(int i=0;i<N;i++){ int w; scanf("%i",&w); width.push_back(w); }

	incre.resize(N); decr.resize(N); int LIS=0, LDS=0;
	for(int i=0;i<N;i++){
	    incre[i]=decr[i]=width[i];
	    for(int j=0;j<i;j++){
		if(height[j]<height[i]) incre[i]=max(incre[j]+width[i],incre[i]);
		if(height[j]>height[i]) decr[i]=max(decr[j]+width[i],decr[i]);
	    }
	    LIS=max(incre[i],LIS); LDS=max(decr[i],LDS);
	}
	printf("Case %i. ",c);
	printf((LIS>=LDS) ?
	       "Increasing (%i). Decreasing (%i).\n" :
	       "Decreasing (%i). Increasing (%i).\n" ,
	       max(LIS,LDS),min(LIS,LDS));
    }
    return 0;
}
