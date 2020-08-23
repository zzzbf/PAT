#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

vector<int> nodes, path;
int n;

void dfs(int num) {
	if (num * 2 > n) { // 遇到叶子结点说明该路径到尾了
		printf("%d", *path.begin());
		for (int i = 1; i < path.size(); i++) printf(" %d", path[i]);
		printf("\n");
	}
	else {
		if (num * 2 + 1 <= n) {
			path.push_back(nodes[num * 2 + 1]);
			dfs(num * 2 + 1);
			path.pop_back();
		}
		if (num * 2 <= n) {
			path.push_back(nodes[num * 2]);
			dfs(num * 2);
			path.pop_back();
		}
	}
}

int main() {
	scanf("%d", &n);
	nodes.resize(n+1);
	for (int i = 1; i <= n; i++) scanf("%d", &nodes[i]);
	path.push_back(nodes[1]);
	dfs(1);
	bool ismin = true, ismax = true;
	for (int i = 2; i <= n; i++) {
		if (nodes[i] < nodes[i / 2]) ismin = false;
		if (nodes[i] > nodes[i / 2]) ismax = false;
	}
	if (!ismin && !ismax) printf("Not Heap");
	else  printf("%s Heap", ismax ? "Max" : "Min");
	return 0;
}