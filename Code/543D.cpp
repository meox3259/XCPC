#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > G(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		p --;
		G[p].emplace_back(i);
	}

	vector<vector<long long> > dp(n, vector<long long> (2));
	function<void(int)> pre_dfs = [&] (int x) {
		dp[x][0] = 1;
		dp[x][1] = 1;
		for (int y : G[x]) {
			pre_dfs(y);
			dp[x][0] = dp[x][0] * dp[y][0] % P;
			dp[x][1] = dp[x][1] * (dp[y][0] + dp[y][1]) % P;
		}
	};

	pre_dfs(0);

	vector<long long> ans(n);
	function<void(int, long long, long long)> dfs = [&] (int x, long long zero, long long one) {
		ans[x] = (zero + one) % P;
		for (int y : G[x]) {
			ans[x] = ans[x] * (dp[y][0] + dp[y][1]) % P;
		}
		int m = G[x].size();
		vector<vector<long long> > pre(m + 1, vector<long long> (2));
		vector<vector<long long> > suf(m + 2, vector<long long> (2));
		pre[0][0] = 1;
		pre[0][1] = 1;
		for (int i = 0; i < m; ++i) {
			int y = G[x][i];
			pre[i + 1][0] = dp[y][0];
			pre[i + 1][1] = (dp[y][0] + dp[y][1]) % P;
			suf[i + 1][0] = dp[y][0];
			suf[i + 1][1] = (dp[y][0] + dp[y][1]) % P;
		}
		suf[m + 1][0] = 1;
		suf[m + 1][1] = 1;
		for (int i = 0; i < m; ++i) {
			pre[i + 1][0] = pre[i + 1][0] * pre[i][0] % P;
			pre[i + 1][1] = pre[i + 1][1] * pre[i][1] % P;
		}
		for (int i = m; i >= 0; --i) {
			suf[i][0] = suf[i][0] * suf[i + 1][0] % P;
			suf[i][1] = suf[i][1] * suf[i + 1][1] % P;
		}
		for (int i = 0; i < m; ++i) {
			int y = G[x][i];
			if (i == 0) {
				dfs(y, suf[2][0] * zero % P, suf[2][1] * (zero + one) % P);
			} else if (i == m - 1) {
				dfs(y, pre[m - 1][0] * zero % P, pre[m - 1][1] * (zero + one) % P);
			} else {
				dfs(y, pre[i][0] * suf[i + 2][0] % P * zero % P, pre[i][1] * suf[i + 2][1] % P * (zero + one) % P);
			}
		}
	};

	dfs(0, 1, 0);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}
