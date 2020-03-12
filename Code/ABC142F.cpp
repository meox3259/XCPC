#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int> > G;
	vector<vector<int> > rev;
	G.resize(n);
	rev.resize(n);

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].emplace_back(b);
		rev[b].emplace_back(a);
	}

	vector<int> vis;
	
	set<int> st;

	function<void(int, int, int)> dfs = [&] (int u, int s, int f) {
		vis[u] = 1;
		st.emplace(u);
		for(auto v : G[u]) {
			if(v != s && st.count(v)) {
				st.erase(u);
				return;
			}
		}
		for(auto v : rev[u]) {
			if(v != f && st.count(v)) {
				st.erase(u);
				return;
			}
		}
		for(auto v : G[u]) {
			if(v == s) {
				cout << st.size() << '\n';
				for(auto x : st) {
					cout << x + 1 << '\n';
				}
				exit(0);
			}
		}
		for(auto v : G[u]) {
			if(vis[v] == 0) {
				dfs(v, s, u);
			}
		}
		st.erase(u);
	};

	for(int i = 0; i < n; ++i) {
		st.clear();
		vis.assign(n, 0);
		dfs(i, i, -1);
	}
	
	cout << -1 << '\n';

	return 0;
}
