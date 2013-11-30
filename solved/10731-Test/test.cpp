#include <vector>
#include <set>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1
#define DFS_GRAY 2              // one more color for graph edges property chec
vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;
vi dfs_parent;      // to differentiate real back edge versus bidirectional edge
vi dfs_low;

vi S, visited;                                    // additional global variables
int numSCC;
set< set<int> > CC;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<vector<ii> > AdjList;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
    //printf("SCC %d:", ++numSCC);            // this part is done after recursion
    set<int> comp;
    while (1) {
      int v = S.back(); S.pop_back(); visited[v] = 0;
      comp.insert(v);
      //printf(" %d", v);
      if (u == v) break;
    }
    CC.insert(comp);
    //printf("\n");
} }


int main(){
  int lines; int V='Z'-'A'+1; vector<bool> check; const char* br="";
  while(scanf("%i",&lines),lines!=0){
    AdjList.clear(); AdjList.resize('Z'-'A'+1,vector<ii>()); check.assign(V,false);
    for(int i=0;i<lines;i++){
      char a,b,c,d,e,f; scanf("\n%c %c %c %c %c %c",&a,&b,&c,&d,&e,&f); check[f-'A']=true;
      if(f!=a) { check[a-'A']=true; AdjList[f-'A'].push_back(ii(a-'A',0)); }
      if(f!=b) { check[b-'A']=true; AdjList[f-'A'].push_back(ii(b-'A',0)); }
      if(f!=c) { check[c-'A']=true; AdjList[f-'A'].push_back(ii(c-'A',0)); }
      if(f!=d) { check[d-'A']=true; AdjList[f-'A'].push_back(ii(d-'A',0)); }
      if(f!=e) { check[e-'A']=true; AdjList[f-'A'].push_back(ii(e-'A',0)); }
    }

    // for(int i=0;i<V;i++){
    //   printf("%c: ",i+'A');
    //   for(int j=0; j<AdjList[i].size(); j++){
    // 	printf("%c ",AdjList[i][j].first+'A');	
    //   } putchar('\n');
    // }

    dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0); visited.assign(V, 0); CC.clear();
    dfsNumberCounter = numSCC = 0;
    for (int i = 0; i < V; i++)
      if (dfs_num[i] == DFS_WHITE)
	tarjanSCC(i);
    
    fputs(br,stdout);br="\n";
    for(set<set<int> >::iterator it=CC.begin(); it!=CC.end(); ++it){ bool any=false;
      const char* str="";
      for(set<int>::iterator it2=it->begin(); it2!=it->end(); ++it2){
	if(check[*it2]){ any=true; printf("%s%c",str, *it2+'A'); str=" "; }
      } if(any) putchar('\n');
    }
  }
  return 0;
}
