#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int vNum, eNum, a, b;
	scanf("%d %d", &vNum, &eNum);
	vector<vector<int>> adj(vNum + 1);
	vector<int> in(vNum + 1, 0);
	for (int i = 0; i < eNum; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	int testNum;
	scanf("%d", &testNum);
	bool flag2 = false;
	for (int i = 0; i < testNum; i++) {
		bool flag1 = true;
		vector<int> tin = in;
		for (int j = 0; j < vNum; j++) {
			scanf("%d", &a);
			if (tin[a] != 0) flag1 = false;
			for (int it : adj[a]) tin[it]--;
		}
		if (flag1) continue;
		printf("%s%d", flag2 ? " " : "", i);
		flag2 = true;
	}
	return 0;
}