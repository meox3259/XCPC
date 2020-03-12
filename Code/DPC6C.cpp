#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, P = 1e9 + 7;
int n, k;
int a[maxn];
int c[maxn][maxn], dp[22][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= k; ++i) {
		cin >> a[i];
	}
	c[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j <= n; ++j) {
			for(int l = 0; l + j <= n && l <= a[i + 1]; ++l) {
				dp[i + 1][j + l] = (dp[i + 1][j + l] + 1LL * dp[i][j] * c[n - j][l] % P * c[n - l][a[i + 1] - l] % P) % P;
			}
		}
	}
	cout << dp[k][n] << '\n';
	return 0;
}
