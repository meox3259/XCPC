#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	if (n > m) {
		swap(n, m);
		swap(a, b);
	}

	vector<vector<int> > dp(n + 1, vector<int> (m + 1, inf));
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i < n) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			}
			if (j < m) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			}
			if (i < n && j < m) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));
			}
		}
	}

	cout << dp[n][m] << '\n';
	
	return 0;
}
