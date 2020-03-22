#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, S;
	cin >> n >> S;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<long long> > dp;
	dp.resize(n + 1);

	for(int i = 0; i < n + 1; ++i) {
		dp[i].resize(S + 1);
	}

	dp[0][0] = 1;

	for(int i = 0; i < n; ++i) {
		if(a[i] <= S) {
			dp[i + 1][a[i]] += i + 1;
		}

		for(int j = 1; j <= S; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % P;
			if(j + a[i] <= S) {
				dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + dp[i][j]) % P;
			}
		}
	}

	long long ans = 0;

	for(int i = 0; i < n + 1; ++i) {
		ans = (ans + dp[i][S]) % P;
	}

	cout << ans << '\n';

	return 0;
}
