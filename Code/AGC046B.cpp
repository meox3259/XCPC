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
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	long long inv = power(2, P - 2);

	vector<vector<long long> > dp(c + 1, vector<long long> (d + 1));
	dp[a][b] = 1;
	for(int i = b; i < d; ++i) {
		dp[a][i + 1] = dp[a][i] * a % P;
	}
	for(int i = a; i < c; ++i) {
		dp[i + 1][b] = dp[i][b] * b % P;
	}
	for(int i = a + 1; i <= c; ++i) {
		for(int j = b + 1; j <= d; ++j) {
			dp[i][j] = (dp[i - 1][j] * j + dp[i][j - 1] * i - dp[i - 1][j - 1] * (i * j + 1 - i - j) % P + P) % P;
		}
	}

	cout << dp[c][d] << '\n';

	return 0;
}
