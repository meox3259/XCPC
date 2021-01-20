#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;
const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s --;
	t --;

	vector<vector<pair<int, int> > > G(n);
	for (int i = 0; i < m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		u --;
		v --;
		G[u].emplace_back(v, d);
		G[v].emplace_back(u, d);
	}

	auto dij = [&] (auto G, int s, int t) {
		vector<long long> d(n, inf);
		d[s] = 0;

		priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
		q.emplace(0, s);

		while (!q.empty()) {
			auto [cur, x] = q.top();
			q.pop();

			if (cur > d[x]) {
				continue;
			}

			for (auto [y, w] : G[x]) {
				if (d[y] > d[x] + w) {
					d[y] = d[x] + w;
					q.emplace(d[y], y);
				}
			}
		}

		return d;
	};

	auto calc = [&] (auto G, auto d, int s, int t) {
		vector<long long> dp(n);
		vector<int> deg(n);

		for (int x = 0; x < n; ++x) {
			for (auto [y, w] : G[x]) {
				if (d[y] == d[x] + w) {
					deg[y] ++;
				}
			}
		}

		queue<int> q;
		q.emplace(s);
		dp[s] = 1;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (auto [y, w] : G[x]) {
				if (d[y] == d[x] + w) {
					dp[y] += dp[x];
					dp[y] %= P;
					if (-- deg[y] == 0) {
						q.emplace(y);
					}
				}
			}
		}

		return dp;
	};

	vector<long long> ds = dij(G, s, t);
	vector<long long> dt = dij(G, t, s);
	vector<long long> f = calc(G, ds, s, t);
	vector<long long> g = calc(G, dt, t, s);

	long long ans = 0;
	ans += f[t] * g[s] % P;

	for (int x = 0; x < n; ++x) {
		for (auto [y, w] : G[x]) {
			if (ds[x] + dt[y] + w == ds[t] && abs(ds[x] - dt[y]) < w) {
				ans -= f[x] * g[y] % P * f[x] % P * g[y] % P;	
				ans += P;
				ans %= P;
			}
		}
	}

	for (int x = 0; x < n; ++x) {
		if (ds[x] + dt[x] == ds[t] && ds[x] == dt[x]) {
			ans -= f[x] * g[x] % P * f[x] % P * g[x] % P;
			ans += P;
			ans %= P;
		}
	}

	cout << ans << '\n';

	return 0;
}
