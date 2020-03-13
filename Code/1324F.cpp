#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

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

	vector<int> ans;
	ans.assign(n, -2 * n);

	vector<int> down;
	vector<int> up;
	down.resize(n);
	up.resize(n);

	function<void(int, int)> dfs = [&] (int u, int f) {
		for(auto v : G[u]) {
			if(v != f) {
				dfs(v, u);

				down[u] += max(0, down[v]);

			}
		}	
		
		if(a[u] == 1) {
			++down[u];
		} else {
			--down[u];
		}

	};

	dfs(0, -1);

	up[0] = down[0];
	ans[0] = down[0];

	function<void(int, int)> Dfs = [&] (int u, int f) {
		multiset<int> s;

		up[u] = up[f] - max(down[u], 0);

		up[u] = max(up[u], 0);

		if(a[u] == 1) {
			++up[u];
		} else {
			--up[u];
		}

		for(auto v : G[u]) {
			if(v != f) {
				s.emplace(down[v]);
				up[u] += max(down[v], 0);
			}		
		} 

		ans[u] = max(ans[u], down[u]);
		ans[u] = max(ans[u], up[u]);

		for(auto v : G[u]) {
			if(v != f) {
				Dfs(v, u);
			}
		}	
	};

	for(auto v : G[0]) {
		Dfs(v, 0);
	}

	for(auto x : ans) {
		cout << x << ' ';
	}

	cout << '\n';

	return 0;
}
