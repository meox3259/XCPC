#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int> > G(n);
	vector<int> c(n), d(n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		++d[u];
		++d[v];
	}
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	set<pair<int, int> > s;
	for(int i = 0; i < n; ++i) {
		s.emplace(d[i], i);
	}
	sort(c.begin(), c.end());
	long long sum = 0;
	vector<int> ans(n);
	for(int i = 0; i < n; ++i) {
		auto o = *s.begin();
		int w = o.first, u = o.second;
		s.erase(s.begin());
		sum += 1LL * w * c[i];
		ans[u] = c[i];
		for(auto v : G[u]) {
			if(s.find({d[v], v}) != s.end()) {
				s.erase({d[v], v});
				--d[v];
				s.emplace(d[v], v);
			}
		}
	}
	cout << sum << '\n';
	for(auto u : ans) {
		cout << u << ' ';
	}
	cout << '\n';
	return 0;
}
