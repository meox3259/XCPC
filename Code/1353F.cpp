#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

template <typename T>
void chkmin(T &x, T y) {
	if(x > y) {
		x = y;
	}
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;

		vector<vector<long long> > a(n, vector<long long> (m));

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}

		auto dis = [&] (int i, int j, int x, int y) {
			return abs(i - x) + abs(j - y);
		};

		long long ans = inf;

		for(int x = 0; x < n; ++x) {
			for(int y = 0; y < m; ++y) {
				long long v = a[x][y];
				vector<vector<long long> > dp(n, vector<long long> (m, inf));
				if(v - dis(0, 0, x, y) <= a[0][0]) {
					dp[0][0] = abs(v - dis(0, 0, x, y) - a[0][0]);
				}
				for(int i = 0; i <= x; ++i) {
					for(int j = 0; j <= y; ++j) {
						if(i + 1 <= x && v - dis(i + 1, j, x, y) <= a[i + 1][j]) {
							chkmin(dp[i + 1][j], dp[i][j] - v + dis(i + 1, j, x, y) + a[i + 1][j]);
						}
						if(j + 1 <= y && v - dis(i, j + 1, x, y) <= a[i][j + 1]) {
							chkmin(dp[i][j + 1], dp[i][j] - v + dis(i, j + 1, x, y) + a[i][j + 1]);
						}
					}
				}

				for(int i = x; i < n; ++i) {
					for(int j = y; j < m; ++j) {
						if(i + 1 < n && v + dis(i + 1, j, x, y) <= a[i + 1][j]) {
							chkmin(dp[i + 1][j], dp[i][j] - v - dis(i + 1, j, x, y) + a[i + 1][j]);
						}
						if(j + 1 < m && v + dis(i, j + 1, x, y) <= a[i][j + 1]) {
							chkmin(dp[i][j + 1], dp[i][j] - v - dis(i, j + 1, x, y) + a[i][j + 1]);
						}
					}
				}

				ans = min(ans, dp[n - 1][m - 1]);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
