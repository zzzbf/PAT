#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

struct node {
	int add, next, val;
};
int main() {
	int h1, h2, n, add, val, next;
	scanf("%d %d %d", &h1, &h2, &n);
	unordered_map<int, node> nodes(n);
	vector<node> list1, list2, ansList;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &add, &val, &next);
		nodes[add] = { add, next, val };
	}
	int t1 = h1, t2 = h2;
	while (t1 != -1) {
		list1.push_back(nodes[t1]);
		t1 = nodes[t1].next;
	}
	while (t2 != -1) {
		list2.push_back(nodes[t2]);
		t2 = nodes[t2].next;
	}
	if (list1.size() < list2.size()) swap(list1, list2);
	int totalSize = list1.size() + list2.size(), longListCnt = 0;
	ansList.resize(totalSize);
	vector<node>::reverse_iterator shortListIt = list2.rbegin();
	vector<node>::iterator longListIt = list1.begin();
	for (int i = 0; i < totalSize; i++) {
		if (longListCnt != 0 && longListCnt % 2 == 0 && shortListIt != list2.rend()) {
			ansList[i] = *shortListIt;
			shortListIt++;
			longListCnt = 0;
		}
		else {
			longListCnt++;
			ansList[i] = *longListIt;
			longListIt++;
		}
	}
	for (int i = 0; i < totalSize; i++) {
		printf("%05d %d ", ansList[i].add, ansList[i].val);
		if (i < totalSize - 1) printf("%05d\n", ansList[i + 1].add);
		else printf("-1");
	}
	return 0;
}