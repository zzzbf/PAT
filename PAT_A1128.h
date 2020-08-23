#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>

using namespace std;

int main(){
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		vector<int> v(n);
		unordered_map<int, int> mp;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[j]);
			mp[v[j]]++;
		}
		for (int j = 0; j < n; j++) {
			if (mp[v[j]] > 1) {
				flag = false;
				break;
			}
			for (int u = 0; u < j; u++) {
				if (abs(v[j] - v[u]) == abs(j - u)) {
					flag = false;
					break;
				}
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}