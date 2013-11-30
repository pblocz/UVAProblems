#include <iostream>
#include "../multiprecision-integer2.hpp"

using namespace std;

int main(){
    bigint l=(-10),ll=6,y=-3,j=4;
    
    cout << (l+ll).str();
    cout << endl <<
    (l-ll).str();
    cout << endl<<
    (l+y).str();
    cout << endl<<
    (l-y).str();
    cout << endl<<
    (ll+y).str();
    cout << endl<<
    (ll-y).str();
    cout << endl<<
    (0-l).str();
    cout << endl;
}
