#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll c(ll x) {
	ll ret = 0;
	for(ll i = 0; i < 63; ++i) {
		if((x << i) > n) {
			break;
		}
		ll d = n - (x << i);
		ret += min((1LL << i) * (1 + ((x & 1) ^ 1)), d + 1);
	}
	return ret;
}
int main() {
	cin >> n >> k;
	ll l = 0, r = n + 1, ans = 1;
	while(r - l > 1) {
		ll mid = l + r >> 1;
		if(c(mid * 2 - 1) >= k) {
			l = mid;
		} else {
			r = mid;
		}
	}
	ans = 2 * l - 1;
	l = 0;
	r = n + 1;
	while(r - l > 1) {
		ll mid = l + r >> 1;
		if(c(mid * 2) >= k) {
			l = mid;
		} else {
			r = mid;
		}
	}
	ans = max(ans, 2 * l);
	cout << ans << endl;
	return 0;
}
