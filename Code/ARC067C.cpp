#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	vector<vector<long long> > dp;
	dp.resize(n + 1);
	for(int i = 0; i < n + 1; ++i) {
		dp[i].resize(n + 1);
	}

	dp[0][0] = 1;

	auto power = [&] (long long x, long long t) {
		long long ret = 1;
		
		for(; t; t >>= 1, x = x * x % P) {
			if(t & 1) {
				ret = ret * x % P;
			}
		}

		return ret;
	};

	vector<long long> fac;
	fac.resize(n + 1);
	
	fac[0] = 1;
	for(int i = 1; i < n + 1; ++i) {
		fac[i] = fac[i - 1] * i % P;
	}

	vector<vector<long long> > pow;
	pow.resize(n + 1);
	
	for(int i = 0; i < n + 1; ++i) {
		pow[i].resize(n + 1);
	}
	
	vector<long long> inv;
	inv.resize(n + 1);

	inv[0] = 1;
	for(int i = 1; i < n + 1; ++i) {
		inv[i] = power(i, P - 2);
	}

	for(int i = 0; i < n + 1; ++i) {
		pow[i][0] = 1;

		fac[i] = power(fac[i], P - 2);

		for(int j = 1; j < n + 1; ++j) {
			pow[i][j] = pow[i][j - 1] * fac[i] % P;
		}

	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= n; ++j) {
			for(int k = 0; j + k * (i + 1) <= n; ++k) {
				if(k == 0 || (a <= i + 1 && i + 1 <= b && c <= k && k <= d)) {
					dp[i + 1][j + k * (i + 1)] = (dp[i + 1][j + k * (i + 1)] + dp[i][j] * pow[i + 1][k] % P * fac[k] % P) % P;
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i) {
		dp[n][n] = dp[n][n] * i % P;
	}

	cout << dp[n][n] << '\n';

	return 0;

}
