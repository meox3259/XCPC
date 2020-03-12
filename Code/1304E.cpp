#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> G[maxn];
int fa[maxn][22], dep[maxn];
void dfs(int u, int f) {
	for(auto v : G[u]) {
		if(v != f) {
			dep[v] = dep[u] + 1;
			fa[v][0] = u; 
			dfs(v, u);
		}
	}
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) {
		swap(u, v);
	}
	int d = dep[u] - dep[v];
	for(int i = 21; ~i; --i) {
		if(d >> i & 1) {
			u = fa[u][i];
		}
	}
	if(u == v) {
		return u;
	}
	for(int i = 21; ~i; --i) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
int dis(int x, int y) {
	int t = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[t];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int j = 1; j < 22; ++j) {
		for(int i = 1; i <= n; ++i) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		int c = dis(a, b);
		int t1 = dis(a, x) + dis(b, y) + 1;
		int t2 = dis(a, y) + dis(b, x) + 1;
		if(k < c && k < t1 && k < t2) {
			puts("NO");
		} else {
			if((k >= c && (k & 1) == (c & 1)) || (k >= t1 && (k & 1) == (t1 & 1)) || (k >= t2 && (k & 1) == (t2 & 1))) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}
