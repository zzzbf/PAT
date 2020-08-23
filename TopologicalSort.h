#include<iostream>
#include<queue>
#include<stack>

#define MAXV 512

using namespace std;

struct Node {
	int v, w;
};
int n, inDegree[MAXV];
vector<Node> G[MAXV];
stack<int> topOrder;

int ve[MAXV], vl[MAXV];

bool topologicalSort() {
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (inDegree[i] == 0) q.push(i);
	ve[q.front()] = 0;
	while (!q.empty()) {
		int u = q.front();
		topOrder.push(u);
		q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			inDegree[v]--;
			if (inDegree[v] == 0) q.push(v);
 			if (G[u][i].w + ve[u] > ve[v]) ve[v] = G[u][i].w + ve[u];
		}
		//G[u].clear();
	}
	if (topOrder.size() == n) return true;
	return false;
}

int CriticalPath() {
	if (topologicalSort() == false) return -1;
	vl[topOrder.top()] = ve[topOrder.top()];
	fill(vl, vl + n, ve[topOrder.top()]);
	while (!topOrder.empty()) {
		int u = topOrder.top();
		topOrder.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			if (vl[v] - G[u][i].w < vl[u])
				vl[u] = vl[v] - G[u][i].w;
		}
	}
	for (int u = 0; u < n; u++) {
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v, w = G[u][i].w;
			int e = ve[u], l = vl[v] - w;
			if (e == l) printf("%d->%d\n", u, v);
		}
	}
	return ve[n - 1];
}

int main() {
	int m, u, v, w;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		inDegree[v]++;
		G[u].push_back({ v,w });
	}
	CriticalPath();
	return 0;
}
/*
11
15
0 1 3
0 2 4
1 3 2
1 4 1
2 5 5
2 4 3
4 6 8
3 6 6
4 7 4
2 5 5
7 9 4
5 8 2
7 8 10
8 9 1
9 10 6
*/