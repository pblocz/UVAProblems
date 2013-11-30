//#include "longnum.hpp"
#include "../multiprecision-integer2.hpp"
#include <iostream>

using namespace std;


int main(){
    bigint l=10,c=BASE-1;

    cout << c.str()<<"^2=";
    cout <<(c*(BASE-1)).str() << endl;

    cout << ((c<<1) + 10).str() << endl;

    // for(int i=0; i< 20; i++){
    // 	cout << (l*l).used << ": ";
    // 	(l*l).show();
    // 	cout << endl;
    // 	l=l*10;
    // }
    
    return 0;
}
