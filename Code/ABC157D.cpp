#include <bits/stdc++.h>
using namespace std;
vector<int> fa;
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > f;
	vector<vector<int> > g;
	fa.resize(n);
	f.resize(n);
	g.resize(n);
	for(int i = 0; i < n; ++i) {
		fa[i] = i;
	}
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		if(Find(a) != Find(b)) {
			fa[Find(a)] = Find(b);
		}
	}
	for(int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		f[a].emplace_back(b);
		f[b].emplace_back(a);
	}
	vector<int> sz;
	sz.resize(n);
	for(int i = 0; i < n; ++i) {
		++sz[Find(i)];
	}
	for(int i = 0; i < n; ++i) {
		int ans = sz[Find(i)] - 1;
		for(auto x : f[i]) {
			if(Find(x) == Find(i)) {
				--ans;
			}
		}
		ans -= g[i].size();
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}
