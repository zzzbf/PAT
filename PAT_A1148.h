#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)  cin >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vector<int> liars, isHum(n + 1, 1);
			isHum[i] = isHum[j] = -1;
			for (int k = 1; k <= n; k++)
				if (isHum[abs(v[k])] * v[k] < 0) liars.push_back(k);
			if (liars.size() == 2 && isHum[liars[0]] + isHum[liars[1]] == 0) {
				printf("%d %d", i, j);
				return 0;
			}
		}
	}       
	printf("No Solution");
	return 0;
}