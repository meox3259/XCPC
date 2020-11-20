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
	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[1] = 1;

	long long odd = 1;
	long long even = 0;

	for(int i = 2; i <= n; ++i) {
		if(i & 1) {
			dp[i] = (even + 1) % P;
			odd = (odd + dp[i]) % P;
		} else {
			dp[i] = odd;
			even = (even + dp[i]) % P;
		}
	}

	long long ans = dp[n];
	ans = ans * power(power(2, n), P - 2) % P;

	cout << ans << '\n';

	return 0;
}
