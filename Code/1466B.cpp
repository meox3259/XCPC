#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<int> x(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}

		int ans = 0;
		unordered_map<int, int> mp;
		for (int i = n - 1; i >= 0; --i) {
			if (mp.find(x[i] + 1) == mp.end()) {
				mp[x[i] + 1] ++;
				ans ++;
			} else {
				if (mp.find(x[i]) == mp.end()) {
					ans ++;
				}
				mp[x[i]] ++;

			}
		}

		cout << ans << '\n';
	}

	return 0;
}
