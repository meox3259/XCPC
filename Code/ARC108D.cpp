#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

template <typename T> void add(T &x, T y) {
	x = (x + y) % P;
}

int main() {
	int n;
	cin >> n;

	vector<vector<char> > c(2, vector<char> (2));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> c[i][j];
		}
	}

	if (c[0][1] == 'A') {
		if (c[0][0] == 'A') {
			cout << 1 << '\n';
		} else {
			if (c[1][0] == 'B') {
				// dp1
				vector<long long> dp(n + 1);
				for (int i = 2; i <= n; ++i) {
					dp[i] = 1;
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 2; j + i <= n; ++j) {
						add(dp[j + i], dp[i] * (j - 1) % P);	
					}
				}
				cout << dp[n] << '\n';
			} else {
				// dp2
				vector<long long> dp(n + 1);
				for (int i = 2; i <= n; ++i) {
					dp[i] = 1;
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 2; j + i <= n; ++j) {
						add(dp[j + i], dp[i]);
					}
				}
				cout << dp[n] << '\n';
			}
		}
	} else {
		if (c[1][1] == 'B') {
			cout << 1 << '\n';
		} else {
			if (c[1][0] == 'A') {
				// dp1
				vector<long long> dp(n + 1);
				for (int i = 2; i <= n; ++i) {
					dp[i] = 1;
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 2; j + i <= n; ++j) {
						add(dp[j + i], dp[i] * (j - 1) % P);
					}
				}
				cout << dp[n] << '\n';
			} else {
				// dp2
				vector<long long> dp(n + 1);
				for (int i = 2; i <= n; ++i) {
					dp[i] = 1;
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 2; j + i <= n; ++j) {
						add(dp[j + i], dp[i]);
					}
				}
				cout << dp[n] << '\n';
			}
		}
	}

	return 0;
}
