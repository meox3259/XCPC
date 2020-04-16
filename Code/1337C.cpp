#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<vector<int> > G;
	G.resize(n);

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		G[u - 1].emplace_back(v - 1);
		G[v - 1].emplace_back(u - 1);
	}

	vector<int> deg;
	deg.resize(n);

	vector<int> dep;
	dep.resize(n);

	vector<int> fa;
	fa.resize(n);
	
	vector<int> sz;
	sz.resize(n);

	function<void(int, int)> dfs = [&] (int u, int f) {
		sz[u] = 1;
		for(int v : G[u]) {
			if(v != f) {
				dep[v] = dep[u] + 1;
				fa[v] = u;
				++deg[u];
				dfs(v, u);
				sz[u] += sz[v];
			}
		}
	};	

	dfs(0, -1);

	priority_queue<pair<int, int> > q;

	for(int i = 0; i < n; ++i) {
		if(deg[i] == 0) {
			q.emplace(dep[i], i);
		}
	}

	long long ans = 0;

	for(int i = 0; i < k; ++i) {
		auto [d, u] = q.top();
		q.pop();

		ans += d;

		if(--deg[fa[u]] == 0) {
			q.emplace(dep[fa[u]] - sz[fa[u]] + 1, fa[u]);
		}
	}

	cout << ans << '\n';

	return 0;
}
