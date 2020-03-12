#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
int n;
ll m;
ll fac[maxn]; 
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % m) {
		if(t & 1) {
			ret = ret * x % m;
		}
	}
	return ret;
}
int main() {
	scanf("%d%lld", &n, &m);
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % m;
	}
	ll ans = fac[n] * n % m;
	for(int i = 1; i < n ; ++i) {
		ans = ans + 1LL * (n - i) * (n - i) % m * fac[i + 1] % m * fac[n - i - 1] % m;
		ans %= m;
	}
	printf("%lld\n", ans);
	return 0;
}
