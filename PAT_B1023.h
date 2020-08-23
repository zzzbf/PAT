#include<iostream>
#include<vector>

using namespace std;

int main() {
	int cnt[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &cnt[i]);
	}
	for (int i = 1; i < 10; i++) {
		if (cnt[i]) {
			printf("%d", i);
			cnt[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		while (cnt[i]) {
			printf("%d", i);
			cnt[i]--;
		}
	}
	
	return 0;
}