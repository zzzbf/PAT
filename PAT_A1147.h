#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int keysNum, caseNum;
bool maxHeap = false, minHeap = false;
vector<int> nodes, ans;

void postOrder(int id)
{
	if (id > keysNum) return;
	postOrder(id * 2);
	postOrder(id * 2 + 1);
	printf("%d%s", nodes[id], id == 1 ? "\n" : " ");
}

int main()
{
	scanf("%d %d", &caseNum, &keysNum);
	nodes.resize(keysNum + 1);
	for (int j = 0; j < caseNum; j++) {
		int ismin = 1, ismax = 1;
		for (int i = 1; i <= keysNum; i++) scanf("%d", &nodes[i]);
		for (int i = 2; i <= keysNum; i++) {
			if (nodes[i] > nodes[i / 2]) ismax = 0;
			if (nodes[i] < nodes[i / 2]) ismin = 0;
		}
		if (!ismax && !ismin) printf("Not Heap\n");
		else printf("%s Heap\n", ismax == 1 ? "Max" : "Min");
		postOrder(1);
	}
	return 0;
}