#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

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

	vector<vector<long long> > dp;
	dp.resize(n);

	for(int i = 0; i < n; ++i) {
		dp[i].resize(3);
	}

	function<void(int, int)> dfs = [&] (int u, int f) {
		dp[u][0] = 1;

		for(auto v : G[u]) {
			if(v != f) {
				dfs(v, u);

				dp[u][1] = dp[u][1] * (dp[v][0] * 3 + dp[v][1] * 2 + dp[v][2] * 2) % P;
				dp[u][1] = (dp[u][1] + dp[u][0] * (dp[v][0] * 2 + dp[v][1] + dp[v][2])) % P;

				dp[u][2] = dp[u][2] * (dp[v][0] * 2 + dp[v][1] * 2 + dp[v][2]) % P;
				dp[u][2] = (dp[u][2] + dp[u][0] * (dp[v][0] + dp[v][1])) % P;

				dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1] + dp[v][2]) % P;
			}
		}
	}; 

	dfs(0, -1);

	cout << (dp[0][0] + dp[0][1] + dp[0][2] - 1 + P) % P << '\n';

	return 0;
}
