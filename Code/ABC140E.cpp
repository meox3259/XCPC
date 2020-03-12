#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> a;
	vector<int> pos;
	a.resize(n);
	pos.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		pos[a[i] - 1] = i;
	}

	multiset<int> s = {-1, -1, n, n};

	long long ans = 0;

	for(int i = n - 1; i >= 0; --i) {
		auto it = s.lower_bound(pos[i]);

		int x = *it;
		int y = *next(it);
		int w = *prev(it);
		int v = *prev(prev(it));

		ans += 1LL * (i + 1) * ((y - x) * (pos[i] - w) + (w - v) * (x - pos[i]));

		s.emplace(pos[i]);
	}

	cout << ans << '\n';

	return 0;
}
