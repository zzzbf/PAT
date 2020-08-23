#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
	int n, p1, p2;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (p1 = 2, p2 = 2; p1 < n && b[p1] >= b[p1 - 1]; p1++, p2++);
	while (p2 < n && b[p2] == a[p2]) p2++;
	if (p2 == n) {
		printf("Insertion Sort\n");
		sort(a.begin(), a.begin() + p1 + 1);
	}
	else {
		printf("Merge Sort\n");
		int h = 1, i = 0, j, flag = 1;
		while (flag) {
			flag = 0;
			for (i = 0; i < n; i++) {
				if (a[i] != b[i])
					flag = 1;
			}
			h *= 2;
			for (j = 0; j < n - h; j += h)
				sort(a.begin() + j, a.begin() + j + h);
			sort(a.begin() + j, a.end());
		}
	}
	printf("%d", a[0]);
	for (int i = 1; i < n; i++) printf(" %d", a[i]);
	return 0;
}