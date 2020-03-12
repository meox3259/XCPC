#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int dp[maxn], x[maxn], s[maxn];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &s[i]);
	}
	memset(dp, 0x3f3, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= m; ++i) {
		dp[i] = min(i, dp[i - 1] + 1);
		for(int j = 1; j <= n; ++j) {
			if(x[j] <= i) {
				int d = max(i - x[j], s[j]);
				dp[i] = min(dp[i], dp[max(0, x[j] - d - 1)] + d - s[j]);
			} else {
				if(x[j] - s[j] <= i && x[j] + s[j] >= i) {
					dp[i] = min(dp[i], dp[i - 1]);
				}
			}
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}
