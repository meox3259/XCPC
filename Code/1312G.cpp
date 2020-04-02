#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> dp;
	dp.resize(n + 1);

	vector<vector<int> > G;
	G.resize(n + 1);

	for(int i = 0; i < n + 1; ++i) {
		G[i].resize(26, -1);
	}

	for(int i = 0; i < n; ++i) {
		int p;
		cin >> p;

		char c;
		cin >> c;

		G[p][c - 'a'] = i + 1;
	}
	
	int k;
	cin >> k;

	vector<int> a;
	a.resize(k);

	vector<int> mark;
	mark.resize(n + 1);

	for(int i = 0; i < k; ++i) {
		cin >> a[i];
		mark[a[i]] = 1;
	}

	int sum = 0;

	vector<int> f;
	f.resize(n + 1, inf);

	function<void(int)> dfs = [&] (int u) {
		if(mark[u]) {
			++sum;
			dp[u] = min(dp[u], f[u] + sum);
			f[u] = min(f[u], dp[u] - sum + 1);
		} else {
			f[u] = min(f[u], dp[u] - sum);
		}

		int cur = sum;

		for(auto v : G[u]) {
			if(v != -1) {
				dp[v] = dp[u] + 1;
				f[v] = f[u];
				dfs(v);
			}
		}
	};

	dfs(0);

	for(int i = 0; i < k; ++i) {
		cout << dp[a[i]] << ' ';
	}

	cout << '\n';

	return 0;
}
