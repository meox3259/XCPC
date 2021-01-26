#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n);
	vector<vector<int> > rev(n);
	vector<int> deg(n);
	vector<int> rdeg(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x --;
		y --;
		adj[x].emplace_back(y);
		rev[y].emplace_back(x);
		deg[y] ++;
		rdeg[x] ++;
	}

	queue<int> q;

	vector<int> f(n, -1);
	f[0] = 0;
	q.emplace(0);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : adj[x]) {
			if (f[y] == -1) {
				f[y] = f[x] + 1;
				q.emplace(y);
			}
		}
	}

	vector<int> g(n, -1);
	g[n - 1] = 0;
	q.emplace(n - 1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : rev[x]) {
			if (g[y] == -1) {
				g[y] = g[x] + 1;
				q.emplace(y);
			}
		}
	}

	q.emplace(n - 1);
	vector<double> dp(n);
	vector<int> tmp(rdeg);
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cnt ++;
		for (int y : rev[x]) {
			if (-- tmp[y] == 0) {
				q.emplace(y);
			}
			dp[y] += (dp[x] + 1.) / (double)(rdeg[y]);
		}
	}

	double ans = dp[0];

	for (int i = 0; i < n; ++i) {
		if (rdeg[i] == 1) {
			continue;
		}
		double mx = 0;
		for (int j : adj[i]) {
			mx = max(mx, dp[j]);
		}
		int tar = -1;
		for (int j : adj[i]) {
			if (dp[j] == mx) {
				tar = j;
			}
		}
		queue<int> q;
		q.emplace(n - 1);
		vector<double> ndp(n);
		vector<int> tmp(rdeg);
		tmp[i] --;
		rdeg[i] --;
		int cnt = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			cnt ++;
			for (int y : rev[x]) {
				if (x == tar && y == i) {
					continue;
				}
				if (-- tmp[y] == 0) {
					q.emplace(y);
				}
				ndp[y] += (ndp[x] + 1.) / (double)(rdeg[y]);
			}
		}
		rdeg[i] ++;
		if (cnt == n) {
			ans = min(ans, ndp[0]);
		}
	}

	cout << fixed << setprecision(10);

	cout << ans << '\n';

	return 0;

}
