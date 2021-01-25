#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "AND") {
			a[i] = 0;
		} else {
			a[i] = 1;
		}
	}

	vector<vector<long long> > dp(n + 1, vector<long long> (2));
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			dp[i + 1][0] += dp[i][0] * 2 + dp[i][1];
			dp[i + 1][1] += dp[i][1];
		} else {
			dp[i + 1][0] += dp[i][0];
			dp[i + 1][1] += dp[i][0] + dp[i][1] * 2;
		}
	}

	cout << dp[n][1] << '\n';

	return 0;
}
