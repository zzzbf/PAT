#include<iostream>
#include<vector>

using namespace std;

int main() 
{
	int nv, ne, u, v, nt, n;
	cin >> nv >> ne;
	vector<vector<bool>> adj(nv + 1, vector<bool>(nv + 1, false));
	for (int i = 0; i < ne; i++) {
		cin >> u >> v;
		adj[u][v] = adj[v][u] = true;
	}
	cin >> nt;
	for(int i = 0;i<nt;i++){
		cin >> n;
		vector<int> tmp(n), hash(nv + 1);
		for (int j = 0; j < n; j++) {
			cin >> tmp[j];
			hash[tmp[j]] = 1;
		}
		bool isClique = true;
		bool isMaximalClique = true;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) 
				if (!adj[tmp[j]][tmp[k]]) isClique = false;
		}
		if (isClique) {
			for (int j = 1; j <= nv; j++) {
				if (hash[j]) continue;
				int k;
				for (k = 0; k < n && adj[j][tmp[k]]; k++);
				if (k == n) 
					isMaximalClique = false;
			}
		}
		if (isClique&&isMaximalClique) printf("Yes\n");
		else if (isClique) printf("Not Maximal\n");
		else printf("Not a Clique\n");
	}
	return 0;
}