#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<vector<int> > dp(n + 1, vector<int> (2, inf));
		dp[0][0] = 0;
		for(int i = 0; i < n; ++i) {
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
			if(i + 2 <= n) {
				dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
			}
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (a[i] == 1));
			if(i + 2 <= n) {
				dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + (a[i] == 1) + (a[i + 1] == 1));
			}
		}

		cout << min(dp[n][0], dp[n][1]) << '\n';
	}

	return 0;
}
