#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	vector<int> children;
};
vector<int> book;

void dfs(vector<node> &family, int id, int level) {
	if (level >= book.size()) book.push_back(0);
	book[level]++;
	for (int i = 0; i < family[id].children.size(); i++) 
		dfs(family, family[id].children[i], level + 1);
}

int main()
{
	int n, m, k, id;
	cin >> n >> m;
	vector<node> family(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> id >> k;
		family[id].children.resize(k);
		for (int j = 0; j < k; j++)
			cin >> family[id].children[j];
	}
	dfs(family, 1, 0);
	int ans = 0, level;
	for (int i = 0; i < book.size();i++) {
		if (book[i] > ans) {
			ans = book[i];
			level = i;
		}
	}
	printf("%d %d", ans, level + 1);
	return 0;
}