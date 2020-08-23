#include<iostream>
#include<string>

using namespace std;

int main(){
	string str; 
	int n, j = 0;
	cin >> str >> n;
	for (int k = 1; k < n; k++) {
		string tmp;
		for (int i = 0; i < str.length(); i = j) {
			for (j = i; j < str.length() && str[j] == str[i]; j++);
			tmp += str[i] + to_string(j - i);
		}
		str = tmp;
	}
	cout << str;
	return 0;
}