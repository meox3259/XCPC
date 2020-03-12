#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1000003;
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> fac(P);
	fac[0] = 1;
	for(int i = 1; i < P; ++i) {
		fac[i] = fac[i - 1] * i % P;
	} 
	int q;
	cin >> q;
	while(q--) {
		ll x, d, n;
		cin >> x >> d >> n;
		if(d == 0) {
			cout << power(x, n) << '\n';
			continue;
		}
		x = x * power(d, P - 2) % P;
		if(x + n - 1 >= P) {
			cout << 0 << '\n';
		} else {
			cout << fac[x + n - 1] * power(fac[x - 1], P - 2) % P * power(d, n) % P << '\n';
		}
	}
	return 0;
}
