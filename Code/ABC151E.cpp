#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5, P = 1e9 + 7;
int n, k;
ll fac[maxn], inv[maxn], a[maxn], facinv[maxn];
ll C(int n, int k) {
	return fac[n] * facinv[k] % P * facinv[n - k] % P;
}
int main() {
	scanf("%d%d", &n, &k);
	fac[0] = 1;
	inv[1] = 1;
	facinv[0] = 1;
	for(int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % P;
		if(i != 1) {
			inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
		}
		facinv[i] = facinv[i - 1] * inv[i] % P;
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for(int i = k; i <= n; ++i) {
		ans = (ans + 1LL * a[i] * C(i - 1, k - 1) % P + P) % P;
	}
	for(int i = 1; i <= n - k + 1; ++i) {
		ans = (ans - 1LL * a[i] * C(n - i, k - 1) % P + P) % P;
	}
	printf("%lld\n", ans);
	return 0;
}
