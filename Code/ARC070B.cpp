#include <bits/stdc++.h>

using namespace std;

const int P = 1919810;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> dp(k + 1);
	dp[0] = 1;
	for (int v : a) {
		for (int i = k; i >= v; --i) {
			dp[i] = (dp[i] + dp[i - v]) % P;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> g(k + 1);
		g[0] = 1;
		for (int j = 0; j <= k; ++j) {
			if (j < a[i]) {
				g[j] = dp[j];
			} else {
				g[j] = (dp[j] - g[j - a[i]] + P) % P; 
			}
		}

		bool ok = true;
		for (int j = max(0, k - a[i]); j < k; ++j) {
			if (g[j] != 0) {
				ok = false;
			}
		}

		if (ok) {
			ans ++;
		}
	}

	cout << ans << '\n';

	return 0;
}
