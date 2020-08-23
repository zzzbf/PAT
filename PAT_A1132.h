#include<iostream>
#include<string>

using namespace std;

bool check(string num) {
	int k = num.length();
	int mid = k / 2, left = 0, right = 0;
	left = stoi(num.substr(0, mid));
	right = stoi(num.substr(mid));
	if (left == 0 || right == 0) return false;
	int num1 = stoi(num);
	return num1 % (right*left) == 0;
}

int main()
{
	int n;
	string num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		printf("%s\n", check(num) ? "Yes" : "No");
	}
	return 0;
}