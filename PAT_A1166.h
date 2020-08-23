#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int parent[210];
int Find(int a) {
	return a == parent[a] ? a : parent[a] = Find(parent[a]);
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb) parent[pb] = pa;
}
bool check(vector<vector<bool>> &isFriend, vector<int> heads) {
	for (int i = 0; i < heads.size(); i++) {
		for (int j = i + 1; j < heads.size(); j++)
			if (!isFriend[heads[i]][heads[j]]) return false;
	}
	return true;
}

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<vector<bool>> isFriend(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < 211; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		isFriend[a][b] = true;
		isFriend[b][a] = true;
		Union(a, b);
	}
	int testn, num;
	scanf("%d", &testn);
	for (int j = 0; j < testn; j++) {
		scanf("%d", &num);
		unordered_map<int, bool> mp;
		vector<int> heads(num);
		for (int k = 0; k < num; k++) {
			scanf("%d", &heads[k]);
			mp[heads[k]] = true;
		}
		if (!check(isFriend, heads)) {
			printf("Area %d needs help.\n", j + 1);
			continue;
		}
		int k;
		bool flag = true;
		for (k = 1; k <= n; k++) {
			if (mp.find(k) != mp.end()) continue;
			int t = 0;
			for (; t < num && isFriend[heads[t]][k]; t++);
			if (t == num) {
				flag = false;
				break;
			}
		}
		if (!flag) printf("Area %d may invite more people, such as %d.\n", j + 1, k);
		else printf("Area %d is OK.\n", j + 1);
	}
	return 0;
}