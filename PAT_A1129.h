#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;

int book[52000];

struct node {
	int val, cnt;
	bool operator < (const node &a) const {
		return (cnt != a.cnt) ? cnt > a.cnt:val < a.val;
	}
};
int main()
{
	int n, k, num;
	scanf("%d %d", &n, &k);
	set<node> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (i != 0) {
			printf("%d:", num);
			int cnt = 0;
			for (set<node>::iterator it = s.begin(); it != s.end() && cnt < k; it++, cnt++)
				printf(" %d", it->val);
			printf("\n");
		}
		set<node>::iterator it = s.find(node{ num, book[num] });
		if (it != s.end()) s.erase(it);
		book[num]++;
		// 为了重新排序
		s.insert(node{ num, book[num] });
	}
	return 0;
}