/**
   \author Pablo Cabeza García

   Version 0.11.21
   
   Multiprecision integer library mainly for contests, and thus
   simplified to the maximum.
   
   For now, it has some major drawbacks:
   - doesn't have a division by multiprep-int
   - doesn't have a string constructor
   - only way to modify it is by copy constructor, doesn't have any
   internal modification operation.
   - more comments to make clearer the way it works.
 */

#include <cmath> //log10,floor
#include <cstring> //memset
#include <string> //string class
#include <sstream> //stringstream class
#include <algorithm> //max and min
using namespace std;

const int NUM=100; //number of elementes in array

typedef long long int base_t; //base type used
const base_t BASE=1000000000; //base for numbers, 10^9

struct bigint{
    bigint(long long int i=0) :used(0),sign((i>=0)?1:-1){
	memset(inner,0,NUM*sizeof(base_t));
	i*=sign;
	for(;i>=BASE;i=i/BASE)
	    inner[used++]=i%BASE;
	inner[used++]=i;
    }

    bigint operator+(bigint b) const{
	if(sign!=b.sign) return b.sign*=-1,((sign<0)?*this-b: b-*this);
	b.used=min(max(b.used,used)+1 , NUM); base_t carry=0;
	for(int i=0;i<b.used;i++){
	    carry=(b.inner[i]+=inner[i]+carry)/BASE;
	    b.inner[i]%=BASE;
	}
	while(b.used && !b.inner[b.used-1]) --b.used;
	return b;
    }

    bigint operator-(bigint b) const{
	bigint const *m=this,*M=&b;
	if(used>b.used || used==b.used && inner[used-1]>b.inner[used-1]) 
	    M=this,m=&b;
	if(b.sign!=sign) return b.sign*=-1,((*M)+(*m));
	bigint r(*M); base_t carry=0;
	for(int i=0;i<=min(m->used,NUM-1);i++)
	    carry=(r.inner[i]-=(m->inner[i]+carry))<0?r.inner[i]+=BASE,1:0;
       	while(r.used && !r.inner[r.used-1]) --r.used;
	return r;
    }

    bigint operator*(const bigint& b) const{
	bigint r;
	bigint const *m, *M= (used>b.used)? (m=&b,this) : (m=this,&b);
	for(int i=0;i<m->used; i++)
	    for(base_t j=0,carry=0 ; j<=(min(M->used,max(0,NUM-i-1))) ; j++){
		carry=(r.inner[j+i]=(M->inner[j]*(m->inner[i]))+carry)/BASE;
		r.inner[j+i]%=BASE;
	    }
        for(r.used=min(used+b.used,NUM);r.used&&!r.inner[r.used-1];--r.used);
	r.sign=sign*b.sign; 
	return r;
    }

    bigint operator/(base_t d) const{ return div(d).first;}
    base_t operator%(base_t d) const{ return div(d).second;}

    pair<bigint,base_t> div (base_t d) const{
	if(d<BASE) throw std::exception();
	pair<bigint,base_t> r(*this,0);
	for(int i=used-1;i>=0;i--){
       	    r.second=(r.first.inner[i]+=BASE*r.second)%BASE;
	    r.first.inner[i]/=BASE;
	}
	while(r.first.used && !r.first.inner[r.first.used-1]) --r.first.used;
	return r;
    }  

    string str() const{
	stringstream ss;
	ss << sign*inner[used-1];
	for(int i=used-2;i>=0;i--)
	    ss<< "00000000" + (int)(inner[i] ? floor(log10(inner[i])) : 0)
	      << inner[i];
	return ss.str();
    }

    char sign; //sign bit
    int used; //number of base_t in used
    base_t inner[NUM]; //base array
};

bigint operator+(long long int i, const bigint& l){ return l+i; }
bigint operator*(long long int i,const bigint& l){ return l*i; }
bigint operator-(long long int i,const bigint& l){ return bigint(i)-l;}
