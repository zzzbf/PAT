#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

vector<int> in, pre, post;
bool unique = true;
void getInOrder(int prel, int prer, int postl, int postr) {
	if (prel == prer) {
		in.push_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[postr]) {
		int i = prel + 1;
		while (i <= prer && pre[i] != post[postr - 1]) i++;
		if (i - prel > 1) getInOrder(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);
		else unique = false;
		in.push_back(post[postr]);
		getInOrder(i, prer, postl + (i - prel - 1), postr - 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	getInOrder(0, n - 1, 0, n - 1);
	printf("%s\n%d", unique ? "Yes" : "No", in[0]);
	for (int i = 1; i < n; i++) printf(" %d", in[i]);
	printf("\n");
	return 0;
}