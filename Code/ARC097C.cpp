#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max() / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<pair<int, int> > > p(2);
	for (int i = 0; i < n + n; ++i) {
		char c;
		int a;
		cin >> c >> a;
		a --;
		if (c == 'W') {
			p[0].emplace_back(a, i);
		} else {
			p[1].emplace_back(a, i);
		}
	}

	for (int i = 0; i < 2; ++i) {
		sort(p[i].begin(), p[i].end());
	}

	int ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < p[i].size(); ++j) {
			for (int k = j + 1; k < p[i].size(); ++k) {
				ans += (p[i][j].second > p[i][k].second);
			}
		}
	}

	vector<vector<int> > dp(n + 1, vector<int> (n + 1, inf));
	dp[0][0] = 0;

	vector<vector<int> > sumi(n, vector<int> (n + 1));
	vector<vector<int> > sumj(n, vector<int> (n + 1));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sumi[i][j + 1] = sumi[i][j] + (p[0][i].second < p[1][j].second);	
			sumj[i][j + 1] = sumj[i][j] + (p[1][i].second < p[0][j].second);
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i < n) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + sumi[i][j]);
			}
			if (j < n) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + sumj[j][i]);
			}
		}
	}

	cout << ans + dp[n][n] << '\n';

	return 0;
}
