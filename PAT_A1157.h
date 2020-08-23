#include<iostream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

struct info {
	string id;
	bool operator < (const info &other) const {
		if (id.substr(6, 4) != other.id.substr(6, 4))  return id.substr(6, 4) < other.id.substr(6, 4);
		else if (id.substr(10, 2) != other.id.substr(10, 2))  return id.substr(10, 2) < other.id.substr(10, 2);
		else return id.substr(12, 2) < other.id.substr(12, 2);
	}
};

int main()
{
	int n, m;
	string str;
	unordered_map<string, bool> mp1, mp2;
	set<info> ans1, ans2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp1[str] = true;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		cin >> str;
		ans1.insert({ str });
		if (mp1.find(str) != mp1.end()) ans2.insert({ str });
	}
	if (ans2.empty()) printf("0\n%s", ans1.begin()->id.c_str()); // ¿Óµã1 ÒªÊä³ö0
	else printf("%d\n%s", ans2.size(), ans2.begin()->id.c_str());
	return 0;
}