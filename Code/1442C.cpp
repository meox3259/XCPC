#include <bits/stdc++.h>

using namespace std;

#define int long long

const int P = 998244353;
const long long inf = 1000000000000000000;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int> > > G(n);
	vector<pair<int, int> > e;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		e.emplace_back(u, v);
		G[u].emplace_back(v, 0);
		G[v].emplace_back(u, 1);
	}

	vector<vector<pair<int, int> > > dis(n, vector<pair<int, int> > (2, {1000000000, 1000000000}));
	dis[0][0] = {0, 0};

	priority_queue<tuple<pair<int, int>, int, int>, vector<tuple<pair<int, int>, int, int> >, greater<tuple<pair<int, int>, int, int> > > q;
	q.emplace(make_pair(0, 0), 0, 0);

	vector<int> pre(n, -1);
	while(!q.empty()) {
		auto [o, u, s] = q.top();
		q.pop();
		if(o > dis[u][s]) {
			continue;
		}
		for(auto [v, w] : G[u]) {
			pair<int, int> tmp = {dis[u][s].first + (s ^ w), dis[u][s].second + 1};
			if(tmp < dis[v][w]) {
				dis[v][w] = tmp;
				q.emplace(tmp, v, w);
			}
		}
	}

	if(min(dis[n - 1][0], dis[n - 1][1]).first > 60) {
		long long ans = 0;
		long long fac = 1;
		auto z = min(dis[n - 1][0], dis[n - 1][1]);
		for(int i = 0; i < z.first; ++i) {
			ans = (ans + fac) % P;
			fac = fac * 2 % P;
		}
		ans = (ans + z.second) % P;
		cout << ans << '\n';
		exit(0);
	}

	vector<vector<long long> > dp(n, vector<long long> (63, inf));
	queue<pair<int, int> > st;
	st.emplace(0, 0);
	dp[0][0] = 0;

	while(!st.empty()) {
		auto [u, d] = st.front();
		st.pop();
		int s = (d & 1);
		for(auto [v, w] : G[u]) {
			if((s ^ w) == 0) {
				if(dp[v][d] == inf) {
					dp[v][d] = dp[u][d] + 1;
					st.emplace(v, d);
				}
			} else {
				if(d + 1 < 63 && dp[v][d + 1] == inf) {
					dp[v][d + 1] = dp[u][d] + 1;
					st.emplace(v, d + 1);
				}
			}
		}
	}

	long long ans = inf;
	long long sum = 0;
	for(int i = 0; i < 63; ++i) {
		ans = min(ans, dp[n - 1][i] + sum);
		sum = (sum + (1LL << (long long)(i)));
	}

	cout << ans % P << '\n';

	return 0;
}
