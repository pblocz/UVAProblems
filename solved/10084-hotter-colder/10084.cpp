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

ld darea(point a, point b, point c) {			// | a.x a.y 1 |
	return imag(conj(a)*b+conj(b)*c+conj(c)*a);	// | b.x b.y 1 |
}							// | c.x c.y 1 |

point intersectSeg(point p, point q, point a, point b) {
	ld u = abs(imag(conj(a-b)*p-b*conj(a)));
	ld v = abs(imag(conj(a-b)*q-b*conj(a)));
	return (p*v + q*u) / (u+v);
}

polygon cutPolygon(point a, point b, polygon &p) {
	polygon q;
	for (int i = 0; i < p.size(); i++) {
		ld left1 = darea(a, b, p[i]);
		ld left2 = darea(a, b, p[(i + 1)%p.size()]);
		if (left1 > -eps) q.push_back(p[i]);
		if (left1*left2 < -eps)
			q.push_back(intersectSeg(p[i],p[(i+1)%p.size()],a,b));
	}
	return q;
}

line perpendicular(line l, point p) {
	line result;
	result.a=-l.b;
	result.b=l.a;
	result.c= l.b*p.real()-l.a*p.imag();
	return result;
}

ld area(polygon &p) { //REVISAR (bastante seguro)
	ld result=0.0;
	for (int i=0; i<p.size(); i++) 
		result+=imag(conj(p[i])*p[(i+1)%p.size()]);
	return abs(result) / 2.0;
}



#define SKIPLINE() (while(getchar()!='\n')) 
const point square[]={point(0,0),point(10,0),point(10,10),point(0,10)};
const point I(0,1);

int main(){
    polygon pol(square,square+4); double a1,a2; point prev,cur(0,0); char c[7]; bool done=false;
    while(scanf("%lf %lf %s\n",&a1,&a2,c)!=EOF){
	if(done){ printf("%.2f\n",0.0); continue; }

	prev=cur; cur=point(a1,a2); 
	point mid=prev+(cur-prev)/2.0, aux(mid+(prev-mid)*I);

	// cout << "prev:"<<prev <<" cur:" << cur << " mid:"<<mid<<" aux:" << aux << endl;
	if(cur==prev);
	else if(c[0]=='C') pol=cutPolygon(aux,mid,pol);
	else if(c[0]=='H') pol=cutPolygon(mid,aux,pol);
	else{ (done=true);printf("%.2f\n",0.0);continue; }
	
	printf("%.2lf\n",area(pol));
    }
    return 0;
}

/// Local Variables:
/// compile-command: (concat "g++ -O3 " (buffer-name))
/// End:
