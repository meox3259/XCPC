#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, m, k;
int a[maxn], b[maxn], c[maxn], dp[maxn][maxn], last[maxn];
vector<int> v[maxn];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	for(int i = 1; i <= n; ++i) {
		last[i] = i;
	}
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		last[v] = max(last[v], u);
	}
	for(int i = 1; i <= n; ++i) {
		v[last[i]].push_back(c[i]);
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; ++i) {
		if(k < a[i]) {
			puts("-1");
			return 0;
		}
		for(int j = a[i]; j <= k; ++j) {
			dp[i][j + b[i]] = dp[i - 1][j];
		}
		for(int l = 0; l < v[i].size(); ++l) {
			for(int j = 1; j <= k + b[i]; ++j) {
				dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + v[i][l]);
			}
		}
		k += b[i];
	}
	int ans = 0;
	for(int i = k; ~i; --i) {
		ans = max(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
