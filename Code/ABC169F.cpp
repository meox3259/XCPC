#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

long long power(long long x, long long t) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> pw(n + 1);
	pw[0] = 1;
	for(int i = 0; i + 1 <= n; ++i) {
		pw[i + 1] = pw[i] * 2 % P;
	}

	long long inv2 = power(2, P - 2);

	vector<vector<long long> > dp(n + 1, vector<long long> (s + 1));
	dp[0][0] = pw[n];

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= s; ++j) {
			dp[i + 1][j] = dp[i][j];
		}
		for(int j = 0; j + a[i] <= s; ++j) {
			dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + dp[i][j] * inv2) % P;
		}
	}

	cout << dp[n][s] << '\n';

	return 0;
}
