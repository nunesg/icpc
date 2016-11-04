double cross(pv a, pv b){//produto vetorial (cross product)
	// a e b sao vetores
	return    a.x*b.y - a.y*b.x;
}

bool ccw(pv a, pv b, pv c){//true se a, b, c nessa ordem estao em sentido anti-horario
	return cross(b-a, c-a) > 0.0;
}

bool colinear(pv a, pv b, pv c){//true se a, b, c sao colineares
	return cross(b-a, c-a) == 0.0;
}

double dot(pv a, pv b){//produto escalar (dot product)
	// a e b sao vetores
	return a.x*b.x + a.y*b.y;// se a e b sao o mesmo vetor, o resultado vai ser a norma de a ao quadrado: |a|^2
}

bool multiplos(pv a, pv b){//retorna true false se os vetores forem multiplos entre si
	if(a.x == b.x && a.x == 0.0) return true;
	if(a.y == b.y && a.y == 0.0) return true;
	return (b.x != 0.0 && b.y != 0.0 && (a.x/b.x == a.y / b.y)); 
}
