#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int num, i;
	cin >> num;
	vector<int> arr(num, 0);
	for (i = 0; i < num; i++) 
		cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<int>());
	for (i = 0; i < num; i++) {
		if (i + 1 >= arr[i]) break;
	}
	cout << i;
	return 0;
}
