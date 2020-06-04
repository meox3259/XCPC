#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}

	vector<vector<int> > G(n);

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	long long ans = 0;

	vector<int> one(n);
	vector<int> two(n);

	function<void(int, int, int)> dfs = [&] (int u, int f, int mn) {
		if(b[u] == 0 && c[u] == 1) {
			one[u] = 1;
		}
		if(b[u] == 1 && c[u] == 0) {
			two[u] = 1;
		}
		for(int v : G[u]) {
			if(v != f) {
				dfs(v, u, min(mn, a[u]));
				one[u] += one[v];
				two[u] += two[v];
			}
		}
		if(a[u] < mn) {
			int less = min(one[u], two[u]);
			ans += 2LL * a[u] * less;
			one[u] -= less;
			two[u] -= less;
		}
	};	

	dfs(0, -1, 1000000001);

	if(one[0] != 0 || two[0] != 0) {
		cout << -1 << '\n'; 
	} else {
		cout << ans << '\n';
	}

	return 0;
}
