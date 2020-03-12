#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int main() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n), b(n);
	vector<vector<int> > dp;
	dp.assign(n + 2, vector<int> ());
	for(int i = 0; i <= n; ++i) {
		dp[i].assign(c + 1, 0);
	}
	vector<vector<int> > pre;
	pre.assign(405, vector<int> ());
	for(int i = 0; i <= 400; ++i) {
		pre[i].assign(405, 0);
	}
	for(int i = 0; i <= 400; ++i) {
		pre[i][0] = 1;
		for(int j = 1; j <= 400; ++j) {
			pre[i][j] = 1LL * pre[i][j - 1] * i % P;
		}
	}
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		vector<int> sum(c + 1, 0);
		for(int j = 0; j <= c; ++j) {
			for(int k = a[i]; k <= b[i]; ++k) {
				sum[j] = (sum[j] + pre[k][j]) % P;
			}
		}
		for(int j = 0; j <= c; ++j) {
			for(int k = 0; k + j <= c; ++k) {
				dp[i + 1][j + k] = (dp[i + 1][j + k] + 1LL * dp[i][j] * sum[k] % P) % P;
			}
		}
	}
	cout << dp[n][c] << '\n';
	return 0;
}
