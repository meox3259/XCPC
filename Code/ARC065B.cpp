#include <bits/stdc++.h>

using namespace std;

class dsu {
	vector<int> fa;
	public:
		dsu(int n) {
			fa.resize(n);
			iota(fa.begin(), fa.end(), 0);
		}

		int find(int x) {
			return x == fa[x] ? x : fa[x] = find(fa[x]);
		}

		bool same(int x, int y) {
			return find(x) == find(y);
		}

		void connect(int x, int y) {
			if(same(x, y)) {
				return;
			}

			x = find(x);
			y = find(y);

			fa[x] = y;
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int k, l;
	cin >> k >> l;

	dsu dsu(n);

	for(int i = 0; i < k; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		dsu.connect(u, v);
	}

	vector<int> c;
	c.assign(n, -1);

	int tot = 0;

	for(int i = 0; i < n; ++i) {
		if(c[dsu.find(i)] == -1) {
			c[dsu.find(i)] = tot++;
		}

		c[i] = c[dsu.find(i)];
	}

	vector<vector<int> > G;
	G.resize(n);

	for(int i = 0; i < l; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<bool> vis;
	vis.assign(n, false);

	vector<int> cnt;
	cnt.resize(tot);

	vector<int> st;

	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		++cnt[c[u]];
		st.emplace_back(u);

		for(auto v : G[u]) {
			if(!vis[v]) {
				dfs(v);
			}
		}
	};

	vector<int> ans;
	ans.resize(n);

	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			st.clear();

			dfs(i);

			for(auto x : st) {
				ans[x] = cnt[c[x]];
			}

			for(auto x : st) {
				cnt[c[x]] = 0;
			}
		}
	}

	for(auto x : ans) {
		cout << x << ' ';
	}

	cout << '\n';

	return 0;
}
