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

		vector<long long> dp(n + 1);
		for (int i = 0; i < n; ++i) {
			dp[min(i + a[i], n)] = max(dp[min(i + a[i], n)], dp[i] + a[i]);
		}

		cout << dp[n] << '\n';
	}

	return 0;
}
