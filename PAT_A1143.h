#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	int m, n, u, v;
	cin >> m >> n;
	vector<int> nodes(n);
	unordered_map<int, bool> hash;
	for (int i = 0; i < n; i++) {
		cin >> nodes[i];
		hash[nodes[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (!hash[u] && !hash[v]) printf("ERROR: %d and %d are not found.\n", u, v);
		else if (!hash[u] || !hash[v]) printf("ERROR: %d is not found.\n", hash[u] ? v : u);
		else {
			for (int j = 0; j < n; j++) {
				if ((u >= nodes[j] && v <= nodes[j]) || (u <= nodes[j] && v >= nodes[j])) {
					if (u == nodes[j] || v == nodes[j]) 
						printf("%d is an ancestor of %d.\n", nodes[j] == u ? u : v, nodes[j] == u ? v : u);
					else printf("LCA of %d and %d is %d.\n", u, v, nodes[j]);
					break;
				}
			}
		}
	}
	return 0;
}