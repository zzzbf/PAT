#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cstring>

using namespace std;

unordered_map<int, int> parent;
int rank1[10000];

int Find(int a) {
	if (parent.find(a) == parent.end()) return parent[a] = a;
	if (parent[a] != a) return parent[a] = Find(parent[a]);
	return a;
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (rank1[pa] > rank1[pb]) parent[pb] = pa;
	else {
		parent[pa] = pb;
		if (rank1[pa] == rank1[pb] && pa != pb) rank1[pb]++;
	}
}
int main()
{
	int n, num, tmp;
	memset(rank1, 0, sizeof(rank1));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int nn;
		scanf("%d", &nn);
		scanf("%d", &num);
		if (parent.find(num) == parent.end()) parent[num] = num; // ¿Óµã
		for (int j = 1; j < nn; j++) {
			scanf("%d", &tmp);
			Union(num, tmp);
		}
	}
	unordered_set<int> parents;
	for (auto it = parent.begin(); it != parent.end(); it++) 
		parents.insert(Find(it->first));
	printf("%d %d\n", parents.size(), parent.size());
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &num, &tmp);
		if (Find(num) != Find(tmp)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}