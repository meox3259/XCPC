#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> d;
	d.resize(n);

	vector<pair<int, int> > e;

	vector<vector<int> > G;
	G.resize(n);

	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		e.emplace_back(a, b);

		G[a].emplace_back(b);
		G[b].emplace_back(a);

		++d[a];
		++d[b];

	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		ans = max(ans, d[i]);
	}

	cout << ans << '\n';

	vector<int> p;
	p.resize(n);

	map<pair<int, int>, int> c;

	function<void(int, int)> dfs = [&] (int u, int f) {
		for(auto v : G[u]) {
			if(v != f) {
				if(c.count(minmax(u, f)) && p[u] == c[minmax(u, f)]) {
					++p[u];
				}
				
				c[minmax(u, v)] = p[u]++;

				dfs(v, u);
			}
		}
	};

	dfs(0, -1);

	for(auto& p : e) {
		cout << c[minmax(p.first, p.second)] + 1 << '\n';
	}

	return 0;
}
