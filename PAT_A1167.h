#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

typedef struct node {
	int data;
	struct node *lchild, *rchild;
}node;

unordered_map<int, int> mp;

node* build(vector<int> &nodes, int low, int high) {
	if (low > high) return NULL;
	vector<int> tmp = nodes;
	//sort(tmp.begin() + low, tmp.begin() + high + 1);
	sort(tmp.begin(), tmp.end());
	int data = tmp[low], mid = mp[data];
	node *root = new node();
	root->data = data;
	root->lchild = build(nodes, low, mid - 1);
	root->rchild = build(nodes, mid + 1, high);
	return root;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> nodes(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nodes[i]);
		mp[nodes[i]] = i;
	}
	node *root = build(nodes, 0, n - 1);
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		printf("%d", q.front()->data);
		if (q.front()->lchild) q.push(q.front()->lchild);
		if (q.front()->rchild) q.push(q.front()->rchild);
		q.pop();
		printf("%s", q.empty() ? "" : " ");
	}
	return 0;
}