#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct node { int key, l, r, level; };

vector<node> nodes;
vector<int> keys;
int cnt = 0;

void createTree(int root, int level) {
	if (root != -1) {
		createTree(nodes[root].l, level + 1);
		nodes[root] = { keys[cnt++], nodes[root].l, nodes[root].r, level };
		createTree(nodes[root].r, level + 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	nodes.resize(n);
	keys.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &nodes[i].l, &nodes[i].r);
	for (int i = 0; i < n; i++) 
		scanf("%d", &keys[i]);
	sort(keys.begin(), keys.end());
	createTree(0, 0);
	sort(nodes.begin(), nodes.end(), [](node a, node b) {
		return a.level == b.level ? a.key < b.key : a.level < b.level; 
	});
	printf("%d", nodes.begin()->key);
	for (int i = 1; i < nodes.size(); i++)
		printf(" %d", nodes[i].key);
	return 0;
}