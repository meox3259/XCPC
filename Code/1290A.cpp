#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m, k;
		cin >> n >> m >> k;
		k = min(k, m - 1);
		vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0; i <= k; ++i) {
			int l = i + 1, r = n - (k - i), d = m - k;
			int t = 1e9 + 5;
			for(int j = 0; j < d; ++j) {
				t = min(t, max(a[l + j], a[r - (d - j - 1)]));
			}
			ans = max(ans, t);
		}
		cout << ans << '\n';
	}
	return 0;
}
