#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		vector<int> h(n);
		for (int i = 0; i < n; ++i) {
			cin >> h[i];
		}

		bool ok = true;
		int l = h[0];
		int r = h[0];
		for (int i = 1; i < n; ++i) {
			l = max(h[i], l - k + 1);
			r = min(h[i] + k - 1, r + k - 1);
			if (l > r) {
				ok = false;
			}
		}

		if (ok && h.back() == l) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
