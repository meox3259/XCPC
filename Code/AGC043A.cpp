#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> s;
	s.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector<vector<int> > dp;
	dp.resize(n);

	for(int i = 0; i < n; ++i) {
		dp[i].assign(m, inf);
	}

	dp[0][0] = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(i + 1 < n) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (s[i][j] != s[i + 1][j]));
			}

			if(j + 1 < m) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (s[i][j] != s[i][j + 1]));
			}
		}
	}

	dp[n - 1][m - 1] += (s[0][0] == '#') + (s[n - 1][m - 1] == '#');

	cout << dp[n - 1][m - 1] / 2 << '\n';

	return 0;
}
