#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

struct record { string id; int time, flag; };

int main(){
	int n, k, h, m, s, maxTime = 0;
	string flagstr;
	scanf("%d %d\n", &n, &k);
	vector<record> records(n), validRecords;
	for (int i = 0; i < n; i++) {
		cin >> records[i].id;
		scanf("%d:%d:%d", &h, &m, &s);
		cin >> flagstr;
		records[i].time = 3600 * h + 60 * m + s;
		records[i].flag = flagstr == "in" ? 1 : -1;
	}
	sort(records.begin(), records.end(), [](record a, record b) {
		return a.id == b.id ? a.time < b.time : a.id < b.id; });
	map<string, int> totalTime;
	for (int i = 0; i < n - 1; i++) {
		if (records[i].id == records[i + 1].id && records[i].flag == 1 && records[i + 1].flag == -1) {
			validRecords.push_back(records[i]);
			validRecords.push_back(records[i + 1]);
			totalTime[records[i].id] += records[i + 1].time - records[i].time;
			if (totalTime[records[i].id] > maxTime) maxTime = totalTime[records[i].id];
		}
	}
	sort(validRecords.begin(), validRecords.end(), [](record a, record b) {
		return a.time < b.time; });
	vector<int> cnt(n);
	for (int i = 0; i < validRecords.size(); i++) {
		if (i == 0) cnt[i] += validRecords[i].flag;
		else cnt[i] = cnt[i - 1] + validRecords[i].flag;
	}
	int tempIndex = 0, j;
	for (int i = 0; i < k; i++) {
		int h, m, s, t;
		scanf("%d:%d:%d", &h, &m, &s);
		t = 3600 * h + 60 * m + s;
		for (j = tempIndex; j < validRecords.size(); j++) {
			if (validRecords[j].time > t) {
				printf("%d\n", j > 0 ? cnt[j - 1] : 0);
				break;
			}
			else if (j == validRecords.size() - 1) printf("%d\n", cnt[j]);
		}
		tempIndex = j;
	}
	for (auto it = totalTime.begin(); it != totalTime.end(); it++) {
		if (it->second == maxTime) printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	
	return 0;
}