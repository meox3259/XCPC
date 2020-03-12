#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, dfs_clock;
vector<int> G[maxn];
int l[maxn], r[maxn];
void dfs(int u, int f) {
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(v != f) {
			l[v] = ++dfs_clock;
		}
	}
	r[u] = ++dfs_clock;
	for(auto v : G[u]) {
		if(v != f) {
			dfs(v, u);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	l[1] = ++dfs_clock;
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) {
		printf("%d %d\n", l[i], r[i]);
	}
	return 0;
}
