#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<int> in;
	vector<vector<int> > G;
	in.resize(n);
	G.resize(n);

	set<pair<int, int> > s;

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
	
		if(a > b) {
			swap(a, b);
		}

		++in[a];
	
		G[a].emplace_back(b);
		G[b].emplace_back(a);

		s.emplace(a, b);
	}

	vector<int> dep;
	vector<vector<int> > fa;
	dep.resize(n);
	fa.resize(n);
	for(int i = 0; i < n; ++i) {
		fa[i].assign(21, -1);
	}

	vector<bool> vis;
	vis.resize(n);
	vector<vector<int> > g;
	g.resize(n);

	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		for(auto v : G[u]) {
			if(!vis[v]) {
				g[u].emplace_back(v);
				s.erase(minmax(u, v));
				dep[v] = dep[u] + 1;
				fa[v][0] = u;
				dfs(v);
			}
		}
	};

	dfs(0);

	for(int j = 1; j < 21; ++j) {
		for(int i = 0; i < n; ++i) {
			if(fa[i][j - 1] != -1) {
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
			}
		}
	}

	auto lca = [&] (int u, int v) {
		if(dep[u] < dep[v]) {
			swap(u, v);
		}

		int d = dep[u] - dep[v];

		for(int i = 20; i >= 0; --i) {
			if(d >> i & 1) {
				u = fa[u][i];
			}
		}

		if(u == v) {
			return u;
		}

		for(int i = 20; i >= 0; --i) {
			if(fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}

		return fa[u][0];
	};

	vector<int> st;

	for(int i = 0; i < n; ++i) {
		if(in[i] & 1) {
			st.emplace_back(i);
		}
	}

	if(st.size() & 1) {
		cout << -1 << '\n';
		return 0;
	}

	vector<int> sum;
	sum.resize(n);

	while(!st.empty()) {
		int u = st.back();
		st.pop_back();
		
		int v = st.back();
		st.pop_back();

		int w = lca(u, v);
		
		sum[w] -= 2;
		sum[u] += 1;
		sum[v] += 1;
	}

	function<void(int, int)> Dfs = [&] (int u, int f) {
		for(auto v : g[u]) {
			if(v != f) {
				Dfs(v, u);
				sum[u] += sum[v];
				
				int a = u;
				int b = v;
				if(a > b) {
					swap(a, b);
				}

				if(sum[v] & 1) {
					s.emplace(b, a);
				} else {
					s.emplace(a, b);
				}
			}
		}
	};

	Dfs(0, -1);

	for(auto& p : s) {
		cout << p.first + 1 << ' ' << p.second + 1 << '\n'; 
	}

	return 0;
}
