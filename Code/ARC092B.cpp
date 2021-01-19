#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	long long ans = 0;
	for (int i = 0; i < 29; ++i) {
		vector<long long> d(b);
		for (int j = 0; j < n; ++j) {
			d[j] &= (1LL << i + 1) - 1;
		}

		sort(d.begin(), d.end());

		vector<long long> c(a);
		for (int j = 0; j < n; ++j) {
			c[j] &= (1LL << i + 1) - 1;
		}

		sort(c.begin(), c.end());

		long long tot = 0;
		for (int v : c) {
			if (v >> i & 1) {
				int x = lower_bound(d.begin(), d.end(), (1LL << i + 1) - v) - d.begin();
				int y = d.end() - lower_bound(d.begin(), d.end(), (1LL << i) + (1LL << i + 1) - v);
				tot += x + y;
			} else {
				int x = lower_bound(d.begin(), d.end(), (1LL << i) - v) - d.begin();
				int y = lower_bound(d.begin(), d.end(), (1LL << i + 1) - v) - d.begin();
				tot += y - x;
			}	
		}

		if (tot & 1) {
			ans ^= 1 << i;
		}
	}

	cout << ans << '\n';

	return 0;
}
