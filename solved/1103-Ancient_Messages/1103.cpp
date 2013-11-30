/**
   For efiency the check of the range could be done before entering
   the function and not inside it, that way it will be speed up
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char ttable[16][4]={
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1},
    {1,0,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {1,1,0,1},
    {1,1,1,0},
    {1,1,1,1}};

const char symbperholes[]={'W','A','K','J','S','D'};
const char alphorder[]={'A','D','J','K','S','W'};
const int symbhash[]={0,0,0,1,0,0,0,0,0,2,3,0,0,0,0,0,0,0,4,0,0,0,5};
//		      a b c d e f g h i j k l m n o p q r s t u v w


//              E  N   W  S
const int xm[]={1, 0, -1, 0},
          ym[]={0, 1,  0,-1}; 

void fillbackground(char grid[][200],int x,int y,const int w, const int h){
    if( x<0 || y<0 || x>=w || y>=h || grid[y][x]!=0) return;
    grid[y][x]='b';
    
    for(int i=0;i<4;i++) fillbackground(grid,x+xm[i],y+ym[i],w,h);
}

void fillhole(char grid[][200],int x,int y,const int w, const int h){
    if( x<0 || y<0 || x>=w || y>=h ) return;
    grid[y][x]=-1;
    
    for(int i=0;i<4;i++) if(grid[y+ym[i]][x+xm[i]] == 0) 
			     fillhole(grid,x+xm[i],y+ym[i],w,h);
}

int countholes(char grid[][200],int x,int y,const int w, const int h){
    if( x<0 || y<0 || x>=w || y>=h) return 0;
    if(grid[y][x]==0){ fillhole(grid,x,y,w,h); return 1; }
    if(grid[y][x]==1){
	grid[y][x]=-1;

	int holes=0;   
	for(int i=0;i<4;i++) holes+= countholes(grid,x+xm[i],y+ym[i],w,h);
	return holes;
    }
    return 0;
}


inline int transf(char c){
    if(c>='a') return c-'a'+10;
    return c-'0';
}


int main(){
    int H,W;
    char line[50*4];
    char matrix[200][50*4];
    int sol[6],cases=1;

    while(scanf("%i %i",&H,&W),H!=0 && W!=0){
	getchar();
	for(int i=0;i<H;i++){
	    fread(line,W,1,stdin); getchar();
	    for(int j=0;j<W;j++) memcpy(matrix[i]+(4*j),
					ttable[transf(line[j])],
					4);
	}

	for(int i=0;i<W*4;i++){
	    if(matrix[0][i]==0) fillbackground(matrix,i,0,W*4,H);
	    if(matrix[H-1][i]==0) fillbackground(matrix,i,H-1,W*4,H);
	}

	for(int i=0;i<H;i++){
	    if(matrix[i][0]==0) fillbackground(matrix,0,i,W*4,H);
	    if(matrix[i][W*4 -1]==0) fillbackground(matrix,W*4 -1,i,W*4,H);
	}

	memset(sol,0,sizeof(sol));
	for(int i=0;i<H;i++) 
	    for(int j=0;j<W*4;j++)
		if(matrix[i][j]==1)
		    sol[symbhash[symbperholes[countholes(matrix,j,i,W*4,H)]-'A']]++;

	printf("Case %i: ",cases++);
	for(int i=0;i<6;i++) 
	    for(int j=0;j<sol[i];j++) putchar(alphorder[i]);
	putchar('\n');
    }

    return 0;
}


