#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3005;
int n, root;
ll ans, t;
int vis[maxn][maxn], pre[maxn][maxn];
ll sz[maxn][maxn], dp[maxn][maxn];
vector<int> G[maxn];
void pre_dfs(int u, int f) {
	sz[root][u] = 1;
	for(auto v : G[u]) {
		if(v != f) {
			pre_dfs(v, u);
			sz[root][u] += sz[root][v];
			pre[v][root] = u;
		}
	}
}
ll dfs(int x, int y) {
	if(vis[x][y]) {
		return dp[x][y];
	}
	if(x == y) {
		return 0;
	}
	vis[x][y] = 1;
	return dp[x][y] = sz[y][x] * sz[x][y] + max(dfs(pre[x][y], y), dfs(x, pre[y][x]));
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; 
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) {
		root = i;
		pre_dfs(i, 0);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++ j) {
			ans = max(ans, dfs(i, j));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
