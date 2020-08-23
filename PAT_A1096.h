#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int num, ans = 0, start = -1;
	scanf("%d", &num);
	int maxn = (int)sqrt(num), i, j, tmp;
	for (i = 2; i <= maxn; i++) {
		j = i;
		tmp = num;
		while (j <= maxn && tmp % j == 0) tmp /= j++;
		if (j - i > ans) {
			ans = j - i;
			start = i;
		}
	}
	if (start == -1) printf("1\n%d", num);
	else {
		printf("%d\n%d", ans, start);
		for (int k = 1; k < ans; k++) printf("*%d", start + k);
	}
	return 0;
}