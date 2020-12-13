#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<long long> > dp(n + 1, vector<long long> (12));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 12; ++j) {
			for (int k = i + 1; k <= n; ++k) {
				dp[k][j + 1] += dp[i][j];
			}
		}
	}

	cout << dp[n][12] << '\n';

	return 0;
}
