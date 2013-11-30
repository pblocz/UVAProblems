//#include "longnum.hpp"
#include "../multiprecision-integer2.hpp"
#include <iostream>

using namespace std;


int main(){
    bigint l=0;
    int beg=l.used; 

    while(l.used!=2){
    	l+=1;
	
	//if(l.used!=beg){
	//    beg=l.used;
	//cout << l.used << " : ";
	cout << l.str() << '\n';
	    //º}
    }
    
    return 0;
}
