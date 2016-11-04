#include <bits/stdc++.h>


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

bool multiplos(pv a, pv b){
	if(a.x == b.x && a.x == 0.0) return true;
	if(a.y == b.y && a.y == 0.0) return true;
	return (b.x != 0.0 && b.y != 0.0 && (a.x/b.x == a.y / b.y)); 
}

bool in_line(pv p, line l){//checa se o ponto p está na reta l
	
	pv v = l.vec, p0 = l.p0;
	
	if(v.x == 0.0) return ( p.x == p0.x );
	if(v.y == 0.0) return ( p.y == p0.y );
	
	double a = (p.x - p0.x)/v.x;
	double b = (p.y - p0.y)/v.y;
	
	return a == b;
	
}

int line_intersection(line l1, line l2, pv& c){// retorna 0 se as retas se cruzam, 1 se sao as mesmas, 2 se sao paralelas
	
	pv u = l1.vec, v = l2.vec;
	pv p1 = l1.p0, p2 = l2.p0;
	int flag = multiplos(u, v);
	if(flag){
		if(in_line(p1, l2)) return 1;
		return 2;
	}
	
	double   a = (p2.x - p1.x)  ,  b = (p2.y - p1.y);
	
	double teta = (u.x*b - u.y*a) / cross(v, u);
	c = p2 + (v*teta);//precisa do parentese pq os operators de struct nao tem prioridade
	return 0;
	
}


int main(){
	int n;
	double a, b, c, d;
	line L1, L2;
	pv aux;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--){
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		L1 = line(pv(a, b), pv(c, d) - pv(a, b));
		
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		L2 = line(pv(a, b), pv(c, d) - pv(a, b));
		
		int flag = line_intersection(L1, L2, aux);
		if(!flag) printf("POINT %.2lf %.2lf\n", aux.x, aux.y);
		else if(flag == 1) printf("LINE\n");
		else printf("NONE\n");
		
	}
	printf("END OF OUTPUT\n");
}
