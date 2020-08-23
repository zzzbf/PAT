#include<iostream>
#include<unordered_map>
#include<string>
#include<set>
#include<cmath>
using namespace std;

struct info {
	int onlineScore, midScore, finalScore;
	int G;
	string id;
	bool operator <(const info &other) const {
		return G == other.G ? id<other.id : G > other.G;
	}
};

int main()
{
	int p, m, n, score;
	string id;
	unordered_map<string, info> students;
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++) {
		cin >> id >> score;
		if (score >= 200) students[id] = info{ score, -1, -1,0, id };
	}
	for (int i = 0; i < m; i++) {
		cin >> id >> score;
		unordered_map<string, info>::iterator it = students.find(id);
		if (it != students.end()) it->second.midScore = score;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> id >> score;
		unordered_map<string, info>::iterator it = students.find(id);
		if (it == students.end()) continue;
		it->second.finalScore = score;
		if (it->second.finalScore >= it->second.midScore) it->second.G = (int)it->second.finalScore;
		else it->second.G = (int)round(0.6*it->second.finalScore + 0.4*it->second.midScore);
	}
	set<info> ans;
	for (auto it = students.begin(); it != students.end(); it++) {
		if (it->second.G >= 60) ans.insert(it->second);
	}
	
	for (auto it = ans.begin(); it != ans.end(); it++) {
		printf("%s %d %d %d %d\n", it->id.c_str(), it->onlineScore,
			it->midScore, it->finalScore, it->G);
	}
	return 0;
}