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

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());

		vector<int> cnt(200001);
		for (int i : a) {
			cnt[i] ++;
		}

		a.erase(unique(a.begin(), a.end()), a.end());
		int m = a.size();
		vector<int> pos(200001, -1);
		for (int i = 0; i < m; ++i) {
			pos[a[i]] = i;
		}

		vector<int> dp(m);
		for (int i = 0; i < m; ++i) {
			dp[i] = max(dp[i], cnt[a[i]]);
			for (int j = a[i] + a[i]; j < 200001; j += a[i]) {
				if (pos[j] != -1) {
					dp[pos[j]] = max(dp[pos[j]], dp[i] + cnt[j]);
				}
			}
		}

		cout << n - *max_element(dp.begin(), dp.end()) << '\n';
	}

	return 0;
}
