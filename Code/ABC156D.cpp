#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}
ll C(int n, int m) {
	ll ret = 1;
	for(int i = 1; i <= m; ++i) {
		ret = ret * power(i, P - 2) % P;
	}
	for(int i = n; i > n - m; --i) {
		ret = ret * i % P;
	}
	return ret;
}
int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = (power(2LL, n) - 1 + P) % P;
	ans = ((ans - C(n, a) - C(n, b)) % P + P) % P;
	cout << ans << '\n';
	return 0;
}
