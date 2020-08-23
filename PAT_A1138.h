#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> pre(n, 0), in(n, 0);
	unordered_map<int, int> idx;
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		idx[in[i]] = i;
	}
	int prel = 0, prer = n - 1, inl = 0, inr = n - 1;
	while (true) {
		if (inl == inr) break;
		int mid = idx[pre[prel]];
		if (mid - inl > 0) {
			prel = prel + 1;
			prer = prel + mid - inl;
			inr = mid - 1;
		}
		else {
			prel = prel + mid - inl + 1;
			inl = mid + 1;
		}
	}
	printf("%d", in[inl]);
	return 0;
}
