#include<iostream>
#include<unordered_map>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

struct school{
	int ns, tws;
	string name;
	bool operator < (const school &other) const {
		if (tws != other.tws) return tws > other.tws;
		else if (ns != other.ns) return ns < other.ns;
		else return name < other.name;
	}
};

int main() {
	unordered_map<string, double> mp;
	unordered_map<string, int> cnt;
	int n;
	double score;
	cin >> n;
	string id, schoolName;
	for (int i = 0; i < n; i++) {
		cin >> id >> score >> schoolName;
		transform(schoolName.begin(), schoolName.end(), schoolName.begin(),
			[](unsigned char c) {return tolower(c); });
		char level = id[0];
		if (level == 'A') mp[schoolName] += 1.0*score;
		else if (level == 'B') mp[schoolName] += score / 1.5;
		else mp[schoolName] += score * 1.5;
		cnt[schoolName]++;
	}
	set<school> ans;
	for (auto it = mp.begin(); it != mp.end(); it++) 
		ans.insert({ cnt[it->first], (int)mp[it->first], it->first });
	printf("%d\n", ans.size());
	int preRank = 1, i = 1, preScore = -1;
	for (auto it = ans.begin(); it != ans.end(); it++, i++) {
		if (it->tws == preScore) printf("%d", preRank);
		else {
			printf("%d", i);
			preRank = i;
			preScore = it->tws;
		}
		printf(" %s %d %d\n", it->name.c_str(), it->tws, it->ns);
	}

	return 0;
}