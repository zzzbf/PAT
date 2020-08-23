#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> in, post;

struct node {
	int key, depth;
	node *lchild, *rchild;
};

node *createTree(int inl, int inr, int postl, int postr) {
	if (inl > inr) return NULL;
	int i;
	node* root = new node();
	root->key = post[postr];
	for (i = inl; i <= inr; i++) 
		if (in[i] == root->key) break;
	int leftNum = i - inl;
	root->lchild = createTree(inl, i - 1, postl, postl + leftNum - 1);
	root->rchild = createTree(i + 1, inr, postl + leftNum, postr - 1);
	return root;
}
void bfs(node* root) {
	queue<node*> q;
	vector<vector<node*>> v(1);
	q.push(root);
	int currentCnt = 1, nextCnt = 0, i = 0, depth = 0;
	while (!q.empty()) {
		node* tmp = q.front();
		v[depth].push_back(tmp);
		q.pop();
		i++;
		if (tmp->lchild) {
			q.push(tmp->lchild);
			nextCnt++;
		}
		if (tmp->rchild) {
			q.push(tmp->rchild);
			nextCnt++;
		}
		if (i == currentCnt) {
			depth++;
			currentCnt = nextCnt, i = 0, nextCnt = 0;
			v.resize(v.size() + 1);
		}
	}
	printf("%d", v[0][0]->key);
	for (int i = 1; i < v.size(); i++) {
		if (i % 2) 
			for (auto it = v[i].begin(); it != v[i].end(); it++)
				printf(" %d", (*it)->key);
		else
			for (auto it = v[i].rbegin(); it != v[i].rend(); it++)
				printf(" %d", (*it)->key);
	}
}

int main()
{
	int n;
	cin >> n;
	in.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> post[i];
	node *tree = createTree(0, n - 1, 0, n - 1);
	bfs(tree);
	return 0;
}