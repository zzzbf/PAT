#include<iostream>
#include<string>
#include<cmath>

using namespace std;

long long strToInteger(string s, int begin, int end)
{
	long long res = 0;
	for (int i = begin; i < end; i++) {
		res = res * 10 + s[i] - '0';
	}
	return res;
}
bool isPrime1(long long d)
{
	long long end = (int)sqrt(d);
	for (int i = 2; i <= end; i++)
		if (d % i == 0) return false;
	return true;
}

bool isPrime2(long long d)
{
	if (d == 2 || d == 3) return true;
	if (d % 6 != 1 && d % 6 != 5) return false;
	long long end = (int)sqrt(d);
	for (int i = 5; i <= end; i += 6)
		if (d % i == 0 || d % (i + 2) == 0) return false;
	return true;
}
int main()
{
	string str, head;
	int l, k;
	cin >> l >> k >> str;
	for (int i = 0; i <= l - k; i++) {
		long long d = stoi(str.substr(i, k));
		if (isPrime2(d)) {
			cout << str.substr(i, k);
			return 0;
		}
	}
	cout << "404";
	return 0;
}