#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, b, P;
	cin >> n >> m >> b >> P;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<int> > dp(m + 1, vector<int> (b + 1));
	dp[0][0] = 1;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			for (int k = b; k >= a[j]; --k) {
				dp[i + 1][k] = (dp[i + 1][k] + dp[i][k - a[j]]) % P;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= b; ++i) {
		ans = (ans + dp[m][i]) % P;
	}

	cout << ans << '\n';

	return 0;
}
