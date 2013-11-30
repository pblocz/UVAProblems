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
}

							// | c.x c.y 1 |

bool menorX(point p1, point p2) {
	point aux=p1-p2; 
	if(abs(aux.real())<eps) return aux.imag()<-eps;
	return aux.real()<-eps;
}



polygon convexHull(polygon &p) { //REVISAR (99.99% de probabilidad de estar bien).
	int n=p.size();
	polygon ch;
	sort(p.begin(),p.end(), menorX);

	for(int i=1-n; i<n; i++){
		while(ch.size()>1 && //poner <0, <=0, <eps o <-eps segun veas. 
			darea(ch[ch.size()-2],ch.back(), p[abs(i)])<0)
				ch.pop_back();
		ch.push_back(p[abs(i)]);
	}

	if(n!=1) ch.pop_back();
	return ch;
}

ld perimeter(polygon &p) {
	ld result=0.0;
	for (int i=0; i<p.size(); i++)
		result+=abs(p[i]-p[(i+1)%p.size()]);
	return result;
}

int main(){
    int traps,c=0; const char* str="";
    while(scanf("%i",&traps),traps){
	polygon pol;
	while(traps--){ double a,b; scanf("%lf%lf",&a,&b); pol.push_back(point(a,b)); }
	pol=convexHull(pol); const char* sep="";

	printf("%sRegion #%i:\n",str,++c); str="\n";
	for(polygon::reverse_iterator it=pol.rbegin();it!=pol.rend();++it){
	    printf("%s(%.1lf,%.1lf)",sep,it->real(),it->imag()); sep="-"; }
	printf("%s(%.1lf,%.1lf)\n",sep,pol.back().real(),pol.back().imag()); 
	printf("Perimeter length = %.2lf\n",perimeter(pol));
    }
    return 0;
}

/// Local Variables:
/// compile-command: (concat "g++ -O3 " (buffer-name))
/// End:
