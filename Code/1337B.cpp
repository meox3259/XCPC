#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int x, n, m;
		cin >> x >> n >> m;

		vector<vector<int> > dp;
		dp.resize(n + 1);

		for(int i = 0; i <= n; ++i) {
			dp[i].assign(m + 1, x + 1);
		}

		dp[0][0] = x;

		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= m; ++j) {
				if(i + 1 <= n && dp[i][j]) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] / 2 + 10);
				}
				if(j + 1 <= m) {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] - 10);
				}
			}
		}

		bool ok = false;

		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= m; ++j) {
				if(dp[i][j] <= 0) {
					ok = true;
				}
			}
		}

		if(ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
