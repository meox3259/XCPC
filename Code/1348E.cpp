#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000;

inline void chkmax(long long &x, long long y) {
	if(y > x) {
		x = y;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	vector<vector<long long> > dp(n + 1, vector<long long> (m, -inf));
	
	dp[0][0] = 0;

	long long sum = 0;
	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		int up = min(m - 1, a[i]);
		for(int j = 0; j < m; ++j) {
			long long v = dp[i][j];
			if(v >= 0) {
				long long ra = a[i] + j;
				long long ma = ra / m;
				long long da = ra % m;
				long long rb = b[i] + sum - v * m - j;
				for(int k = max(1, m - b[i]); k <= up; ++k) {
					int nxt = (a[i] - k + j) % m;
					chkmax(dp[i + 1][nxt], v + ma - (k > da) + (rb - m + k) / m + 1);
					++cnt;
				}
				int nxt = (j + a[i]) % m;
				chkmax(dp[i + 1][nxt], v + ra / m + rb / m);
			}
		}
		sum += a[i] + b[i];
	}

	cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';

	return 0;
}
