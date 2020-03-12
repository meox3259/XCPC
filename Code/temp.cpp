#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, P = 1e9 + 7;
long long dp[maxn][maxn][2];
int main() {
	/*
	 (1, 2) = 1
	 (2, 2) = 6
	 (3, 2) = 6 + 7 + 

	 1 1 1
	 1 1 1
	*/
	int n, k;
	scanf("%d%d", &n, &k);
	dp[1][1][0] = 1;
	dp[1][2][1] = 1;
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= min(2 * i, k); ++j) {
			dp[i][j][0] = (dp[i - 1][j - 1][0] + dp[i - 1][j][0] + dp[i - 1][j + 1][1] + dp[i - 1][j - 1][1] + 2 * dp[i - 1][j][1]) % P;
			if(j > 1) {
				dp[i][j][1] = (dp[i - 1][j - 2][0] + dp[i - 1][j - 1][0] + dp[i - 1][j - 2][1] + dp[i - 1][j][1] + 2 * dp[i - 1][j - 1][1]) % P;
			}
		}
	}
	printf("%lld\n", (dp[n][k][0] + dp[n][k][1]) % P)
	return 0;
}
