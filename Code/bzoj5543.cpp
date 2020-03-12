#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n, m, p;
ll mul(ll A, ll B) {
    return (A * B - (ll)((long double)A * B / p) * p + p) % p;
}
ll power(ll x, ll t) {
	ll ret = 1;
	while(t) {
		if(t & 1LL) {
			ret = mul(ret, x);
		}
		t >>= 1LL;
		x = mul(x, x);
	}
	return ret;
}
int main() {
	scanf("%lld%lld%lld%lld", &k, &n, &m, &p);
	ll ans = 0;
	for(ll i = m; i <= n; ++i) {
		ans = (ans + power(i, k)) % p;
	}
	printf("%lld\n", ans);
	return 0;
}
