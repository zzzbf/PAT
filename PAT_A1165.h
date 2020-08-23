#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

typedef struct {
	int add, data, next;
}node;

int main()
{
	int head, n, k, add, data, next;
	unordered_map<int, node> list;
	scanf("%d %d %d", &head, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &add, &data, &next);
		list[add] = node{ add, data, next };
	}
	int p = head;
	vector<node> li, ans;
	while (p != -1) {
		li.push_back(list[p]);
		p = list[p].next;
	}
	int re = li.size() % k, size = li.size();
	int from = size - 1;
	if (re != 0) {
		for (int j = 0; j < re; j++)
			ans.push_back(li[size - re + j]);
		from -= re;
	}
	from -= k;
	for (; from >= -1; from -= k) {
		for (int j = 1; j <= k; j++) 
			ans.push_back(li[from + j]);
	}
	for (int i = 0; i < size - 1; i++)
		printf("%05d %d %05d\n", ans[i].add, ans[i].data, ans[i + 1].add);
	printf("%05d %d -1", ans[size - 1].add, ans[size - 1].data);
	return 0;
}