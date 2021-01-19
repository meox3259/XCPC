#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > g(n, vector<int> (n, 1));
	for (int i = 0; i < n; ++i) {
		g[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a --;
		b --;
		g[a][b] = 0;
		g[b][a] = 0;
	}

	vector<bool> vis(n);
	vector<int> c(n);
	vector<pair<int, int> > obj;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			int c0 = 0;
			int c1 = 0;
			function<void(int)> dfs = [&] (int x) {
				vis[x] = true;
				if (c[x] == 0) {
					c0 ++;
				} else {
					c1 ++;
				}
				for (int y = 0; y < n; ++y) {
					if (g[x][y]) {
						if (!vis[y]) {
							c[y] = c[x] ^ 1;
							dfs(y);
						} else if (c[x] == c[y]) {
							ok = false;
						}
					}
				}
			};

			dfs(i);
			obj.emplace_back(c0, c1);
		}
	}

	if (!ok) {
		cout << -1 << '\n';
		exit(0);
	}

	vector<int> dp(n + 1);
	dp[0] = 1;
	for (auto [x, y] : obj) {
		vector<int> tmp(n + 1);
		for (int i = n; i >= 0; --i) {
			if (i >= x) {
				tmp[i] |= dp[i - x];
			}
			if (i >= y) {
				tmp[i] |= dp[i - y];
			}
		}
		swap(dp, tmp);
	}

	int ans = n * n;
	for (int i = 0; i <= n; ++i) {
		if (dp[i]) {
			ans = min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
		}
	}

	cout << ans << '\n';

	return 0;
}
