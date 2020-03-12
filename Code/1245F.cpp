#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[32][2][2];
ll dfs(int l, int r, int bit, int a, int b) {
	if(bit == -1) {
		return 1;
	}
	if(dp[bit][a][b] != -1) {
		return dp[bit][a][b];
	}
	auto &ret = dp[bit][a][b] = 0;
	int ua = a ? (l >> bit & 1) : 1;
	int ub = b ? (r >> bit & 1) : 1;
	for(int i = 0; i <= ua; ++i) {
		for(int j = 0; j <= ub; ++j) {
			if(!(i & j)) {
				ret += dfs(l, r, bit - 1, a && (i == ua), b && (j == ub));
			}
		}
	}
	return ret;
}
ll calc(int l, int r) {
	if(l < 0 || r < 0) {
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	return dfs(l, r, 30, 1, 1);
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", calc(r, r) - 2 * calc(l - 1, r) + calc(l - 1, l - 1));
	}
	return 0;
}
