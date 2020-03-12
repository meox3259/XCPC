#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
	int n;
	cin >> n;
	vector<vector<int> > G;
	G.resize(n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	vector<int> sz;
	vector<int> bin;
	sz.resize(n);
	bin.resize(n + 1);
	bin[0] = 1;
	for(int i = 1; i <= n; ++i) {
		bin[i] = 2LL * bin[i - 1] % P;
	}
	int ans = 0;
	function<void(int, int)> dfs = [&] (int u, int f) {
		sz[u] = 1;
		for(auto v : G[u]) {
			if(v != f) {
				dfs(v, u);
				sz[u] += sz[v];
				ans = (ans + bin[sz[v]]) % P;
			}
		}
		ans = (ans + bin[n - sz[u]]) % P;
	};
	dfs(0, -1);
	auto power = [&] (int x, int t) {
		int ret = 1;
		for(; t; t >>= 1, x = 1LL * x * x % P) {
			if(t & 1) {
				ret = 1LL * ret * x % P;
			}
		}
		return ret;
	};
	ans = (1LL * n * bin[n - 1] - ans + P) % P;
	ans = (ans + n - 1) % P;
	ans = 1LL * ans * power(bin[n] % P, P - 2) % P;
	cout << ans << '\n';
	return 0;
}
