#include <cstdio>
#include <cstring>

#include <iostream>
using namespace std;


void error(char* act,char* pact, char* prev){
    if(*++pact=='\n') *(pact)='\0';
    printf("mismatch: %s + 1 != %s",act,prev);
}

int main(int argc,char* argv[]){
    char cA[1000];
    char cB[1000];
    char *prev=cA ,*act=cB;
    char* pprev,*pact;

    fgets(cA,1000,stdin);
    fgets(cB,1000,stdin);

    for(pprev=prev; *pprev!='\n' && *pprev!='\0' ;pprev++);//get end of string
    --pprev;

    do{
	for(pact=act; *pact!='\n' && *pact!='\0' ;pact++); //get end of string
	--pact;

	//Check if they are equal
	char *a=pact;
	char *p=pprev;
	for( ; p!=prev && *p=='9' && *a=='0' ; --a,--p); //jump 99999
	if(*p=='9' && (*a!='0' || *(a-1)!='1')) error(prev,pprev,act);
	else if(*p!='9' && *p+1!=*a) error(prev,pprev,act);

	pprev=pact; //save end pointer for act
	
	pact=act;
	act=prev;  //set act as the older string
	prev=pact; //change prev to act
	
    } while(fgets(act,1000,stdin));

    return 0;
}
