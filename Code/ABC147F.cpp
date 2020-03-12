#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1e16;

int main() {
	ll n, x, d;
	cin >> n >> x >> d;
	
	if(d == 0) {
		if(x == 0) {
			cout << 1 << '\n';
		} else {
			cout << n + 1 << '\n';
		}
		return 0;
	}

	if(d < 0) {
		d = -d;
		x = -x;
	}

	map<ll, vector<pair<ll, ll> > > mp;

	for(int i = 0; i < n + 1; ++i) {
		ll s = x * i;
		ll l = 1LL * i * (i - 1) / 2;
		ll r = 1LL * (2 * n - i - 1) * i / 2;
		mp[(s % d + d) % d].emplace_back(s + l * d, r - l);
	}		

	ll ans = 0;

	for(auto& p : mp) {
		auto &a = p.second;
		int m = a.size();

		for(int i = 0; i < m; ++i) {
			a[i].first = (a[i].first - p.first) / d;
		}

		vector<pair<ll, int> > v;

		for(int i = 0; i < m; ++i) {
			v.emplace_back(a[i].first, 1);
			v.emplace_back(a[i].first + a[i].second + 1, -1);
		}

		sort(v.begin(), v.end());

		ll cnt = 0;
		ll pre = -inf;

		for(auto& x : v) {
			ll len = x.first - pre;
			if(cnt > 0) {
				ans += len;
			}
			cnt += x.second;
			pre = x.first;
		}
	}

	cout << ans << '\n';
	return 0;
}
