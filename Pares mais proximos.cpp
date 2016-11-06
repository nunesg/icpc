
/*
 * 
 * 				PROBLEMA DOS PARES MAIS PROXIMOS
 * 
 */



/*

 Ordena os pontos por x antes.
 vetor de pontos P.
 
*/


double Closest_Pair(){
	
	set<pv> L;//Sweep Line
	L.insert(P[0]);
	double d = 10000000.0;//valor pra servir como inf
	
	for(int i=1; i<P.size(); i++){
		
		
		for(set<pv>::iterator it = L.begin(); it!=L.end(); it++){
			pv aux = *it;
			if(fabs(aux.x-P[i].x) >= d) L.erase(it);
		}
		
		
		for(set<pv>::iterator it = L.lower_bound(pv(P[i].x, P[i].y-d)); it!=L.end(); it++){
			pv aux = *it;
			
			if(fabs(aux.y-P[i].y)<=d) d = min(d, dist(P[i], aux));
			else break;
		}
		
		L.insert(P[i]);
		
	}
	
	return d;
	
}
