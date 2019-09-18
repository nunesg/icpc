#include <bits/stdc++.h>

using namespace std;

#define N 444
#define inf 101010101

struct query{
	int a, b, id;
};

int n, m, q, adj[N][N], d[N][N], t[N], answer[N*N];
vector<query> Q[2][N];

void solve(int flag, auto f){
	
	vector<int> v;
	for(int i=1; i<=n; i++) v.push_back(i);
	
	sort(v.begin(), v.end(), f);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			d[i][j] = adj[i][j];
	
	int k=1;
	for(int x=0; x<n; x++){
		int u = v[x];
		k += (x && t[u]!=t[v[x-1]]);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				d[i][j] = min(d[i][j], d[i][u] + d[u][j]);
			}
		}
		for(auto qry : Q[flag][k]){
			answer[qry.id] = d[qry.a][qry.b];
		}
	}
	for(; k<=n; k++){
		for(auto qry : Q[flag][k]){
			answer[qry.id] = d[qry.a][qry.b];
		}
	}
}

int main(){
	
	scanf("%d %d", &n, &m);
	
	int a, b, c, op;
	
	for(int i=1; i<=n; i++)	scanf("%d", &t[i]);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			adj[i][j] = (i!=j) ? inf : 0;
		}
	}
	
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = min(adj[a][b], c);
		adj[b][a] = adj[a][b];
	}
	
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d %d %d %d", &a, &b, &c, &op);
		Q[op][c].push_back({a, b, i});
	}
	
	solve(0, [](int a, int b){
		return t[a] < t[b];
	});
	
	solve(1, [](int a, int b){
		return t[a] > t[b];
	});
	
	for(int i=0; i<q; i++) printf("%d\n", answer[i] == inf ? -1 : answer[i]);
	
}
