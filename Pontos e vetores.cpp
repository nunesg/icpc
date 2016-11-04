//estrutura de um ponto 2D. 3D é a mesma coisa porém com o parâmetro z a mais

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
