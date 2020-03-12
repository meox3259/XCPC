#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int inf = 1e6;
int fa[maxn], dep[maxn];
vector<int> G[maxn];
void dfs(int u, int f) {
	for(auto v : G[u]) {
		if(v != f) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, int> > e;
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		e.emplace_back(minmax(x, y));
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	dfs(1, 0);
	int m;
	cin >> m;
	vector<tuple<int, int, int> > path;
	vector<int> val(n + 1, 0);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		path.emplace_back(u, v, w);
	}
	for(int i = 0; i < m; ++i) {
		auto [x, y, w] = path[i];
		while(x != y) {
			if(dep[x] < dep[y]) {
				swap(x, y);
			}
			val[x] = max(val[x], w);
			x = fa[x];
		}
	}
	for(auto [x, y, w] : path) {
		int mn = inf;
		while(x != y) {
			if(dep[x] < dep[y]) {
				swap(x, y);
			}
			mn = min(mn, val[x]);
			x = fa[x];
		}
		if(mn != w) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for(int i = 0; i < e.size(); ++i) {
		auto [u, v] = e[i];
		if(fa[v] == u) {
			swap(u, v);
		}
		if(!val[u]) {
			cout << inf << ' ';
		} else {
			cout << val[u] << ' ';
		}
	}
	cout << '\n';
	return 0;
}
