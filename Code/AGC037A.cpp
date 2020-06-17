#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();

	vector<vector<int> > dp(n + 1, vector<int> (2));

	dp[1][0] = 1;
	for(int i = 0; i < n; ++i) {
		if(i + 2 <= n) {
			dp[i + 2][1] = max(dp[i + 2][1], dp[i][0] + 1);
			if(i > 1 && s.substr(i - 2, 2) != s.substr(i, 2)) {
				dp[i + 2][1] = max(dp[i + 2][1], dp[i][1] + 1);
			}
		}
		if(i > 0 && s[i] != s[i - 1]) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1);
		}
		if(i > 1) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 1);
		}
	}

	cout << max(dp[n][0], dp[n][1]) << '\n';

	return 0;
}
