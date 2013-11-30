// continents
#include <cstdio>
#include <algorithm>

using std::max;

#define INC(mat,x,y,ix,iy,N) mat[y+iy][((x+ix<0) ? N-1 : x+ix) % N]
#define EINC(mat,x,y,N) INC(mat,x,y,1,0,N)
#define WINC(mat,x,y,N) INC(mat,x,y,-1,0,N)
#define NINC(mat,x,y,N) INC(mat,x,y,0,-1,N)
#define SINC(mat,x,y,N) INC(mat,x,y,0,1,N)

int floodcount(char mat[][21], int x, int y,const int M,const int N, const char t){
    int i=1; mat[y][x]=t+1;
    if( y > 0 && NINC(mat,x,y,N)==t ) i+=floodcount(mat,x,y-1,M,N,t);
    if( y < M-1 && SINC(mat,x,y,N)==t ) i+=floodcount(mat,x,y+1,M,N,t);
    if( WINC(mat,x,y,N)==t ) i+=floodcount(mat,(x-1<0)?N-1:x-1,y,M,N,t);
    if( EINC(mat,x,y,N)==t ) i+=floodcount(mat,(x+1)%N,y,M,N,t);

    return i;
}


int main(){
    int M,N,px,py,Max;
    char matrix[20][21], t;
    while(scanf("%i%i",&M,&N)!=EOF){
	getchar();
	for (int i=0;i<M;i++)
	    fread(matrix[i],N+1,1,stdin);
	scanf("%i%i",&py,&px);
	t=matrix[py][px];
	
	floodcount(matrix,px,py,M,N,t); Max=0;
	for(int i=0;i<M;i++)
	    for(int j=0;j<N;j++)
		if(matrix[i][j]==t) Max=max(Max,floodcount(matrix,j,i,M,N,t));
	
	printf("%i\n", Max);
    }
    return 0;
}
