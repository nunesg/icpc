#include <bits/stdc++.h>

using namespace std;

struct pv{ // pv porque eh uma struct pra ponto e vetor.

	double x, y;
	pv(){x=y=0.0;}
	pv(double a, double b) : x(a), y(b) {}
	
	pv operator - (pv g){ // subtrai dois pontos A e B criando o vetor AB
	
		return pv(x-g.x, y-g.y);
	}
	
	pv operator + (pv u){ // anda com o ponto no vetor u
	
		return pv(x+u.x, y+u.y);
	}
	
	pv operator * (double k){ //multiplicacao do vetor por um escalar k
		return pv(x*k, y*k);
	}
	
	bool operator < (pv g) const{ //operator < pra pontos. Necessario pra ordenar ocm a funcao sort
		if(g.x != x) return x < g.x;
		return y < g.y;
	}

};

struct line{
	pv p0, vec;//p: p0 da formula acima.  vec: V da fórmula acima
	line(){p0=vec=pv();}
	line(pv a, pv u) : p0(a), vec(u) {}
};

double cross(pv a, pv b){ return a.x*b.y - a.y*b.x; }

pv perp_vec(pv u){
	return pv(u.y, -u.x);
}


int main(){
	int n;
	cin >> n;
	double a, b;
	pv c, d;
	for(int i=0; i<n; i++){
		scanf("%lf %lf", &a, &b); c = pv(a, b);
		scanf("%lf %lf", &a, &b); d = pv(a, b);
		c = perp_vec(d-c);
		printf("Perpendicular: (%.0lf, %.0lf)\n", c.x, c.y);
	}
}
