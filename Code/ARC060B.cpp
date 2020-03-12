#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(ll b, ll n) {
	if(n < b) {
		return n;
	}
	return f(b, n / b) + (n % b);
}
int main() {
	ll n, s;
	cin >> n >> s;
	if(s > n) {
		cout << -1 << '\n';
		return 0;
	}
	for(ll b = 2; b * b <= 2 * n; ++b) {
		if(f(b, n) == s) {
			cout << b << '\n';
			return 0;
		}
	}
	vector<ll> ans;
	for(ll d = 1; d * d <= n; ++d) {
		ll x = s - d;
		if(x >= 0 && (n - x) % d == 0) {
			ll b = (n - x) / d;
			if(b > 1 && b > x) {
				ans.emplace_back(b);
			}
		}
	}
	if(s == n) {
		ans.emplace_back(n + 1);
	}
	if(ans.empty()) {
		cout << -1 << '\n';
	} else {
		cout << *min_element(ans.begin(), ans.end()) << '\n';
	}
	return 0;
}
