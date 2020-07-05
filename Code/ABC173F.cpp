#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > G(n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> fa(n, -1);
	function<void(int, int)> dfs = [&] (int u, int f) {
		for(int v : G[u]) {
			if(v != f) {
				fa[v] = u;
				dfs(v, u);
			}
		}
	};

	dfs(0, -1);

	long long ans = 0;
	ans += n;
	for(int i = 1; i < n; ++i) {
		long long l = 0;
		long long r = n - 1;
		if(fa[i] < i) {
			l = fa[i] + 1;		
		} else {
			r = fa[i] - 1;
		}

		ans += 1LL * (i - l + 1) * (r - i + 1);
	}

	cout << ans << '\n';

	return 0;
}
