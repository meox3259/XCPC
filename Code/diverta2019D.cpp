#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 * 5000 + 5;
int n;
int a[6][6];
long long dp[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		dp[i] = i;
	}
	for(int i = 0; i < 3; ++i) {
		for(int j = a[0][i]; j <= n; ++j) {
			dp[j] = max(dp[j], dp[j - a[0][i]] + a[1][i]);
		}
	}
	int lim = dp[n];
	long long ans = dp[n];
	for(int i = 1; i <= lim; ++i) {
		dp[i] = i;
	}
	for(int i = 0; i < 3; ++i) {
		for(int j = a[1][i]; j <= lim; ++j) {
			dp[j] = max(dp[j], dp[j - a[1][i]] + a[0][i]);
		}
	}
	cout << max(ans, dp[lim]) << '\n';
	return 0;
}
