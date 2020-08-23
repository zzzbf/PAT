#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct edge { int a, b; };

int main() {
	int n, m, nt;
	scanf("%d %d", &n, &m);
	vector<edge> edges(m);
	vector<int> colors(n);
	for (int i = 0; i < m; i++) scanf("%d %d", &edges[i].a, &edges[i].b);
	scanf("%d", &nt);
	for (int i = 0; i < nt; i++) {
		set<int> se;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			scanf("%d", &colors[j]);
			se.insert(colors[j]);
		}
		for (int j = 0; j < m; j++) {
			if (colors[edges[j].a] == colors[edges[j].b]) {
				flag = false;
				break;
			}
		}
		if(flag) printf("%lu-coloring\n", se.size());
		else printf("No\n");
	}
	return 0;
}