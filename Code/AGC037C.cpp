#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	int cnt = 0;

	set<pair<int, int> > s = { { 0, -1 } };
	for(int i = 0; i < n; ++i) {
		s.emplace(b[i], i);
	}

	long long ans = 0;

	while(s.size() > 1) {
		auto o = *s.rbegin();
		s.erase(o);
		int p = o.second;
		int nxt = s.rbegin() -> first;
		int m = b[(p - 1 + n) % n] + b[(p + 1) % n];
		int delta = (o.first - a[p]) / m;
		if(o.first == a[p]) {
			continue;
		}
		if(delta == 0 || o.first < a[p]) {
			cout << -1 << '\n';
			exit(0);
		}
		ans += delta;
		o.first -= m * delta;
		b[p] = o.first;
		s.insert(o);
	}

	cout << ans << '\n';

	return 0;
}
