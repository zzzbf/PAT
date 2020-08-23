#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
typedef struct {
	int n, num;
}number;

int gcd(int n, int m){
	return m == 0 ? n : gcd(m, n%m);
}
bool isPrime(int n) {
	if (n < 3) return false;
	int sqrtn = (int)sqrt(n);
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}
int getSum(int n) {
	return n == 0 ? 0 : getSum(n / 10) + n % 10;
}

int main() {
	int num, k, m;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		vector<number> ans;
		scanf("%d %d", &k, &m);
		printf("Case %d\n", i + 1);
		int minn = (int)pow(10, k - 3);
		int maxn = minn * 10;
		for (int j = minn; j < maxn; j++) {
			int tmp = j * 100 + 99;
			int sum1 = getSum(tmp + 1);
			if (getSum(tmp) == m && isPrime(gcd(sum1, m)))
				ans.push_back({ sum1, tmp });
		}
		if(ans.empty()) printf("No Solution\n");
		else {
			sort(ans.begin(), ans.end(), [](number n1, number n2) {
				return n1.n == n2.n ? n1.num < n2.num : n1.n < n2.n;
			});
			for (auto it : ans) printf("%d %d\n", it.n, it.num);
		}
	}
	return 0;
}