

/*
 * 
 * 			DISTANCIAS E ANGULOS
 * 
 */


double dist(pv a, pv b){//distancia euclidiana
	//a e b sao pontos
	return hypot(a.x - b.x, a.y - b.y);
}

double angulo(pv a, pv o, pv b){//retorna o angulo em radianos entre a e b centrado em o
	pv oa = a-o, ob = b-o;
	return acos( dot(oa, ob) / sqrt( dot(oa, oa) * dot(ob, ob) ) );	
}
