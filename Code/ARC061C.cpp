#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > e;
	vector<vector<pair<int, int> > > G;
	e.resize(n);
	int node = n;
	map<pair<int, int>, int> id;
	for(int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;
		if(id.count({c, x}) == 0) {
			id[{c, x}] = node++;
		}
		if(id.count({c, y}) == 0) {
			id[{c, y}] = node++;
		}
		e[x].emplace_back(c, y);
		e[y].emplace_back(c, x);
	}
	G.resize(node);
	for(int i = 0; i < n; ++i) {
		for(auto o : e[i]) {
			int c = o.first, u = id[{c, i}], v = o.second;
			G[i].emplace_back(u, 1);
			G[u].emplace_back(i, 1);
			G[u].emplace_back(v, 0);
			int w = id[{c, v}];
			G[u].emplace_back(w, 0);
		}
	}
	vector<int> d(node, inf);
	d[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.emplace(0, 0);
	while(!q.empty()) {
		auto o = q.top();
		q.pop();
		int u = o.second;
		if(o.first < d[u]) {
			continue;
		}
		for(auto o : G[u]) {
			int v = o.first, w = o.second;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.emplace(d[v], v);
			}
		}
	}
	if(d[n - 1] == inf) {
		cout << -1 << '\n';
	} else {
		cout << d[n - 1] << '\n';
	}
	return 0;
}
