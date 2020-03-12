#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[105][5][2];
int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	dp[0][0][1] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 4; ++j) {
			int b = s[i] - '0';
			if(b) {
				dp[i + 1][j][0] += dp[i][j][1];
				dp[i + 1][j][0] += dp[i][j][0];
				dp[i + 1][j + 1][0] += dp[i][j][1] * (b - 1);
				dp[i + 1][j + 1][0] += dp[i][j][0] * 9;
				dp[i + 1][j + 1][1] += dp[i][j][1];
			} else {
				dp[i + 1][j][1] += dp[i][j][1];
				dp[i + 1][j][0] += dp[i][j][0];
				dp[i + 1][j + 1][0] += dp[i][j][0] * 9;
			}
		}
	}
	cout << dp[n][k][0] + dp[n][k][1] << '\n';
	return 0;
}
