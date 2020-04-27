#include <bits/stdc++.h>

using namespace std;

const string mp[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

int dis[130][130] = { -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> S;
	S.resize(10);

	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 7; ++j) {
			S[i] |= (mp[i][j] - '0') << j;
		}
	}

	int n, m;
	cin >> n >> m;

	vector<int> c;
	c.resize(n);

	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		for(int j = 0; j < 7; ++j) {
			c[i] |= (s[j] - '0') << j;
		}
	}

	reverse(c.begin(), c.end());

	vector<vector<int> > dp;
	dp.resize(n + 1);

	for(int i = 0; i <= n; ++i) {
		dp[i].resize(m + 1);
	}

	dp[0][0] = 1;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= m; ++j) {
			if(dp[i][j]) {
				for(int x = 0; x < 10; ++x) {
					if((c[i] & S[x]) == c[i]) {
						int d = __builtin_popcount(S[x]) - __builtin_popcount(c[i]);
						if(j + d <= m) {
							dp[i + 1][j + d] |= dp[i][j];
						}
					}
				}
			}
		}
	}

	if(dp[n][m] == 0) {
		cout << -1 << '\n';
		return 0;
	}

	for(int i = n - 1; i >= 0; --i) {
		for(int j = 9; j >= 0; --j) {
			if((c[i] & S[j]) == c[i]) {
				int d = __builtin_popcount(S[j]) - __builtin_popcount(c[i]);
				if(m - d >= 0 && dp[i][m - d]) {
					cout << j;
					m -= d;
					break;
				}
			}
		}
	}

	cout << '\n';

	return 0;
}
