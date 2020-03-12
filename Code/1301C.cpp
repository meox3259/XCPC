#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		ll n, m;
		cin >> n >> m;
		ll ans = 0;
		ans = n * (n + 1) / 2;
		ll t = n - m;
		ll x = t / (m + 1), y = t % (m + 1);
		ans -= y * (x + 2) * (x + 1) / 2 + (m + 1 - y) * x * (x + 1) / 2;
		cout << ans << '\n';
	}
	return 0;
}
