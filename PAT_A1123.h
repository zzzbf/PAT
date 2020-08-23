#include<iostream>
#include<queue>

using namespace std;

struct node
{
	int key;
	struct node *lchild, *rchild;
};

int GetHeight(node *node) {
	if (node == NULL) return 0;
	int lh = GetHeight(node->lchild);
	int rh = GetHeight(node->rchild);
	return max(lh, rh) + 1;
}

void LevelOrder(node *root)
{
	node *p = NULL;
	queue<node*> nodes;
	if (root == NULL) return;
	nodes.push(root);
	while (!nodes.empty()) {
		p = nodes.front();
		nodes.pop();
		printf("%d", p->key);
		if (p->lchild) {
			nodes.push(p->lchild);
		}
		if (p->rchild) {
			nodes.push(p->rchild);
		}
		if (nodes.empty()) printf("\n");
		else printf(" ");
	}
}

void IsComplete(node *root)
{
	node *p = NULL;
	bool complete = true;
	bool nullTag = false;
	queue<node*> nodes;
	if (root == NULL) return;
	int currentCount = 1;
	nodes.push(root);
	while (!nodes.empty()) {
		p = nodes.front();
		nodes.pop();
		if (p == NULL) {
			nullTag = true;
			continue;
		}
		if (nullTag) complete = false;
		nodes.push(p->lchild);
		nodes.push(p->rchild);
	}
	if (complete) printf("YES");
	else printf("NO");
}

node *leftRotate(node *root) {
	node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	return temp;
}
node *rightRotate(node *root) {
	node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	return temp;
}
node *rightLeftRotate(node *root) {
	root->rchild = rightRotate(root->rchild);
	return leftRotate(root);
}
node *leftRightRotate(node *root) {
	root->lchild = leftRotate(root->lchild);
	return rightRotate(root);
}
node *Insert(node *root, int key) {
	if (root == NULL) {
		root = new node();
		root->key = key;
	}
	else if(root->key>key){
		root->lchild = Insert(root->lchild, key);
		int lh = GetHeight(root->lchild), rh = GetHeight(root->rchild);
		if (lh - rh >= 2) {
			// ×ó×ó
			if (key < root->lchild->key) root = rightRotate(root);
			//×óÓÒ
			else root = leftRightRotate(root);
		}
	}
	else {
		root->rchild = Insert(root->rchild, key);
		int lh = GetHeight(root->lchild), rh = GetHeight(root->rchild);
		if (rh - lh >= 2) {
			// ÓÒÓÒ
			if (key > root->rchild->key) root = leftRotate(root);
			// ÓÒ×ó
			else root = rightLeftRotate(root);
		}
	}
	return root;
}

int main()
{
	int n, k;
	cin >> n;
	node *root(NULL);
	node *tp = NULL;
	for (int i = 0; i < n; i++) {
		cin >> k;
		root = Insert(root, k);
	}
	LevelOrder(root);
	IsComplete(root);
	return 0;
}