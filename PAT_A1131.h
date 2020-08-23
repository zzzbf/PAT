#include<iostream>
#include<vector>
#include<unordered_map>

#define MAX_SIZE 10000

using namespace std;

int currentLine = -1;
vector<int> path, ans, ansLines, ansTransfer;
vector<bool> visited(MAX_SIZE, false);
//vector<vector<int>> adj(MAX_SIZE, vector<int>(MAX_SIZE, -1));
unordered_map<int, unordered_map<int, int>> adj;
vector<vector<int>> getLines(vector<int> v)
{
	vector<int> lines;
	vector<int> transferStations;
	int from = v[0], to = v[0];
	for (int i = 0; i < v.size() - 1; i++) {
		to = v[i];
		if (lines.empty() || adj[v[i]][v[i + 1]] != lines.back()) {
			if (!lines.empty()) {
				transferStations.push_back(from);
				transferStations.push_back(to);
				from = to;
			}
			lines.push_back(adj[v[i]][v[i + 1]]);
		}
	}
	if (lines.size() == 1) {
		transferStations.push_back(*v.begin());
		transferStations.push_back(v.back());
	}
	else {
		transferStations.push_back(from);
		transferStations.push_back(v.back());
	}
	vector<vector<int>> res(2);
	res[0] = lines;
	res[1] = transferStations;
	return res;
}

void dfs(int from, int to)
{
	path.push_back(from);
	if (from == to) {
		if (ans.empty() || path.size() < ans.size() || (
			path.size() == ans.size() && getLines(path)[0].size() < getLines(ans)[0].size()
			)) {
			ans = path;
			ansLines = getLines(path)[0];
			ansTransfer = getLines(path)[1];
		}
		path.pop_back();
		return;
	}
	if (!ans.empty() && path.size() >= ans.size()) {
		path.pop_back();
		return;
	}
	visited[from] = true;

	for (auto it = adj[from].begin(); it != adj[from].end(); it++) {
		if (!visited[it->first]) dfs(it->first, to);
	}

	path.pop_back();
	visited[from] = false;
}

int main()
{
	int linesN, stationsN, stationId, queryN, from, to;

	cin >> linesN;

	for (int i = 0; i < linesN; i++) {
		cin >> stationsN >> stationId;
		int pre = stationId;
		for (int j = 1; j < stationsN; j++) {
			cin >> stationId;
			adj[pre][stationId] = i + 1;
			adj[stationId][pre] = i + 1;
			pre = stationId;
		}
	}
	cin >> queryN;
	for (int i = 0; i < queryN; i++) {
		cin >> from >> to;
		dfs(from, to);
		printf("%d\n", ans.size() - 1);
		for (int i = 0; i < ansLines.size(); i++) {
			printf("Take Line#%d from %04d to %04d.\n", ansLines[i],
				ansTransfer[2 * i], ansTransfer[2 * i + 1]);
		}
		path.clear();
		ans.clear();
		ansLines.clear();
		ansTransfer.clear();
		fill(visited.begin(), visited.end(), false);
	}
	return 0;
}