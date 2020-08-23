#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node {
	string data;
	int lchild, rchild;
};

vector<node> nodes;

string postOrder(int root) {
	if (root == -1) return "";
	int lchild = nodes[root].lchild, rchild = nodes[root].rchild;
	//if (lchild == -1 && rchild == -1)
	//	return nodes[root].data;
	if (lchild != -1 && rchild != -1)
		return "(" + postOrder(lchild) + postOrder(rchild) + nodes[root].data + ")";
	else //if (rchild != -1)
		return "(" + nodes[root].data + postOrder(rchild) + ")";
	//else
	//	return "(" + postOrder(lchild) + nodes[root].data + ")";
}

int main() {
	int n, root;
	scanf("%d", &n);
	vector<bool> isRoot(n + 1, true); 
	nodes.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i].data >> nodes[i].lchild >> nodes[i].rchild;
		//if (nodes[i].data != "+" && nodes[i].data != "-" &&nodes[i].data != "%" && nodes[i].data != "*")
		//	nodes[i].data = "(" + nodes[i].data + ")";
		if (nodes[i].lchild != -1) isRoot[nodes[i].lchild] = false;
		if (nodes[i].rchild != -1) isRoot[nodes[i].rchild] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (isRoot[i]) {
			root = i;
			break;
		}
	}
	printf("%s", postOrder(root).c_str());
	return 0;
}