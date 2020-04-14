#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> a;
		a.resize(n);

		for(int &i : a) {
			cin >> i;
		}

		int mx = a[0];
		int ans = 0;

		for(int i = 1; i < n; ++i) {
			if(a[i] < mx) {
				int d = mx - a[i];

				for(int j = 30; j >= 0; --j) {
					if(d >> j & 1) {
						ans = max(ans, j + 1);
						break;
					}
				}
			}

			mx = max(mx, a[i]);
		}

		cout << ans << '\n';
	}

	return 0;
}
