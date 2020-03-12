#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ll pre = 0, ans = sum;
	for(int i = 0; i < n; ++i) {
		pre += a[i];
		ans = min(ans, abs(2LL * pre - sum));
	}
	cout << ans << '\n';
	return 0;
}
