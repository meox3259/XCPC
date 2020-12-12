#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] --;
		}

		int pos = -1;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] != i) {
				pos = i;
				break;
			}
		}

		double ans = 1.;
		for (int i = 0; i < m; ++i) {
			int r;
			double p;
			cin >> r >> p;
			r --;
			if (r >= pos) {
				ans = ans * (1. - p);
			}
		}

		cout << fixed << setprecision(10);
		if (pos == -1) {
			cout << 1.00000000000 << '\n';
		} else {
			cout << 1. - ans << '\n';
		}
	}

	return 0;
}
