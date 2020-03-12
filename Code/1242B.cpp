#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
set<int> G[maxn], s;
void dfs(int u) {
	vector<int> tmp;
	for(auto x : s) {
		if(!G[u].count(x)) {
			tmp.emplace_back(x);
		}
	}
	for(auto x : tmp) {
		s.erase(x);
	}
	for(auto x : tmp) {
		dfs(x);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v; 
		cin >> u >> v;
		--u; 
		--v;
		G[u].insert(v);
		G[v].insert(u);
	}
	for(int i = 0; i < n; ++i) {
		s.insert(i);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s.count(i)) {
			++ans;
			dfs(i);
		}
	}
	cout << ans - 1 << "\n";
	return 0;
}
