#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> b(a);
		sort(b.begin(), b.end());

		if(a == b) {
			cout << 0 << '\n';
			continue;
		}

		int ans = -1;
		for(int i = 0; i <= n; ++i) {
			bool ok = true;
			for(int j = 0; j + 1 < n; ++j) {
				if(a[j] > a[j + 1]) {
					ok = false;
				}
			}
			if(ok) {
				ans = i;
				break;
			}
			for(int j = 0; j < n; ++j) {
				if(a[j] > x) {
					swap(a[j], x);
					break;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
