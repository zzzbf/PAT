#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct node { int add, key, next; };

int main()
{
	int head, num, K, add, key, next;
	unordered_map<int, node> list;
	scanf("%d %d %d", &head, &num, &K);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &add, &key, &next);
		list[add] = { add, key, next };
	}
	vector<node> v, ans;

	for (int tail = head; tail != -1; tail = list[tail].next)
		v.push_back(list[tail]);

	for (int i = 0; i < v.size(); i++) 
		if (v[i].key < 0) ans.push_back(v[i]);
	for (int i = 0; i < v.size(); i++) 
		if (v[i].key >= 0 && v[i].key <= K) ans.push_back(v[i]);
	for (int i = 0; i < v.size(); i++)
		if (v[i].key > K) ans.push_back(v[i]);

	for (int i = 0; i < v.size() - 1; i++)
		printf("%05d %d %05d\n", ans[i].add, ans[i].key, ans[i + 1].add);
	printf("%05d %d -1\n", ans.back().add, ans.back().key);
	return 0;
}