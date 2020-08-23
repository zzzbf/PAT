#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int expIndex = str.find('E');
	string left = str.substr(1, expIndex-1);
	int exp = stoi(str.substr(expIndex + 1));
	if (str[0] == '-') putchar('-');
	if (exp < 0) {
		printf("0.");
		for (int i = 0; i < abs(exp) - 1; i++) printf("0");
		for (int i = 0; i < left.length(); i++) {
			if (left[i] != '.') putchar(left[i]);
		}
	}
	else{
		putchar(left[0]);
		int i, cnt;
		for (i = 2, cnt = 0; i < left.length() && cnt < exp; i++, cnt++) putchar(left[i]);
		if (i == left.length()) {
			for (int j = 0; j < exp - cnt; j++) putchar('0');
		}
		else {
			putchar('.');
			for (int j = i; j < left.length(); j++) putchar(left[j]);
		}
	}
	return 0;
}