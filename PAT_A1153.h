#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct student {
	string id;
	int score;
};

bool cmp1(student s1, student s2)
{
	if (s1.score == s2.score) return s1.id < s2.id;
	return s1.score > s2.score;
}

int main()
{
	int cardNum, queryNum, queryType;
	string inputStr;
	cin >> cardNum >> queryNum;
	vector<student> students(cardNum);

	for (int i = 0; i < cardNum; i++)
		cin >> students[i].id >> students[i].score;

	for (int i = 0; i < queryNum; i++) {
		cin >> queryType >> inputStr;
		printf("Case %d: %d %s\n", i + 1, queryType, inputStr.c_str());
		vector<student> ans;
		int totalScore = 0, cnt = 0;
		if (queryType == 1) {
			for (int i = 0; i < cardNum; i++)
				if (students[i].id.substr(0, 1) == inputStr)
					ans.push_back(students[i]);
		}
		else if (queryType == 2) {
			for (int i = 0; i < cardNum; i++)
				if (students[i].id.substr(1, 3) == inputStr) {
					totalScore += students[i].score;
					cnt++;
				}
		}
		else {
			unordered_map<string, int> mp;
			for (int j = 0; j < cardNum; j++)
				if (students[j].id.substr(4, 6) == inputStr) mp[students[j].id.substr(1, 3)]++;
			for (auto it : mp) ans.push_back({ it.first, it.second });
		}
		if ((ans.size() == 0 && (queryType == 1 || queryType == 3)) ||
			(queryType == 2 && cnt == 0))
			printf("NA\n");
		else if (queryType == 2)
			printf("%d %d\n", cnt, totalScore);
		else {
			sort(ans.begin(), ans.end(), cmp1);
			for (int j = 0; j < ans.size(); j++)
				printf("%s %d\n", ans[j].id.c_str(), ans[j].score);
		}
	}
	return 0;
}