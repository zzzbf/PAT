#include<iostream>
#include<string>

using namespace std;

int main() 
{
	string str;
	int cntt = 0, ans = 0, cntp = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) 
		if (str[i] == 'T') cntt++;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'T') cntt--;
		else if (str[i] == 'P') cntp++;
		else ans = (ans + cntp * cntt % 1000000007) % 1000000007;
	}
	printf("%d", ans);
	return 0;
}