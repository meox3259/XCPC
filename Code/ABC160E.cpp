#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;

	vector<int> p;
	p.resize(a);

	vector<int> q;
	q.resize(b);

	vector<int> r;
	r.resize(c);

	for(int i = 0; i < a; ++i) {
		cin >> p[i];
	}

	for(int i = 0; i < b; ++i) {
		cin >> q[i];
	}

	for(int i = 0; i < c; ++i) {
		cin >> r[i];
	}

	sort(p.begin(), p.end(), greater<int> ());
	sort(q.begin(), q.end(), greater<int> ());
	sort(r.begin(), r.end(), greater<int> ());

	long long ans = 0;

	vector<int> t;
	
	for(int i = 0; i < x; ++i) {
		t.emplace_back(p[i]);
	}

	for(int i = 0; i < y; ++i) {
		t.emplace_back(q[i]);
	}

	for(int i = 0; i < c; ++i) {
		t.emplace_back(r[i]);
	}

	sort(t.begin(), t.end(), greater<int> ());

	for(int i = 0; i < x + y; ++i) {
		ans += t[i];
	}

	cout << ans << '\n';

	return 0;
}
