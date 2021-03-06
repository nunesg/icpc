/*

	ROTATING CALIPERS ALVARO

*/


int rotatingCalipers(vector<point> &up, vector<point> &dn){
	int ans = 0;
	
	int i = 0, j = dn.size()-1; 
	
	while(i < (int)up.size() - 1 || j > 0){
		// Entrou aqui: up[i] e dn[j] eh um antipodal pair
		ans = max(ans, dist2(up[i],dn[j]));
		
		if(i == (int)up.size()-1) j--;
		else if(j == 0) i++;
		else{
			// Verifica qual o menor angulo a ser rotacionado p utilizar na rotacao
			if((up[i+1].y - up[i].y) * (dn[j].x - dn[j-1].x)
				> (dn[j].y - dn[j-1].y) * (up[i+1].x - up[i].x ))
				i++;
			else
				j--;
		}
	}
	return ans;
}
