#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll tmp = n;
		n = (n + 1) / 2;
		ll ans = 0;
		ll t = n / g;
		if(n % g != 0) {
			ans = t * (b + g) + n % g;
		} else {
			ans = max(t - 1, 0LL) * (b + g) + g;
		}
		cout << max(ans, tmp) << '\n';
	}
	return 0;
}
