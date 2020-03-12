#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cou(ll x) {
	ll ret = 1;
	while(x) {
		ret *= 10;
		x /= 10;
	}
	return ret;
}
int main() {
	int T; cin >> T;
	while(T--) {
		int cnt = 0;
		ll A, B, ans = 0; cin >> A >> B; /*
		for(ll i = 1; i <= A; ++i) {
			for(ll j = 1; j <= B; ++j) {
				if(i * j + i + j == i * cou(j) + j) {
					printf("%lld %lld\n", i, j);
					++cnt;
				}
			}
		}
		printf("%d\n", cnt); */
		ll t = 0;
		while(t * 10 + 9 <= B) {
			++cnt;
			t = t * 10 + 9;
		}
		printf("%lld\n", cnt * A);
	}
	return 0;
}
