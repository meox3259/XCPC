#include <bits/stdc++.h>

using namespace std;

namespace SegmentTree {
	int Pool = 0;

	vector<int> sum;
	vector<int> lc;
	vector<int> rc;

	void init(int n) {
		sum.resize(n * 200);
		lc.resize(n * 200);
		rc.resize(n * 200);
	}

	void update(int l, int r, int &x, int p, int v) {
		if(x == 0) {
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

	int query(int l, int r, int x, int a, int b) {
		if(x == 0 || l > b || r < a) {
			return 0;
		}
		if(l >= a && r <= b) {
			return sum[x];
		}
		int mid = l + r >> 1;
		return query(l, mid, lc[x], a, b) + query(mid + 1, r, rc[x], a, b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> val(n);
	for(int i = 0; i < n; ++i) {
		cin >> val[i];
	}

	vector<vector<int> > G(n);
	for(int i = 1; i < n; ++i) {
		int f;
		cin >> f;
		--f;
		G[f].emplace_back(i);
	}

	SegmentTree::init(n);

	vector<int> sz(n);
	vector<int> heavy(n, -1);
	vector<int> in(n);
	vector<int> out(n);
	vector<int> mir(n);
	vector<int> dep(n);
	int dfs_clock = 0;
	function<void(int)> pre = [&] (int u) {
		in[u] = dfs_clock++;
		mir[in[u]] = u;
		sz[u] = 1;
		for(int v : G[u]) {
			dep[v] = dep[u] + 1;
			pre(v);
			sz[u] += sz[v];
			if(heavy[u] == -1 || sz[v] > sz[heavy[u]]) {
				heavy[u] = v;
			}
		}
		out[u] = dfs_clock;
	};

	pre(0);

	long long ans = 0;
	vector<int> root(n + 1);
	function<void(int, bool)> dfs = [&] (int u, bool light) {
		for(int v : G[u]) {
			if(v != heavy[u]) {
				dfs(v, true);
			}
		}
		if(heavy[u] != -1) {
			dfs(heavy[u], false);
		}
		for(int v : G[u]) {
			if(v != heavy[u]) {
				for(int i = in[v]; i < out[v]; ++i) {
					if(val[u] * 2 - val[mir[i]] >= 0 && val[u] * 2 - val[mir[i]] <= n) {
						ans += SegmentTree::query(0, n, root[val[u] * 2 - val[mir[i]]], 1, min(k + dep[u] * 2 - dep[mir[i]], n));		
					}
				}
				for(int i = in[v]; i < out[v]; ++i) {
					SegmentTree::update(0, n, root[val[mir[i]]], dep[mir[i]], 1);
				}
			}
		}
		SegmentTree::update(0, n, root[val[u]], dep[u], 1);
		if(light) {
			for(int i = in[u]; i < out[u]; ++i) {
				SegmentTree::update(0, n, root[val[mir[i]]], dep[mir[i]], -1);
			}
		}
	};

	dfs(0, 0);

	cout << ans * 2 << '\n';

	return 0;
}
