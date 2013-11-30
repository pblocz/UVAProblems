#include <cstdio>

#include <complex>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef double ld;

const ld inf=1e9;
const ld eps=1e-9;
const ld pi=acos(-1.0);

//represento los puntos como complex
typedef complex<ld> point, vect;

struct line {
	ld a; ld b; //coeficientes x, y
	ld c; //termino independiente
};

typedef pair<point, point> segment;

typedef struct {
	point center; ld radius;
} circle;

typedef vector<point> polygon; typedef polygon::iterator polIter;


line pointsToLine(point a, point b) {
	line result;
	result.a=b.imag()-a.imag();
	result.b=a.real()-b.real();
	result.c=a.imag()*b.real()-a.real()*b.imag();
	return result;
}


point closestPoint(line l, point p) {
	ld d=l.a*l.a+l.b*l.b;
	point result( (l.b*l.b*p.real()-l.a*l.c-l.a*l.b*p.imag())/d ,
		(l.a*l.a*p.imag()-l.b*l.c-l.a*l.b*p.real())/d );
	return result;
}

point intersection(line r, line s) {
	ld den=r.b*s.a-r.a*s.b;
	point result( (r.c*s.b-r.b*s.c)/den , (r.a*s.c-r.c*s.a)/den );
	return result;
}


pair<bool,point> intersectSeg(pair<point,point> a,pair<point,point> b){
    line A(pointsToLine(a.first,a.second)),B(pointsToLine(b.first,b.second));
    if(A.a*B.b==A.b*B.a) return pair<bool,point>(false,a.first);
    point inters(intersection(A,B));
    if(norm(a.first-a.second)<norm(a.first-inters)||norm(a.first-a.second)<norm(a.second-inters)){
	// not in first segment
	return pair<bool,point>(false,inters);
    }

    if(norm(b.first-b.second)<norm(b.first-inters)||norm(b.first-b.second)<norm(b.second-inters)){
	// not in second segment
	return pair<bool,point>(false,inters);
    }
    return pair<bool,point>(true,inters);
}


int main(){
    int cases; scanf("%i",&cases); const char* str="";
    while(cases--){
	int N,ninters=0; scanf("%i",&N);
	vector<pair<point,point> > v;
	while(N--){
	    double a1,a2,b1,b2;
	    scanf("%lf%lf%lf%lf",&a1,&a2,&b1,&b2);
	    v.push_back(pair<point,point>(point(a1,a2),point(b1,b2)));
	}
	for(int i=0;i<v.size();++i) for(int j=i+1;j<v.size();++j) ninters+=intersectSeg(v[i],v[j]).first;
	printf("%s%lu\n",str,ninters*2+v.size()); str="\n";
    }
    return 0;
}

/// Local Variables:
/// compile-command: (concat "g++ -O3 " (buffer-name))
/// End:
