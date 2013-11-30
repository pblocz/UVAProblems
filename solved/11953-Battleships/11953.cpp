#include <cstdio>

int xm[]={1,0,-1,0},
    ym[]={0,1,0,-1};

bool checkalive(char grid[100][100],int x,int y,int size){
    if( x<0 || y<0 || x>=size || y>=size ) return false;
    bool alive=(grid[y][x]=='x');
    grid[y][x]='.';
    
    for(int i=0;i<4;i++) 
	if(grid[y+ym[i]][x+xm[i]] != '.')
	    alive=checkalive(grid,x+xm[i],y+ym[i],size)||alive;
    return alive;
}

int main(){
    int cases; scanf("%i",&cases);
    char grid[100][100];
    for(int c=1;c<=cases;c++){
	int size,solution=0; scanf("%i",&size); getchar();
	for(int i=0;i<size;i++){ fread(grid[i],size,1,stdin); getchar(); }
	
	for(int i=0;i<size;i++) 
	    for(int j=0;j<size;j++)
		if(grid[j][i]!='.') solution+=checkalive(grid,i,j,size);
	printf("Case %i: %i\n",c,solution);
    }

    return 0;
}
