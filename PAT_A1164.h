#include<iostream>
#include<string>
#include<stdio.h>
#include<vector> 

using namespace std;

char dict[26][7][5];
int main()
{
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 5; k++) {
				dict[i][j][k] = getchar();
			}
			getchar();
		}
	}
	string str="", tmp = "";
	char c;
	while ((c = getchar())!=EOF) {
		str += c;
	}
	while (str.back() < 'A' || str.back() > 'Z') str = str.substr(0, str.size() - 1);
	vector<string> words;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') tmp += str[i];
		else {
			if (tmp != "") words.push_back(tmp);
			tmp = "";
		}
	}
	if (tmp != "") words.push_back(tmp);
	for (int i = 0; i < words.size(); i++) {
		// 打印行
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < words[i].length(); k++) {
				// 打印列
				for (int t = 0; t < 5; t++) printf("%c", dict[words[i][k] - 'A'][j][t]);
				if (k < words[i].length() - 1) printf(" ");
			}
			if (j != 6) printf("\n");
		}
		if (i != words.size() - 1)printf("\n\n");
	}
	
	return 0;
}