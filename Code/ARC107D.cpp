#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

template <typename T> 
void add(T &x, T y) {
	x = (x + y) % P;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<long long> > dp(n + 1, vector<long long> (n + 1));
	dp[0][0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			add(dp[i + 1][j + 1], dp[i][j]);
		}
		for (int j = n; j >= 1; --j) {
			if (j + j <= n) {
				add(dp[i + 1][j], dp[i + 1][j + j]);
			}
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}
