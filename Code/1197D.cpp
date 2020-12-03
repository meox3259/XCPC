#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<long long> > dp(n + 1, vector<long long> (m + 1, -inf));
	dp[0][0] = 0;

	for (int i = 0; i < n; ++i) {
		dp[i + 1][0] = 0;
		for (int j = 0; j < m; ++j) {
			dp[i + 1][(j + 1) % m] = max(dp[i + 1][(j + 1) % m], dp[i][j] + a[i] - (j == 0) * k);	
		}
	}

	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}

	cout << ans << '\n';

	return 0;
}
