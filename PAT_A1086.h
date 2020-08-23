#include<iostream>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

vector<int> pre, in, post, values;

void postorder(int root, int start, int end) {
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != pre[root]) i++;
	postorder(root + 1, start, i - 1);
	postorder(root + i - start + 1, i + 1, end);
	post.push_back(pre[root]);
}

int main()
{
	int n, num, idx = 0;
	char str[10];
	scanf("%d", &n);
	stack<int> s;
	for (int i = 0; i < 2 * n; i++) {
		scanf("%s", str);
		if (strlen(str) == 4) {
			scanf("%d", &num);
			values.push_back(num);
			pre.push_back(idx);
			s.push(idx++);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	postorder(0, 0, n - 1);
	printf("%d", values[post[0]]);
	for (int i = 1; i < n; i++) printf(" %d", values[post[i]]);
	return 0;
}