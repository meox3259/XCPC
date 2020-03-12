#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n, root, dfs_clock;
int a[maxn], c[maxn], sz[maxn], ans[maxn], dp[maxn][maxn];
vector<int> G[maxn], g[maxn];
void dfs(int u) {
	for(auto v: G[u]) {
		dfs(v);
		for(int j = 1; j <= sz[v]; ++j) {
			dp[u][sz[u] + j] = dp[v][j];
		}
		sz[u] += sz[v];
	}
	if(c[u] > sz[u]) {
		puts("NO");
		exit(0);
	}
	for(int i = sz[u]; i > c[u]; --i) {
		dp[u][i + 1] = dp[u][i];
	}
	dp[u][c[u] + 1] = u;
	++sz[u];
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int f; scanf("%d%d", &f, &c[i]);
		if(f) {
			G[f].push_back(i);
		} else {
			root = i;
		}
	}
	dfs(root);
	puts("YES");
	for(int i = 1; i <= n; ++i) {
		ans[dp[root][i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}
