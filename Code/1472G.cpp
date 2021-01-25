#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, m;
		cin >> n >> m;

		vector<vector<int> > adj(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			x --;
			y --;
			adj[x].emplace_back(y);
		}

		vector<int> d(n, -1);
		d[0] = 0;
		queue<int> q;
		q.emplace(0);

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : adj[x]) {
				if (d[y] == -1) {
					d[y] = d[x] + 1;
					q.emplace(y);
				}
			}
		}

		vector<vector<int> > dp(n, vector<int> (2, inf));

		auto dfs = [&] (auto &&f, int x, int s) -> int {
			if (dp[x][s] != inf) {
				return dp[x][s];
			}
			dp[x][s] = d[x];
			for (int y : adj[x]) {
				if (d[x] < d[y]) {
					dp[x][s] = min(dp[x][s], f(f, y, s));
				} else {
					if (s == 0) {
						dp[x][0] = min(dp[x][0], f(f, y, 1));
					}
				}
			}
			return dp[x][s];
		};

		for (int i = 0; i < n; ++i) {
			cout << min(dfs(dfs, i, 0), dfs(dfs, i, 1)) << " \n"[i == n - 1];
		}
	}

	return 0;
}
