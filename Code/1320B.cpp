#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > G;
	vector<vector<int> > g;
	G.resize(n);
	g.resize(n);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--v;
		--u;
		G[v].emplace_back(u);
		g[u].emplace_back(v);
	}
	int k;
	cin >> k;
	vector<int> p;
	p.resize(k);
	for(int i = 0; i < k; ++i) {
		cin >> p[i];
		--p[i];
	}
	queue<int> q;
	vector<int> d;
	d.assign(n, -1);
	d[p.back()] = 0;
	q.emplace(p.back());
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : G[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q.emplace(v);
			}
		}
	}
	int low = 0;
	int high = 0;
	for(int i = 0; i < k - 1; ++i) {
		int u = p[i];
		for(auto v : g[u]) {
			if(d[v] + 1 == d[u] && v != p[i + 1]) {
				++high;
				break;
			}
		}
		if(d[p[i + 1]] + 1 != d[p[i]]) {
			++low;
		}
	}
	cout << low << ' ' << high << '\n';
	return 0;
}
