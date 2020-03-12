#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > G;
	G.resize(n);
	for(int i = 0; i < m; ++i) {
		int l, r, c;
		cin >> l >> r >> c;
		--r;
		--l;
		G[l].emplace_back(r, c);
	}
	for(int i = n - 1; i > 0; --i) {
		G[i].emplace_back(i - 1, 0);
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
	vector<long long> d;
	d.resize(n, inf);
	d[0] = 0;
	q.emplace(0, 0);
	while(!q.empty()) {
		auto o = q.top();
		int u = o.second;
		q.pop();
		if(o.first > d[u]) {
			continue;
		}
		for(auto o : G[u]) {
			int v = o.first;
			int w = o.second;
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
