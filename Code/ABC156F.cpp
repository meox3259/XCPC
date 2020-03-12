#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k, q;
	cin >> k >> q;
	vector<int> d;
	d.resize(k + 1);
	for(int i = 0; i < k; ++i) {
		cin >> d[i];
	}
	d[k] = d[0];
	while(q--) {
		int n, x, m;
		cin >> n >> x >> m;
		x %= m;
		vector<ll> a;
		a.resize(k + 1);
		int eq = 0;
		for(int i = 1; i <= k; ++i) {
			a[i] = a[i - 1] + d[i - 1] % m;
			if(d[i - 1] % m == 0) {
				eq += (n - 1) / k;
				if(i <= (n - 1) % k) {
					++eq;
				}
			}
		}
		ll r = a[k] * ((n - 1) / k) + a[(n - 1) % k] + x;
		cout << n - eq - r / m - 1 << '\n';
	}
	return 0;
}
