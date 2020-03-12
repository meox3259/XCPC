#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
int n, m;
int dp[maxn];
int main() {
	scanf("%d%d", &m, &n);
	memset(dp, 0x3f3f, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		for(int j = a; j < maxn; ++j) {
			dp[j] = min(dp[j], dp[j - a] + b);
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = m; i < maxn; ++i) {
		ans = min(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
