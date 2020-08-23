#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isPrime(int num) {
	if (num == 3 || num == 2) return true;
	if (num % 6 != 1 && num % 6 != 5) return false;
	int end = (int)sqrt(num);
	for (int i = 5; i <= end; i += 6)
		if (num % i == 0 || num % (i + 2) == 0) return false;
	return true;
}
int main() {
	int size, n, m, val;
	scanf("%d %d %d", &size, &n, &m);
	while (!isPrime(size)) size++;
	vector<int> v(size, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		int j;
		for (j = 0; j < size; j++) {
			int pos = (val + j * j) % size;
			if (v[pos] == 0) {
				v[pos] = val;
				break;
			}
		}
		if (j == size)printf("%d cannot be inserted.\n", val);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &val);
		for (int j = 0; j <= size; j++) {
			ans++;
			int pos = (val + j * j) % size;
			if (v[pos] == 0 || v[pos] == val) break;
		}
	}
	printf("%.1f\n", ans*1.0 / m);
	return 0;
}