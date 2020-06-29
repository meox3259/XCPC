#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<vector<int> > G(n);
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}

	vector<int> dep(n);
	vector<int> dp(n);
	vector<int> sz(n);
	vector<int> Sum(n);

	function<void(int, int)> dfs = [&] (int u, int f) {
		sz[u] = (s[u] == '1');
		dp[u] = 0;
		Sum[u] = dep[u] * (s[u] == '1');
		for(int v : G[u]) {
			if(v != f) {
				dep[v] = dep[u] + 1;
				dfs(v, u);
				int y = min(dp[u], dp[v] + sz[v]);
				dp[u] = dp[u] + dp[v] + sz[v] - 2 * y;
				sz[u] += sz[v];
				Sum[u] += Sum[v];
			}
		}
	};

	int ans = inf;
	for(int i = 0; i < n; ++i) {
		dep[i] = 0;	
		dfs(i, -1);

		int tmp = 0;
		bool ok = true;

		for(int j : G[i]) {
			tmp += dp[j];
		}

		for(int j : G[i]) {
			if(dp[j] + sz[j] > Sum[i] - Sum[j]) {
				ok = false;
			}
		}

		if(ok && Sum[i] % 2 == 0) {
			ans = min(ans, Sum[i] / 2);
		}
	}

	if(ans == inf) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
