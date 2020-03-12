#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int d[] = {0, 1, -1};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	for(int kase = 0; kase < q; ++kase) {
		int n;
		cin >> n;
		vector<int> a;
		vector<int> b;
		a.resize(n);
		b.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		vector<vector<long long> > dp;
		dp.resize(n + 1);
		for(int i = 0; i < n + 1; ++i) {
			dp[i].resize(3, inf);
		}
		// 1 : up 2 : down
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2 * b[0];
		for(int i = 0; i < n - 1; ++i) {
			for(int j = 0; j < 3; ++j) {
				for(int k = 0; k < 3; ++k) {
					if(a[i] + j != a[i + 1] + k) {
						dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + b[i + 1] * k);
					}
				}
			}
		}
		cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
	}
	return 0;
}
