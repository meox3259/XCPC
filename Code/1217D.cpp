#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > e;
	vector<int> d;
	vector<vector<int> > G;
	e.resize(m);
	d.resize(n);
	G.resize(n);
	map<pair<int, int>, int> mp;
	for(auto& [u, v] : e) {
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		++d[v];
	}
	queue<int> q;
	int tot = 0;
	for(int i = 0; i < n; ++i) {
		if(d[i] == 0) {
			q.emplace(i);
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		++tot;
		for(int v : G[u]) {
			if(--d[v] == 0) {
				q.emplace(v);
			}
		}
	}
	if(tot == n) {
		cout << 1 << '\n';
		for(int i = 0; i < m; ++i) {
			cout << 1 << ' ';
		}
		cout << '\n';
		return 0;
	}
	cout << 2 << '\n';
	for(auto [u, v] : e) {
		cout << (u < v) + 1 << ' '; 
	}
	cout << '\n';
	return 0;
}
