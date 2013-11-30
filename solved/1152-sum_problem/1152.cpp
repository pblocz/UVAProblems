#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int sumA[4000*4000],sumB[4000*4000];
int main(){
    int m[4][4000],cases; scanf("%i",&cases); bool first=true;
    vector<pair<int,int> > pii;
    while(cases--){
	int N,sol=0,sa=0,sb=0; scanf("%i",&N);
	for(int i=0;i<N;++i) scanf("%i%i%i%i",&m[0][i],&m[1][i]
				   ,&m[2][i],&m[3][i]);
	for(int i=0;i<N;++i) 
	    for(int j=0;j<N;++j){
		sumA[sa++]=m[0][i]+m[1][j];
		sumB[sb++]=m[2][i]+m[3][j];
	    }
	sort(sumB,sumB+sb); pii.clear();
	for(int i=0;i<sb;){
	    pii.push_back(make_pair(sumB[i],1)); i++;
	    while(i<sb && sumB[i]==pii.back().first) i++,pii.back().second++;
	}

	for(int i=0;i<sa;i++){
	    vector<pair<int,int> >::iterator it=
		lower_bound(pii.begin(),pii.end(),pair<int,int>(-sumA[i],0));
	    if(it!=pii.end() && it->first==-sumA[i]) sol+=it->second;
	}
	if(first) first=false; else putchar('\n'); printf("%i\n",sol);
    }
    return 0;
}
