#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n;
int a[maxn], dp[maxn][maxn][2];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, 0x3f3f, sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(!a[i] || (a[i] & 1)) {
				dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
			}
			if(j && !(a[i] & 1)) {
				dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
			}
		}
	}
	printf("%d\n", min(dp[n][n >> 1][0], dp[n][n >> 1][1]));
	return 0;
}
