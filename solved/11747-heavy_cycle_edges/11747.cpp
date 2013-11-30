#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

struct UFDS{
    UFDS(int n){for(int i=0;i<n;++i)v[i]=i;}
    void join(int i,int j){ v[find(i)]=find(j); }
    int find(int i){ return (v[i]==i)? i : v[i]=find(v[i]); }
    void reset(int n){for(int i=0;i<n;++i)v[i]=i;}
    int v[1000];
};

// typedef pair<int,int> ii;
// typedef pair<int,pair<int,int> > iii;

struct iii{int c,x,y; iii(int C=0,int X=0,int Y=0):c(C),x(X),y(Y){}};
bool operator<(iii a, iii b){ return a.c < b.c; }

int main(){
    int n,m; UFDS u(0); iii edges[25000];
    while(scanf("%i%i",&n,&m),n){
	u.reset(n); bool any=false;
	for(int i=0;i<m;++i){ 
	    int x,y,c; scanf("%i%i%i",&x,&y,&c); edges[i]=iii(c,x,y); }
	sort(edges,edges+m);
	for(int i=0;i<m;i++){
	    if(u.find(edges[i].x)!=u.find(edges[i].y)) 
		u.join(edges[i].x,edges[i].y);
	    else{ 
		if(any) putchar(' '); printf("%i",edges[i].c); any=true; }
	} 
	if(!any) fputs("forest",stdout); putchar('\n');
    }
    return 0;
}
