#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

vector<int> in, post;
unordered_map<int, int> idx;
unordered_map<int, int> sibling, parent, lchild, rchild, levels;
bool isFull = true;

void build(int inl, int inr, int postl, int postr, int level) {
	int mid = idx[post[postr]], leftNum = mid - inl - 1;
	levels[in[mid]] = level;
	int l = -1, r = -1;
	if (inl <= mid - 1) {
		l = post[postl + leftNum];
		lchild[in[mid]] = l;
		parent[l] = in[mid];
		build(inl, mid - 1, postl, postl + leftNum, level + 1);
	}
	if (mid + 1 <= inr) {
		r = post[postr - 1];
		rchild[in[mid]] = r;
		parent[r] = in[mid];
		build(mid + 1, inr, postl + leftNum + 1, postr - 1, level + 1);
	}
	if (inl <= mid - 1 && mid + 1 <= inr) {
		sibling[r] = l;
		sibling[l] = r;
	}
	else if(!(inl > mid - 1 && mid + 1 > inr)){
		isFull = false;
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	in.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		idx[in[i]] = i;
	}
	build(0, n - 1, 0, n - 1, 1);
	scanf("%d\n", &m);
	int A, B;
	for(int i = 0;i<m;i++){
		string statement;
		getline(cin, statement);
		if (statement.find("root") != string::npos) {
			sscanf(statement.c_str(), "%d is the root", &A);
			printf("%s\n", post[n - 1] == A ? "Yes" : "No");
		}
		else if (statement.find("siblings") != string::npos) {
			sscanf(statement.c_str(), "%d and %d are siblings", &A, &B);
			printf("%s\n", sibling.find(A) != sibling.end() && sibling[A] == B ? "Yes" : "No");
		}
		else if (statement.find("parent") != string::npos) {
			sscanf(statement.c_str(), "%d is the parent of %d", &A, &B);
			printf("%s\n", parent.find(B) != parent.end() && parent[B] == A ? "Yes" : "No");
		}
		else if (statement.find("left child") != string::npos) {
			sscanf(statement.c_str(), "%d is the left child of %d", &A, &B);
			printf("%s\n", lchild.find(B) != lchild.end() && lchild[B] == A ? "Yes" : "No");
		}
		else if (statement.find("right child") != string::npos) {
			sscanf(statement.c_str(), "%d is the right child of %d", &A, &B);
			printf("%s\n", rchild.find(B) != rchild.end() && rchild[B] == A ? "Yes" : "No");
		}
		else if (statement.find("same level") != string::npos) {
			sscanf(statement.c_str(), "%d and %d are on the same level", &A, &B);
			printf("%s\n", levels.find(A) != levels.end() && levels.find(B) != levels.end() &&
				levels[A] == levels[B] ? "Yes" : "No");
		}
		else {
			printf("%s\n", isFull ? "Yes" : "No");
		}
	}
	return 0;
}