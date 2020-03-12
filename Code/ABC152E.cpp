#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5, P = 1e9 + 7;
int n;
int a[maxn], cnt[maxn];
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
	ll lcm = 1;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ll t = a[i];
		for(ll j = 2; j * j <= t; ++j) {
			int c = 0;
			if(t % j == 0) {
				while(t % j == 0) {
					t /= j;
					++c;
				}	
			} 
			cnt[j] = max(cnt[j], c);
		}
		if(t > 1) {
			cnt[t] = max(cnt[t], 1);
		}
	}
	for(int i = 1; i <= (int)1e6; ++i) {
		if(cnt[i]) {
			lcm = lcm * power(i, cnt[i]) % P;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = (ans + lcm * power(a[i], P - 2)) % P;
	}
	printf("%lld\n", ans);
	return 0;
}
