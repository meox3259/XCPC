#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n, A;
	cin >> n >> A;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<ll> > dp;
	dp.assign(n + 1, vector<ll> ());
	for(int i = 0; i <= n; ++i) {
		dp[i].assign(5005, 0);
	}
	dp[0][2500] = 1;
	for(int i = 0; i < n; ++i) {
		int x = a[i] - A;
		for(int j = 0; j <= 5000; ++j) {
			dp[i + 1][j] += dp[i][j];
			if(j + x >= 0) {
				dp[i + 1][j + x] += dp[i][j];
			}
		}
	}
	cout << dp[n][2500] - 1  << '\n';
	return 0;
}
