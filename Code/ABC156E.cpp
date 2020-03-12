#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1'000'000'007;
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
	int n, k;
	cin >> n >> k;
	k = min(k, n - 1);
	vector<ll> fac;
	vector<ll> inv;
	vector<ll> facinv;
	fac.resize(n + 1);
	inv.resize(n + 1);
	facinv.resize(n + 1);
	fac[0] = 1;
	inv[1] = 1;
	facinv[0] = 1;
	for(int i = 1; i <= n; ++i) {
		if(i != 1) {
			inv[i] = (P - P / i) * inv[P % i] % P;
		}
		fac[i] = fac[i - 1] * i % P;
		facinv[i] = facinv[i - 1] * inv[i] % P;
	}
	auto C = [&] (int n, int m) {
		return fac[n] * facinv[m] % P * facinv[n - m] % P;
	};
	ll ans = 0;
	for(int i = 0; i <= k; ++i) {
		ans = (ans + C(n, i) * C(n - 1, i) % P) % P;
	}
	cout << ans << '\n';
	/*
	 1 1 2

	 3 1
	 2 2
	 1 3
	 */
	return 0;
}
