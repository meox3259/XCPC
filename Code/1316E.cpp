#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p, k;
	cin >> n >> p >> k;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<int> > s;
	s.resize(n);
	for(int i = 0; i < n; ++i) {
		s[i].resize(p);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < p; ++j) {
			cin >> s[i][j];
		}
	}
	vector<int> id;
	id.resize(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&] (int i, int j) {
		return a[i] > a[j];				
	});
	vector<vector<long long> > dp;
	dp.resize(n + 1);
	for(int i = 0; i <= n; ++i) {
		dp[i].resize(1 << p, -inf);
	}
	dp[0][0] = 0;

	for(int _ = 0; _ < n; ++_) {
		int i = id[_];

		dp[_ + 1] = dp[_];

		for(int S = 0; S < 1 << p; ++S) {
			if(_ + 1 - __builtin_popcount(S) <= k) {
				dp[_ + 1][S] = max(dp[_ + 1][S], dp[_][S] + a[i]);
			}
		}
		for(int S = 0; S < 1 << p; ++S) {
			for(int j = 0; j < p; ++j) {
				if(!(S >> j & 1)) {
					dp[_ + 1][S ^ (1 << j)] = max(dp[_ + 1][S ^ (1 << j)], dp[_][S] + s[i][j]);
				}
			}
		}
	}

	cout << dp[n][(1 << p) - 1] << '\n';
	return 0;
}
