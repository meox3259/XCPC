#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {

	int n;
	cin >> n;

	vector<vector<int> > G(n);
	vector<pair<int, int> > edge;
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
		edge.emplace_back(x, y);
	}

	vector<int> sz(n);
	vector<int> mx(n);
	function<void(int, int)> dfs = [&] (int u, int f) {
		sz[u] = 1;
		for(int v : G[u]) {
			if(v != f) {
				dfs(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
		}
		mx[u] = max(mx[u], n - sz[u]);
	};

	dfs(0, -1);	

	int S = *min_element(mx.begin(), mx.end());
	vector<int> centre;
	for(int i = 0; i < n; ++i) {
		if(mx[i] == S) {
			centre.emplace_back(i);
		}
	}

	if(centre.size() == 1) {
		cout << edge[0].first + 1 << ' ' << edge[0].second + 1 << '\n';
		cout << edge[0].first + 1 << ' ' << edge[0].second + 1 << '\n';
		continue;
	}

	int x = centre[0];
	int y = centre[1];

	int cx = -1;
	int cy = -1;
	function<void(int, int)> dfs_1 = [&] (int u, int f) {
		if(G[u].size() == 1) {
			cx = u;
			cy = f;
		}
		for(int v : G[u]) {
			if(v != f) {
				dfs_1(v, u);
			}
		}
	};

	dfs_1(x, y);

	cout << cx + 1 << ' ' << cy + 1 << '\n';
	cout << cx + 1 << ' ' << y + 1 << '\n';

	}

	return 0;
}
