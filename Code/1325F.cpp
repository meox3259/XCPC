#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > G;
	G.resize(n);

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> dep;
	dep.assign(n, -1);

	vector<bool> vis;
	vis.assign(n, false);

	vector<bool> mark;
	mark.assign(n, false);

	int lim = 0;
	while(lim * lim < n) {
		++lim;
	}

	vector<int> st;

	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;

		st.emplace_back(u);

		for(auto v : G[u]) {
			if(vis[v] && dep[u] - dep[v] + 1 >= lim) {
				cout << 2 << '\n';

				cout << dep[u] - dep[v] + 1 << '\n';

				while(st.back() != v) {
					cout << st.back() + 1 << ' ';
					st.pop_back();
				}

				cout << st.back() + 1;

				cout << '\n';

				exit(0);
			} 

			if(!vis[v]) {
				dep[v] = dep[u] + 1;

				dfs(v);
			}
		}

		st.pop_back();

		if(!mark[u]) {
			for(auto v : G[u]) {
				mark[v] = true;
			}
		}
	};

	dfs(0);

	cout << 1 << '\n';

	vector<int> ans;
	for(int i = 0; i < n; ++i) {
		if(!mark[i]) {
			ans.emplace_back(i);
		}
	}

	for(int i = 0; i < lim; ++i) {
		cout << ans[i] + 1 << ' ';
	}

	cout << '\n';
	return 0;
}
