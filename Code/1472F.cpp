#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, m;
		cin >> n >> m;

		vector<pair<int, int> > q(m);
		for (int i = 0; i < m; ++i) {
			cin >> q[i].second >> q[i].first;
		}

		sort(q.begin(), q.end());

		vector<vector<int> > dp(m + 1, vector<int> (3));
		auto [c, r] = q[0];
		dp[1][r] = 1;
		for (int i = 1; i < m; ++i) {
			auto [c, r] = q[i];			
			auto [pc, pr] = q[i - 1];
			if (c == pc) {
				dp[i + 1][0] |= dp[i][pr];
			} else {
				if (r == pr) {
					if ((c - pc) % 2 == 1) {
						dp[i + 1][r] |= dp[i][0];
						dp[i + 1][0] |= dp[i][r];
					} else {
						dp[i + 1][r] |= dp[i][0];
					}
				} else {
					if ((c - pc) % 2 == 1) {
						dp[i + 1][r] |= dp[i][0];
					} else {
						dp[i + 1][r] |= dp[i][0];
						dp[i + 1][0] |= dp[i][pr];
				
					}	
				}
			}
		}

		if (dp[m][0]) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
