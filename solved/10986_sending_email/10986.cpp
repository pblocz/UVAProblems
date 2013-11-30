#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream> 

using namespace std;

typedef pair<long long,int> Li;

vector<vector<pair<int,int> > > adylist;
long long dist[20000];


template <typename type,int bufsize>
inline type rdbunumber(){
    static char buffer[bufsize]; static char* beg=buffer,* end=buffer;
    type out=0;
    if(beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    while(*beg==' ' || *beg=='\n')
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    
    while(*beg>='0' && *beg<='9'){
	out=(out<<3)+(out<<1)+*beg-'0';
	if(++beg==end) end=(beg=buffer)+fread(buffer,1,bufsize,stdin);
    }
    return out;
}
#define BSIZE 8192<<3
#define rdbui rdbunumber<unsigned int,BSIZE>


// unsigned rdbui(){ unsigned i; scanf("%u",&i); return i; }

int main(){
    int N=rdbui();

    for(int c=1;c<=N;c++){
	int n=rdbui(),m=rdbui(),s=rdbui(),t=rdbui();
	adylist.assign(n,vector<pair<int,int> > ());
	for(int i=0;i<m;++i){
	    int a=rdbui(), b=rdbui(), cost=rdbui();
	    adylist[a].push_back(pair<int,int>(b,cost));
	    adylist[b].push_back(pair<int,int>(a,cost));
	}
	memset(dist,-1,n*sizeof(long long));
	
	priority_queue<Li,vector<Li>,greater<Li> > qu; qu.push(Li(0,s));
	while(!qu.empty()){
	    Li act=qu.top(); qu.pop();
	    if(dist[act.second]!=-1) continue;
	    dist[act.second]=act.first;
	    if(act.second==t) break;

	    // relax this vertex
	    for(int i=0;i<adylist[act.second].size();++i){
		if(dist[adylist[act.second][i].first]==-1){
		    qu.push(Li(
			       act.first+adylist[act.second][i].second,
			       adylist[act.second][i].first));
		    
		}
	    }
	}
	
	if(dist[t]!=-1) printf("Case #%i: %Li\n",c,dist[t]);
	else printf("Case #%i: unreachable\n",c);
    }
}
