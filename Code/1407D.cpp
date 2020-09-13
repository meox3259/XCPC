#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> big{0};
	vector<int> sml{0};
	vector<int> dp(n, inf);
	dp[0] = 0;
	for(int i = 1; i < n; ++i) {
		dp[i] = min(dp[i], dp[i - 1] + 1);
		while(!big.empty() && a[i] >= a[big.back()]) {
			int x = big.back();
			big.pop_back();
			if(!big.empty() && a[i] > a[x]) {
				dp[i] = min(dp[i], dp[big.back()] + 1);
			}
		}
		while(!sml.empty() && a[i] <= a[sml.back()]) {
			int x = sml.back();
			sml.pop_back();
			if(!sml.empty() && a[i] < a[x]) {
				dp[i] = min(dp[i], dp[sml.back()] + 1);
			}
		}
		big.emplace_back(i);
		sml.emplace_back(i);
	}

	cout << dp[n - 1] << '\n';

	return 0;
}
