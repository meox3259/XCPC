#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int> > a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), greater<pair<int, int> > ());

	vector<vector<long long> > dp;
	dp.resize(n + 1);

	for(int i = 0; i < n + 1; ++i) {
		dp[i].resize(n + 1);
	}

	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j + i < n; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1LL * a[i + j].first * abs(a[i + j].second - i));
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1LL * a[i + j].first * abs(n - 1 - j - a[i + j].second));
		}
	}

	long long ans = 0;

	for(int i = 0; i < n + 1; ++i) {
		ans = max(ans, dp[i][n - i]);
	}

	cout << ans << '\n';

	return 0;
}
