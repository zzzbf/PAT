#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

vector<int> parent;
map<int, set<int>> tmpAns;
vector<set<int>> ans;

int Find(int a) {
	if (a != parent[a]) return parent[a] = Find(parent[a]);
	return a;
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if (pa != pb) parent[pa] = pb;
	
}

int main()
{
	int k, n, m, c, r, d;
	scanf("%d %d %d", &k, &n, &m);
	map<int, bool> sus;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &c, &r, &d);
		 adj[c][r] += d;
	}

	for (int i = 1; i <= n; i++) {
		int callOutcount = 0, callBackcount = 0;
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] > 0 && adj[i][j] <= 5) { //等号，测试点5
				callOutcount++;
				if (adj[j][i] != 0) callBackcount++;
			}
		}
		if (callOutcount > k && callBackcount <= 0.2*callOutcount) 
			// 坑点1 取等号 测试点3
			// 坑点2 callBackcount <= 0.2*k，这里k是阈值，所以不等式错误 测试点2
			sus[i] = true;
	}

	if (sus.empty()) {
		printf("None");
		return 0;
	}

	for (auto it1 = sus.begin(); it1 != sus.end(); it1++) {
		for (auto it2 = it1; it2 != sus.end(); it2++) {
			if (adj[it1->first][it2->first] && adj[it2->first][it1->first]) 
				Union(it1->first, it2->first);	
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sus.find(i) != sus.end()) tmpAns[Find(i)].insert(i);
	}

	for (auto it = tmpAns.begin(); it != tmpAns.end(); it++) {
		set<int> gang = it->second;
		ans.push_back(gang);
	}
	sort(ans.begin(), ans.end(), [](set<int> s1, set<int> s2) {
		return *s1.begin() < *s2.begin();
	});

	for (auto it = ans.begin(); it != ans.end(); it++) {
		set<int> gang = *it;
		int i = 0;
		for (auto it2 = gang.begin(); it2 !=gang.end(); it2++, i++)
			printf("%d%s", *it2, i == gang.size() - 1 ? "\n" : " ");
	}
	return 0;
}