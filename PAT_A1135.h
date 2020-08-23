#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct node {
	int val;
	node *left, *right;
};

node *Insert(int val, node *root)
{
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	else if (abs(val) <= abs(root->val))
		root->left = Insert(val, root->left);
	else
		root->right = Insert(val, root->right);
	return root;
}

bool preOrderJudge(node* root, int blackCnt, set<int> &cnt) {
	if (root == NULL) {
		cnt.insert(blackCnt);
		return true;
	}
	
	if(root->val<0 && ((root->right && root->right->val<0)|| 
		(root->left && root->left->val < 0))) return false;
	if (preOrderJudge(root->left, root->val < 0 ? blackCnt : blackCnt + 1, cnt))
		return preOrderJudge(root->right, root->val < 0 ? blackCnt : blackCnt + 1, cnt);
	return false;
}

int main()
{
	int testN, nodesN, val;
	cin >> testN;
	for (int i = 0; i < testN; i++) {
		cin >> nodesN;
		node* root = NULL;
		set<int> cnt;
		for (int j = 0; j < nodesN; j++) {
			cin >> val;
			root = Insert(val, root);
		}
		// 根结点必须为黑结点
		// 红色结点的孩子为黑色结点
		// 所有路径有相同数量的黑色结点

		bool flag = preOrderJudge(root, 0, cnt);
		printf("%s\n", root->val > 0 && flag && cnt.size() == 1 ? "Yes" : "No");
	}
	return 0;
}