#include<iostream>
#include<vector>
#include<climits>
#include<set>

using namespace std;

vector<vector<int>> adj;

int main() {
	int nv, ne, u, v, d, n;
	scanf("%d %d", &nv, &ne);
	adj.resize(nv + 1);
	for (int i = 1; i <= nv; i++) {
		adj[i].resize(nv + 1);
	}
	for (int i = 0; i < ne; i++) {
		scanf("%d %d %d", &u, &v, &d);
		adj[u][v] = adj[v][u] = d;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		vector<int> givenPath(nv);
		for (int j = 0; j < nv; j++)
			scanf("%d", &givenPath[j]);

		int from = givenPath[0], to = givenPath[nv - 1];
		vector<int> dist(nv + 1, INT_MAX), visited(nv + 1, 0);
		vector<vector<int>> pre(nv + 1);
		vector<vector<int>> allSet;
		bool flag = true;
		int givenPathCnt = 0;
		dist[from] = 0;
		for (int k = 0; k < nv; k++) {
			int min = INT_MAX, idx = -1;
			for (int t = 1; t <= nv; t++) {
				if (visited[t]) continue;
				if (dist[t] < min) {
					min = dist[t];
					idx = t;
				}
				else if (dist[t] == min && t == givenPath[givenPathCnt]) {
					idx = t;
				}
			}
			if (idx != givenPath[givenPathCnt]) {
				flag = false;
				break;
			}
			visited[idx] = 1;
			givenPathCnt++;
			for (int t = 1; t <= nv; t++) {
				if (!adj[idx][t]) continue;
				if (adj[idx][t] + min < dist[t]) {
					dist[t] = adj[idx][t] + min;
					pre[t].clear();
					pre[t].push_back(idx);
				}
				else if (adj[idx][t] + min == dist[t]) {
					pre[t].push_back(idx);
				}
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}