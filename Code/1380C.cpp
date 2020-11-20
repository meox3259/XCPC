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

		sort(a.begin(), a.end());

		vector<int> dp(n + 1);
		for(int i = 0; i < n; ++i) {
			int l = (x + a[i] - 1) / a[i];	
			dp[i + 1] = max(dp[i + 1], dp[i]);
			if(i + l <= n) {
				dp[i + l] = max(dp[i + l], dp[i] + 1);
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}

	return 0;
}
