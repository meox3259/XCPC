#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int> > s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i].second >> s[i].first;
	}

	sort(s.begin(), s.end());

	vector<int> deg(n + 1);
	vector<vector<pair<int, int> > > G(n + 1);
	for (int i = 0; i + 1 < n; ++i) {
		G[i].emplace_back(i + 1, 0);
		deg[i + 1] ++;
	}

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		v.emplace_back(s[i].first);
	}

	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(v.begin(), v.end(), s[i].second);
		if (it != v.end()) {
			int p = it - v.begin();
			G[i].emplace_back(p, s[i].first - s[i].second);
			deg[p] ++;
		} else {
			G[i].emplace_back(n, s[i].first);
			deg[n] ++;
		}
	}

	vector<long long> dis(n + 1, inf);

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (deg[i] == 0) {
			dis[i] = 0;
			q.emplace(i);
		}
	}

	vector<int> ddeg(deg);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (auto [y, w] : G[x]) {
			dis[y] = min(dis[y], dis[x] + w);
			if (! --deg[y]) {
				q.emplace(y);
			}
		}
	}

	vector<long long> dp(n + 1);
	for (int i = 0; i < n; ++i) {
		if (ddeg[i] == 0) {
			dp[i] = 1;
			q.emplace(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto [y, w] : G[x]) {
			if (dis[y] == dis[x] + w) {
				dp[y] = (dp[y] + dp[x]) % P;
			}
			if (! --ddeg[y]) {
				q.emplace(y);
			}
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
