
/*
 * 				STRUCTS DE RETA E SEGMENTO DE RETA
 * 
 */




struct line{
	/*
	
		Reta no tratamento vetorial. Obedece a equação: X = p0 + u*V
		
		p0: ponto inicial da reta
		V: vetor diretor da reta
		
		onde um ponto X pertence a reta se existe um escalar > u < que satisfaz a equação.
		
		A equacao acima pode ser desmembrada em 2(ou 3 se estiver no espaço tridimensional) equações paramétricas:
		
		x = x0 + u*V.x
		y = y0 + u*V.y

		Se o sistema puder ser resolvido com duas coordenadas x e y, significa que o ponto (x, y) pertence à reta
	  
	*/
	
	pv p0, vec;//p: p0 da formula acima.  vec: V da fórmula acima
	line(){p0=vec=pv();}
	line(pv a, pv u) : p0(a), vec(u) {}
};




struct seg{//segmento de reta
	pv a, b;
	seg(){a=b=pv();}
	seg(pv i, pv j) : a(i), b(j) {}
};
