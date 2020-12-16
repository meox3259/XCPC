#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> pre(n + 1);
		for (int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + a[i];
		}
		unordered_map<int, int> mp;
		for (int i = 0; i <= n; ++i) {
			mp[pre[i]] = i;
		}
		int ans = n - 1;
		for (int i = 1; i <= n; ++i) {
			int p = i;
			int cnt = 0;
			while (p < n) {
				if (mp.find(pre[i] + pre[p]) == mp.end()) {
					break;
				}
				p = mp[pre[i] + pre[p]];
				cnt ++;
			}
			if (p == n) {
				ans = min(ans, n - 1 - cnt);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
