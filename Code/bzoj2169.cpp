#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, P = 10007;
int n, m, k;
int d[maxn], dp[maxn][maxn], c[maxn][maxn];
int C(int x) {
	return 1LL * x * (x - 1) / 2LL % P;
}
int power(int x, int t) {
	int ret = 1;
	for(; t; t >>= 1, x = 1LL * x * x % P) {
		if(t & 1) {
			ret = 1LL * ret * x % P;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		d[u] ^= 1;
		d[v] ^= 1;
	}
	int c = 0;
	for(int i = 1; i <= n; ++i) {
		if(d[i]) {
			++c;
		}
	}
	dp[0][c] = 1;
	for(int i = 1; i <= k; ++i) {
		int inv = power(i, P - 2);
		for(int j = 0; j <= n; ++j) {
			if(j > 1) {
				dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 2] * C(n - j + 2) % P) % P;
			}
			if(j + 2 <= n) {
				dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j + 2] * C(j + 2) % P) % P;
			}
			dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j] * j % P * (n - j) % P) % P;
			if(i > 1) {
				dp[i][j] = (dp[i][j] - 1LL * dp[i - 2][j] * (C(n) - (i - 2)) % P + P) % P; 
			}
			dp[i][j] = 1LL * dp[i][j] * inv % P;
		}
	}
	printf("%d\n", dp[k][0]);
	return 0;
}
