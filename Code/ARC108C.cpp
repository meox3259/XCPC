#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int> > > G(n);
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		x --;
		y --;
		c --;
		G[x].emplace_back(y, c);
		G[y].emplace_back(x, c);
	}

	vector<int> ans(n);
	vector<bool> vis(n);
	function<void(int)> dfs = [&] (int x) {
		vis[x] = true;
		for (auto o : G[x]) {
			int y = o.first;
			int c = o.second;
			if (!vis[y]) {
				if (ans[x] == c) {
					ans[y] = (c + 1) % n;
					dfs(y);
				} else {
					ans[y] = c;
					dfs(y);
				}
			}
		}
	};

	ans[0] = 0;
	dfs(0);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << '\n';
	}

	return 0;
}
