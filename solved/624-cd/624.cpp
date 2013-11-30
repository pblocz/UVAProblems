/**
   Resolver el problema de la mochila por backtracking
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
#define K 21

bool bestsol[K];
int bestVol;

int N;
int C;
int elem[K];
bool actsol[K];

/*
  Possible heavy prunes:
  - sort the list to explore the nodes in that order, that way you
  will prune earlier due to heavier early nodes

  - since it is sorted, if elem[pos] > C , then you cant continue

  - If bestVol <= C - SUM_OF_NEXTS, then you cant continue
 */

// knapsack(k) = el mejor coste de llenar con los k primeros hasta
// C (global)
bool knapsack(int pos){
    if(pos==0){
	if(C>=elem[0] && C-elem[0]<bestVol){ 
	    bestVol=C-elem[0];
	    memcpy(bestsol,actsol,sizeof(bestsol)); bestsol[0]=true; 
	    return !bestVol;
	}
	else if(C< bestVol){
	    memcpy(bestsol,actsol,sizeof(bestsol)); 
	    bestVol=C;
	    return !bestVol;
	}
	return false;
    }
    
    if(elem[pos]<=C){
	actsol[pos]=true;
	C-=elem[pos];
	if(C==0){ 
	    memcpy(bestsol,actsol,sizeof(bestsol)); 
	    bestVol=0;
	    C+=elem[pos];
	    return true; 
	}
	bool ret=knapsack(pos-1);
	C+=elem[pos];
	if(ret) return true;
	actsol[pos]=false;
    }
    return knapsack(pos-1);
}


int main(){
    while(scanf("%i",&C)!=EOF){
	int N; scanf("%i",&N);
	bestVol=~0U>>1;;
	memset(actsol,0,sizeof(actsol));
	memset(bestsol,0,sizeof(bestsol));

	for(int i=0;i<N;i++) scanf("%i",elem+i);
	knapsack(N-1);

	for(int i=0;i<N;i++) if(bestsol[i]) printf("%i ",elem[i]);
	printf("sum:%i\n",C-bestVol);
    }
}
