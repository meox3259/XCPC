#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int maxn = 1e6 + 5;
int n, d, h;
ll dp[maxn], sum[maxn];
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}
int main() {
	cin >> n >> h >> d;
	ll fac = 1, s = 0;
	for(int i = 1; i <= n; ++i) {
		fac = fac * i % P;
		s = (s + fac) % P;
	}
	dp[0] = sum[0] = 1;
	for(int i = 1; i <= h; ++i) {
		dp[i] = (sum[i - 1] - (i - d - 1 >= 0 ? sum[i - d - 1] : 0) + P) % P;
		dp[i] = dp[i] * s % P;
		sum[i] = (sum[i - 1] + dp[i]) % P;
	}
	dp[h] = dp[h] * power(s, P - 2) % P * fac % P;
	cout << dp[h] << '\n';
	return 0;
}
