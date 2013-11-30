// Usando la libreria paco de geometría
#include <cstdio>

#include <complex>
#include <vector>
#include <algorithm>
#include <limits>


typedef long double ld;

struct line {
	ld a; ld b; //coeficientes x, y
	ld c; //termino independiente
};

typedef std::complex<ld> point, vect;

typedef std::pair<point, point> segment;

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

point closestToSegment(point a,point b,point M){
    line l=pointsToLine(a,b);
    point p=closestPoint(l,M);
    if(norm(b-a)<norm(b-p) || norm(b-a)<norm(a-p)){ // not in the segement
	if(norm(a-M)>norm(b-M)) return b;
	else return a;
    }
    return p;
}

int main(){
    long double a1,a2;
    while(scanf("%Lf%Lf",&a1,&a2)!=EOF){
	point M(a1,a2),sol; int points; scanf("%i",&points);
	double dist=std::numeric_limits<double>::infinity();
	std::vector<point> v;
	for(int i=0;i<=points;++i){ 
	    scanf("%Lf%Lf",&a1,&a2); v.push_back(point(a1,a2)); }
	
	for(int i=0;i<points;++i){
	    point res=closestToSegment(v[i],v[i+1],M);
	    if(norm(res-M)<dist){ dist=norm(res-M); sol=res; }
	}
	printf("%.4Lf\n%.4Lf\n",sol.real(),sol.imag());
    }
    return 0;
}
