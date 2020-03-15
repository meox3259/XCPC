#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll u, v;
	cin >> u >> v;

	if(u == 0 && v == 0) {
		cout << 0 << '\n';
		return 0;
	}

	if(u > v || (u % 2 != v % 2)) {
		cout << -1 << '\n';
		return 0;
	}

	if(u == v) {
		cout << 1 << '\n';
		cout << u << '\n';
		return 0;
	}

	ll t = v - u >> 1;

	if(t & u) {
		cout << 3 << '\n';
		cout << u << ' ' << t << ' ' << t << '\n'; 
	} else {
		cout << 2 << '\n';
		cout << t << ' ' << (u ^ t) << '\n';
	}

	return 0;
}
