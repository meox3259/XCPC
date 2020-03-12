#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> x;
	vector<ll> y;
	x.resize(n);
	y.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	if(n & 1) {
		cout << "NO" << '\n';
		return 0;
	}
	ll sumx = 0, sumy = 0;
	for(int i = 0; i < n; ++i) {
		sumx += x[i];
		sumy += y[i];
	}
	sumx *= 2LL;
	sumy *= 2LL;
	map<pair<ll, ll>, ll> mp;
	for(int i = 0; i < n; ++i) {
		mp[{x[i] * n, y[i] * n}] = 1;
	}
	for(int i = 0; i < n; ++i) {
		if(!mp.count({sumx - x[i] * n, sumy - y[i] * n})) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}
