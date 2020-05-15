#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> dp(n);

		vector<int> sum(n);

		sum[0] = s[0] - '0';
		for(int i = 0; i + 1 < n; ++i) {
			sum[i + 1] = sum[i] + (s[i + 1] - '0');
		}

		for(int i = 1; i < k; ++i) {
			dp[i] = sum[i - 1];
		}

		for(int i = k; i < n; ++i) {
			dp[i] = dp[i - k] + sum[i - 1] - sum[i - k] + (s[i] == '0');
			dp[i] = min(dp[i], sum[i]);
		}

		int ans = n;

		for(int i = 0; i < n; ++i) {
			ans = min(ans, dp[i] + sum[n - 1] - sum[i]);
		}

		cout << ans << '\n';
	}

	return 0;
}
