#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll phi(ll x) {
	ll ret = x;
	for(ll i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			ret = ret / i * (i - 1);
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		ret = ret / x * (x - 1);
	}
	return ret;
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		ll a, m;
		cin >> a >> m;
		ll d = __gcd(a, m);
		ll x = m / d;
		printf("%lld\n", phi(m / d));
	}
	return 0;
}
