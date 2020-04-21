#include <bits/stdc++.h>

using namespace std;

class segment_tree {
	vector<int> lc;
	vector<int> rc;
	vector<int> sum;
	int Pool = 0;
	
	public:
	segment_tree(int n) {
		lc.resize(60 * n + 5);
		rc.resize(60 * n + 5);
		sum.resize(60 * n + 5);
	}

	void update(int l, int r, int &x, int p, int v) {
		if(!x) {
			x = ++Pool;
		}

		sum[x] += v;

		if(l == r) {
			return;
		}

		int mid = l + r >> 1;

		if(p <= mid) {
			update(l, mid, lc[x], p, v);
		} else {
			update(mid + 1, r, rc[x], p, v);
		}
	}

	int query(int l, int r, int x, int p) {
		if(!x) {
			return 0;
		}

		if(l == r) {
			return sum[x];
		}

		int mid = l + r >> 1;

		if(p <= mid) {
			return query(l, mid, lc[x], p);
		} else {
			return query(mid + 1, r, rc[x], p);
		}
	}

	int merge(int x, int y) {
		if(!x || !y) {
			return x + y;
		}

		int z = ++Pool;

		lc[z] = merge(lc[x], lc[y]);
		rc[z] = merge(rc[x], rc[y]);
		sum[z] = sum[x] + sum[y];

		return z;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> c;
	c.resize(n);

	for(int &i : c) {
		cin >> i;
		--i;
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

	segment_tree t(n);

	vector<int> root;
	root.resize(n);

	vector<long long> ans;
	ans.resize(n);

	vector<int> sz;
	sz.resize(n);

	function<void(int, int)> dfs = [&] (int u, int f) {
		sz[u] = 1;

		int sum = 0;

		for(int v : G[u]) {
			if(v != f) {
				dfs(v, u);
				sz[u] += sz[v];

				int d = t.query(0, n - 1, root[v], c[u]);
				sum += d;
				root[u] = t.merge(root[u], root[v]);
				
				ans[c[u]] += 1LL * (sz[v] - d) * (sz[v] - d + 1) / 2; 
			}
		}

		t.update(0, n - 1, root[u], c[u], sz[u] - sum);
	};

	dfs(0, -1);

	vector<bool> vis;
	vis.resize(n);

	for(int i : c) {
		vis[i] = true;
	}

	for(int i = 0; i < n; ++i) {
		if(vis[i]) {
			int d = n - t.query(0, n - 1, root[0], i);
			ans[i] += 1LL * d * (d + 1) / 2;
			ans[i] = 1LL * n * (n + 1) / 2 - ans[i];
		}
	}

	for(long long i : ans) {
		cout << i << '\n';
	}

	return 0;
}
