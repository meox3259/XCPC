#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T-- ) {

		int n, a, b;
		cin >> n >> a >> b;

		string s;
		cin >> s;

		vector<vector<long long> > dp(n + 1, vector<long long> (2, inf));
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1' || (i + 1 < n && s[i + 1] == '1')) {
				dp[i + 1][1] = min(dp[i][1] + a + b, dp[i][0] + b + a + a);
			} else {
				dp[i + 1][0] = min(dp[i][0] + a, dp[i][1] + a + a);
				dp[i + 1][1] = min(dp[i][1] + a + b, dp[i][0] + b + a + a);
			}
		}

		cout << dp[n][0] + 1LL * (n + 1) * b << '\n';

	}

	return 0;
}
