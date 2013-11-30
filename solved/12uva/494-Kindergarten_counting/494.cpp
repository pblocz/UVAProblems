#include <cstdio>
#include <cctype>

int main(){
    char buffer[1<<14]; int words=0,res; bool wordstarted=false;
    do{ 
	res=fread(buffer,1,1<<14,stdin);
	for(int i=0;i<res;++i)
	    if(isalpha(buffer[i])) wordstarted=true;
	    else if(buffer[i]=='\n'){
		printf("%i\n",words+=wordstarted); words=wordstarted=false; }
	    else{ words+=wordstarted; wordstarted=false; }
    } while(res==1<<14);
}
