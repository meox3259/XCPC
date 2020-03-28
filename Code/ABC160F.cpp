#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > G;
	G.resize(n);

	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;

		--a;
		--b;

		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	vector<long long> dp;
	dp.resize(n);

	vector<long long> fac;
	fac.resize(n + 1);
	
	fac[0] = 1;

	for(int i = 1; i < n + 1; ++i) {
		fac[i] = fac[i - 1] * i % P;
	}
	
	auto power = [&] (long long x, long long t) {
		long long ret = 1;
		
		for(; t; t >>= 1, x = x * x % P) {
			if(t & 1) {
				ret = ret * x % P;
			}
		}

		return ret;
	};

	vector<int> sz;
	sz.resize(n);

	function<void(int, int)> pre = [&] (int u, int f) {
		dp[u] = 1;	
		sz[u] = 1;

		for(auto v : G[u]) {
			if(v != f) {
				pre(v, u);

				dp[u] = dp[u] * dp[v] % P;
				dp[u] = dp[u] * power(fac[sz[v]], P - 2) % P;
				sz[u] += sz[v];
			}
		}

		dp[u] = dp[u] * fac[sz[u] - 1] % P;
	};

	vector<long long> ans;
	ans.resize(n);

	pre(0, -1);

	function<void(int, int, long long)> dfs = [&] (int u, int f, long long up) {
		ans[u] = 1;

		for(auto v : G[u]) {
			if(v != f) {
				ans[u] = ans[u] * dp[v] % P;
				ans[u] = ans[u] * power(fac[sz[v]], P - 2) % P;
			}
		}

		ans[u] = ans[u] * up % P;
		ans[u] = ans[u] * power(fac[n - sz[u]], P - 2) % P;
		ans[u] = ans[u] * fac[n - 1] % P;

		for(auto v : G[u]) {
			if(v != f) {
				long long tmp = ans[u];

				tmp = tmp * power(dp[v], P - 2) % P;
				tmp = tmp * fac[sz[v]] % P;
				tmp = tmp * power(fac[n - 1], P - 2) % P;
				tmp = tmp * fac[n - sz[v] - 1] % P;

				dfs(v, u, tmp);
			}
		}
	};

	dfs(0, -1, 1);

	for(auto x : ans) {
		cout << x << '\n';
	}

	return 0;
}
