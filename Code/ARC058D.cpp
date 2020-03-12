#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int maxn = 2e5 + 5;
ll fac[maxn], inv[maxn], facinv[maxn];
ll C(int n, int m) {
	if(n < m) {
		return 0;
	}
	return fac[n] * facinv[m] % P * facinv[n - m] % P;
}
int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	fac[0] = 1;
	inv[1] = 1;
	facinv[0] = 1;
	for(int i = 1; i < maxn; ++i) {
		fac[i] = fac[i - 1] * i % P;
		if(i != 1) {
			inv[i] = (P - P / i) * inv[P % i] % P;
		}
		facinv[i] = facinv[i - 1] * inv[i] % P;
	}
	ll ans = 0;
	for(int i = b + 1; i <= w; ++i) {
		ll delta = C(h - a + i - 2, i - 1) * C(a + w - i - 1, a - 1) % P;
		ans = (ans + delta) % P;
	}
	cout << ans << '\n';
	return 0;
}
