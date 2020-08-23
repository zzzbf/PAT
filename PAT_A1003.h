#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int MAXV = 510;
const int INF = 0X3FFFFFFF;

struct Node{
	int v, dis;
	Node(int _v, int _dis) :v(_v), dis(_dis) {}
};

vector<Node> adj[MAXV];

int n, m, st, ed, weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];

set<int> pre[MAXV];

void Bellman(int s) {
	fill(d, d + MAXV, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;

	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < adj[u].size(); j++) {
				int v = adj[u][j].v, dis = adj[u][j].dis;
				if (d[u] + dis < d[v]) {
					d[v] = d[u] + dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + dis == d[v]) {
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;
					for (auto it = pre[v].begin(); it != pre[v].end(); it++)
						num[v] += num[*it];
				}
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
	int u, v, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &wt);
		adj[u].push_back(Node(v, wt));
		adj[v].push_back(Node(u, wt));
	}
	Bellman(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}

