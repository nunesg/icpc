bool center_circum_circle(pv o, pv p, pv q, pv &c){
	
	if(colinear(o, p, q)) return false;
	
	pv meio_op = o + ((p-o)*0.5);
	pv perp_op = perp_vec(p-o);
	line l1 = line(meio_op, perp_op);//mediatriz do segmento op
	
	pv meio_pq = p + ((q-p)*0.5);
	pv perp_pq = perp_vec(q-p);
	line l2 = line(meio_pq, perp_pq);//mediatriz do segmento pq
	
	line_intersection(l1, l2, c);
	return true;
}

bool center_in_circle(pv a, pv b, pv c, pv &ans){
	if(colinear(a, b, c)) return false;
	
	line l1 = bissetriz(a, b, c);
	line l2 = bissetriz(b, c, a);
	
	line_intersection(l1, l2, ans);
	return true;
}
