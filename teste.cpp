#include <bits/stdc++.h>

using namespace std;

struct pv{
	double x, y;
	pv() {x=y=0.0;}
	pv(double a, double b) : x(a), y(b) {}
	
	
	
};

struct circle{
	pv p;
	double r;
	circle(){p=pv(); r=0.0;}
	circle(pv a, double q) : p(a), r(q) {}
};

bool inside_circle(pv a, circle C){
	
	double c1_sq = (a.x - C.p.x)*(a.x - C.p.x);
	double c2_sq = (a.y - C.p.y)*(a.y - C.p.y);
	return (c1_sq + c2_sq) <= C.r*C.r;
	
}



int main(){
	double a, b, c;
	while(scanf("%lf %lf %lf", &a, &b, &c)){
		circle C = circle(pv(a, b), c);
		scanf("%lf %lf", &a, &b);
		printf("%c\n", (inside_circle(pv(a, b), C)) ? 'I' : 'O');
	}
}
