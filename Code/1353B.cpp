#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		vector<int> b(n);

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for(int i = 0; i < n; ++i) {
			for(int j = n - 1; j >= 0; --j) {
				if(a[i] < b[j]) {
					if(k > 0) {
						--k;
						swap(a[i], b[j]);
						break;
					}
				}
			}
		}

		int ans = 0;

		for(int i : a) {
			ans = ans + i;
		}

		cout << ans << '\n';
	}

	return 0;
}
