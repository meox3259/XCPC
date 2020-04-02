#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

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

	vector<int> dep;
	dep.resize(n);

	vector<vector<int> > fa;
	fa.resize(n);

	for(int i = 0; i < n; ++i) {
		fa[i].resize(21, -1);
	}

	function<void(int, int)> dfs = [&] (int u, int f) {
		for(auto v : G[u]) {
			if(v != f) {
				dep[v] = dep[u] + 1;
				fa[v][0] = u;
				dfs(v, u);
			}
		}
	};

	dfs(0, -1);
	
	for(int j = 1; j < 21; ++j) {
		for(int i = 0; i < n; ++i) {
			if(fa[i][j - 1] != -1) {
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
			}	
		}
	}

	auto lca = [&] (int u, int v) {
		if(dep[u] < dep[v]) {
			swap(u, v);
		}

		int d = dep[u] - dep[v];

		for(int j = 20; j >= 0; --j) {
			if(d >> j & 1) {
				u = fa[u][j];
			}
		}

		if(u == v) {
			return u;
		}

		for(int i = 20; i >= 0; --i) {
			if(fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}

		return fa[u][0];
	};

	auto dis = [&] (int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];	
	};

	while(m--) {
		int k;
		cin >> k;
		
		vector<int> v;
		v.resize(k);

		for(int i = 0; i < k; ++i) {
			cin >> v[i];

			--v[i];
		}

		sort(v.begin(), v.end(), [&] (int i, int j) {
			return dep[i] < dep[j];
		});

		bool ok = true;

		for(int i = 0; i < (int)v.size() - 1; ++i) {
			if(dis(v[i], 0) + dis(v[i], v[k - 1]) > dep[v[k - 1]] + 2) {
				ok = false;
			}
		}

		if(ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
