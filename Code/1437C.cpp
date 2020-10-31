#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while(q--) {
		int n;
		cin >> n;

		vector<int> t(n);
		for(int i = 0; i < n; ++i) {
			cin >> t[i];
		}

		sort(t.begin(), t.end());

		vector<vector<int> > dp(n + 1, vector<int> (n + n + 1, inf));
		dp[0][0] = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j <= n + n; ++j) {
				for(int k = j + 1; k <= n + n; ++k) {
					dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + abs(k - t[i]));
				}
			}
		}

		cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
	}

	return 0;
}
