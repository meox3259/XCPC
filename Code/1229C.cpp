#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int n, m;
ll ans;
int d[maxn];
vector<int> G[maxn];
ll c(int x) {
	return 1LL * G[x].size() * (d[x] - G[x].size());
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if(u > v) {
			swap(u, v);
		}
		++d[u];
		++d[v];
		G[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i) {
		ans += c(i);
	}
	cout << ans << '\n';
	int q;
	cin >> q;
	while(q--) {
		int u;
		cin >> u;
		for(auto v : G[u]) {
			ans -= c(v);
			G[v].emplace_back(u);
			ans += c(v);
		}
		ans -= c(u);
		G[u].clear();
		cout << ans << '\n';
	}
	return 0;
}
