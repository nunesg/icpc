



/*
 * 
 * 			FUNCOES RELAICONADAS A RETAS
 * 
 */






double dist_line(pv p, pv a, pv b){//distancia de p à reta formada por a e b
	//p a e b sao pontos
	return fabs( cross(p-a, b-a) ) / dist(a, b);
}




double dist_seg(pv p, seg ab){//distancia de p ao segmento ab
	pv a = ab.a, b = ab.b;
	double u = u = dot(p-a, b-a) / dot(b-a, b-a);
	
	if(u<=0.0) return dist(p, a);
	if(u>=1.0) return dist(p, b);
	return dist_line(p, a, b);
}




pv projecao(pv p, pv a, pv b){//projecao de p na reta ab
	double u = dot(p-a, b-a) / dot(b-a, b-a);
	return a + ( (b-a)*u );
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

	int flag = multiplos(u, v);//verifica se os vetores u e v sao multiplos ja eliminando erros de divisao por zero
	
	if(flag){	
		if(in_line(p1, l2)) return 1;//retas sao iguais
		return 2;//retas paralelas
	}
	
	double   a = (p2.x - p1.x)  ,  b = (p2.y - p1.y);
	
	double teta = (u.x*b - u.y*a) / cross(v, u);//se u e v nao forem multiplos, entao cross!=0
	c = p2 + (v*teta);//precisa do parentese pq os operators de struct nao tem prioridade
	return 0;
	
}



line bissetriz(pv a, pv o, pv c){
	pv u = a-o, v = c-o;
	
	u = unit_vec(u);
	v = unit_vec(v);
	
	u = u+v;
	return line(o, u);
}




line mediatriz(pv a, pv b){
	pv v = unit_vec( perp_vec(b-a) );
	return line(a+((b-a)*0.5), v );
}

