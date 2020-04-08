#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<long long> > dp;
	dp.resize(k + 1);

	for(int i = 0; i < k + 1; ++i) {
		dp[i].resize(k + 1);
	}

	dp[0][0] = 1;

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j <= k; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j) % P;
			if(j + 1 <= k) {
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (n - j)) % P;
			}
		}
	}

	auto power = [&] (long long x, long long t) {
		long long ret = 1;

		for(; t; t >>= 1, x = x * x % P) {
			if(t & 1) {
				ret = ret * x % P;
			}
		}

		return ret;
	};

	auto inv = [&] (long long x) {
		return power(x, P - 2);
	};

	long long ans = 0;

	for(int i = 1; i <= k; ++i) {
		ans = (ans + dp[k][i] * power(inv(m), i)) % P;
	}

	cout << ans << '\n';

	return 0;
}
