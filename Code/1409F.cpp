#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	
	string s, t;
	cin >> s >> t;

	if(t[0] == t[1]) {
		int cnt = 0;
		for(char c : s) {
			if(c == t[0]) {
				cnt += 1;
			}	
		}
		int p = cnt + min(n - cnt, k);
		cout << p * (p - 1) / 2 << '\n';
		exit(0);
	}

	vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (n + 1, vector<int> (k + 1, -inf)));
	dp[0][0][0] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			for(int x = 0; x <= k && x <= i; ++x) {
				dp[i + 1][j][x] = max(dp[i + 1][j][x], dp[i][j][x]);
				int f = (s[i] != t[0]);
				if(x + f <= k) {
					dp[i + 1][j + 1][x + f] = max(dp[i + 1][j + 1][x + f], dp[i][j][x]);
				}
				int g = (s[i] != t[1]);
				if(x + g <= k) {
					dp[i + 1][j][x + g] = max(dp[i + 1][j][x + g], dp[i][j][x] + j);
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			for(int x = 0; x <= k; ++x) {
				ans = max(ans, dp[i][j][x]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
