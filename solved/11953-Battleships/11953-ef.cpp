#include <cstdio>

template <int dx, int dy>
bool dircheckalive(char grid[100][100],int x,int y,int size){
    x+=dx; y+=dy;
    if( x<0 || y<0 || x>=size || y>=size || grid[y][x]=='.' ) return false;
    bool alive=(grid[y][x]=='x');
    grid[y][x]='.';
    alive=dircheckalive<dx,dy>(grid,x,y,size)||alive;
    return alive;
}

bool checkalive(char grid[100][100],int x,int y,int size){
    bool alive=(grid[y][x]=='x');
    grid[y][x]='.';
    
    alive=dircheckalive<1,0>(grid,x,y,size)||alive;
    alive=dircheckalive<-1,0>(grid,x,y,size)||alive;
    alive=dircheckalive<0,1>(grid,x,y,size)||alive;
    alive=dircheckalive<0,-1>(grid,x,y,size)||alive;
    
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
