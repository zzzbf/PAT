#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	int vNum, eNum, u, v;
	cin >> vNum >> eNum;
	vector<vector<int>> mp(vNum);
	for (int i = 0; i < eNum; i++) {
		cin >> u >> v;
		mp[u].push_back(i);
		mp[v].push_back(i);
	}
	int qNum;
	cin >> qNum;
	for (int i = 0; i < qNum; i++) {
		int n;
		cin >> n;
		unordered_map<int, bool> tmp;
		for (int j = 0; j < n; j++) {
			cin >> u;
			for (auto it = mp[u].begin(); it != mp[u].end(); it++)
				tmp[*it] = true;
		}
		if (tmp.size() == eNum) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}