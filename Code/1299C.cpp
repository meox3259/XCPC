#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<ll, ll> > s;
	for(int i = 0; i < n; ++i) {
		ll x = 1, y = a[i];
		while(!s.empty()) {
			auto [tx, ty] = s.back();
			if(ty * x >= y * tx) {
				s.pop_back();
				x += tx;
				y += ty;
			} else {
				break;
			}
		}
		s.emplace_back(x, y);
	}
	cout << fixed << setprecision(10);
	for(int i = 0; i < s.size(); ++i) {
		double ans = 1.0 * s[i].second / s[i].first;
		if(i) {
			s[i].first += s[i - 1].first;
		}
		for(int j = i ? s[i - 1].first : 0; j < s[i].first; ++j) {
			cout << ans << '\n';		
		}
	}
	return 0;
}
