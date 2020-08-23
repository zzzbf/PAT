#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void downAdjust(vector<int> &b, int low, int high) {
	int i = 1, j = i * 2;
	while(j<=high){
		if (j + 1 <= high && b[j] < b[j + 1]) j++;
		if (b[i] > b[j]) break;
		swap(b[i], b[j]);
		i = j; j = i * 2;
	}
}

int main (){
	int n, p1 = 2, p2 = 2;
	scanf("%d", &n);
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	while (p1 <= n && b[p1 - 1] <= b[p1]) p1++, p2++;
	while (p2 <= n && a[p2] == b[p2]) p2++;
	if (p2 == n + 1) {
		printf("Insertion Sort\n");
		sort(b.begin() + 1, b.begin() + p1 + 1);
	}
	else {
		printf("Heap Sort\n");
		p2 = n;
		while (p2 > 2 && b[p2] >= b[1]) p2--;
		swap(b[1], b[p2]);
		downAdjust(b, 1, p2 - 1);
	}
	printf("%d", b[1]);
	for (int i = 2; i <= n; i++) printf(" %d", b[i]);
	return 0;
}