#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, G, B;
	cin >> R >> G >> B;

	vector<int> r(R);
	for(int i = 0; i < R; ++i) {
		cin >> r[i];
	}

	vector<int> g(G);
	for(int i = 0; i < G; ++i) {
		cin >> g[i];
	}

	vector<int> b(B);
	for(int i = 0; i < B; ++i) {
		cin >> b[i];
	}

	sort(r.begin(), r.end(), greater<int> ());
	sort(g.begin(), g.end(), greater<int> ());
	sort(b.begin(), b.end(), greater<int> ());

	vector<vector<vector<long long> > > dp(R + 1, vector<vector<long long> > (G + 1, vector<long long> (B + 1)));
	for(int i = 0; i <= R; ++i) {
		for(int j = 0; j <= G; ++j) {
			for(int k = 0; k <= B; ++k) {
				if(i < R && j < G) {
					dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
				}
				if(i < R && k < B) {
					dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
				}
				if(j < G && k < B) {
					dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
				}
			}
		}
	}

	long long ans = 0;
	for(int i = 0; i <= R; ++i) {
		for(int j = 0; j <= G; ++j) {
			for(int k = 0; k <= B; ++k) {
				ans = max(ans, dp[i][j][k]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
