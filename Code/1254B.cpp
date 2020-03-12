#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int n;
ll m;
ll a[maxn], pre[maxn], suf[maxn];
vector<ll> fac;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		m += a[i];
	}
	if(m == 1) {
		puts("-1");
		return 0;
	}
	for(ll i = 2; i * i <= m; ++i) {
		if(m % i == 0) {
			while(m % i == 0) {
				m /= i;
			}
			fac.emplace_back(i);
		}
	}
	if(m > 1) {
		fac.emplace_back(m);
	}
	ll ans = 1e18;
	for(auto x : fac) {
		for(int i = 1; i <= n; ++i) {
			pre[i] = (pre[i - 1] + a[i]) % x;
		}
		for(int i = n; i; --i) {
			suf[i] = (suf[i + 1] + a[i]) % x;
		}
		ll tot = 0;
		for(int i = 1; i <= n; ++i) {
			tot += min(pre[i], suf[i + 1]);
		}
		ans = min(ans, tot);
	}
	printf("%lld\n", ans);
	return 0;
}
