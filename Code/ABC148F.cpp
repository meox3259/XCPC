#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b;
	cin >> n >> a >> b;
	--a;
	--b;
	vector<vector<int> > G;
	G.resize(n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	vector<vector<int> > d;
	d.resize(2);
	for(int i = 0; i < 2; ++i) {
		d[i].resize(n);
	}
	function<void(int, int, int)> dfs = [&] (int u, int f, int t) {
		for(auto v : G[u]) {
			if(v != f) {
				d[t][v] = d[t][u] + 1;
				dfs(v, u, t);
			}
		}
	};
	dfs(a, -1, 0);
	dfs(b, -1, 1);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(d[0][i] < d[1][i]) {
			ans = max(ans, d[1][i] - 1);
		}
	}
	// 0 - 0 - 0 - 0 - 0
	cout << ans << '\n';
	return 0;
}
