#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h, l, r;
	cin >> n >> h >> l >> r;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<int> > dp;
	dp.resize(n + 1);

	for(int i = 0; i < n + 1; ++i) {
		dp[i].assign(h, -inf);
	}

	dp[0][0] = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < h; ++j) {
			int x = (j + a[i]) % h;
			int y = (j + a[i] - 1) % h;

			dp[i + 1][x] = max(dp[i + 1][x], dp[i][j] + (l <= x && x <= r));
			dp[i + 1][y] = max(dp[i + 1][y], dp[i][j] + (l <= y && y <= r));
		}
	}

	cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
	return 0;
}
