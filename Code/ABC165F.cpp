#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int &i : a) {
		cin >> i;
	}

	vector<vector<int> > G(n);

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> ans(n);

	int mx = *max_element(a.begin(), a.end());

	vector<int> dp(n, mx + 1);

	function<void(int, int)> dfs = [&] (int u, int f) {
		int p = lower_bound(dp.begin(), dp.end(), a[u]) - dp.begin();
		ans[u] = max(ans[u], p + 1);
		int tmp = dp[p];
		dp[p] = a[u];
		for(int v : G[u]) {
			if(v != f) {
				ans[v] = max(ans[v], ans[u]);
				dfs(v, u);
			}
		}
		dp[p] = tmp;
	};

	dfs(0, -1);

	for(int i : ans) {
		cout << i << '\n';
	}

	return 0;
}
