#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 998244353;
const int maxn = 2e5 + 5;
int n;
ll p[maxn];
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
	scanf("%d", &n);
	ll f = 1, ans = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]);
	}
	for(int i = n; i; --i) {
		f = f * power(p[i], P - 2) % P * 100LL % P;
		ans = (ans + f) % P;
	}
	printf("%lld\n", ans);
	// dp[i] = p[i] * dp[i + 1] + (1 - p[i]) * dp[1] + 1
	// dp[n] = p[n] + (1 - p[n]) * dp[1] + 1
	// dp[1] = p[1] * dp[2] + (1 - p[1]) * dp[1] + 1
	// dp[1] = dp[2] + 1 / p[1]
	// dp[2] = p[2] * dp[3] + (1 - p[2]) * (dp[1] + 1 / p[1]) + 1
	// p[2] * dp[2] = dp[3] + 1 / (p[1] * p[2]) + 1 / dp[2]
	return 0;
}
