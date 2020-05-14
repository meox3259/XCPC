#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> d(m + 1);

	for(int i = 0; i < m; ++i) {
		cin >> d[i];
	}

	int g, r;
	cin >> g >> r;

	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	m = d.size();

	auto id = [&] (int i, int j) {
		return i * g + j;
	};

	deque<pair<int, int> > q;
	q.push_front({0, 0});

	vector<long long> dis(id(m, 0), inf);
	dis[id(0, 0)] = 0;

	while(!q.empty()) {
		auto [i, j] = q.front();
		q.pop_front();

		if(i + 1 < m && j + d[i + 1] - d[i] <= g) {
			int t = (j + d[i + 1] - d[i]) % g;
			if(j != 0) {
				if(dis[id(i + 1, t)] > dis[id(i, j)]) {
					dis[id(i + 1, t)] = dis[id(i, j)];
					q.push_front({i + 1, t});
				}
			} else {
				if(dis[id(i + 1, t)] > dis[id(i, j)] + 1) {
					dis[id(i + 1, t)] = dis[id(i, j)] + 1;
					q.push_back({i + 1, t});
				}
			}
		}

		if(i >= 1 && j + d[i] - d[i - 1] <= g) {
			int t = (j + d[i] - d[i - 1]) % g;
			if(j != 0) {
				if(dis[id(i - 1, t)] > dis[id(i, j)]) {
					dis[id(i - 1, t)] = dis[id(i, j)];
					q.push_front({i - 1, t});
				}
			} else {
				if(dis[id(i - 1, t)] > dis[id(i, j)] + 1) {
					dis[id(i - 1, t)] = dis[id(i, j)] + 1;
					q.push_back({i - 1, t});
				}
			}
		}
	}

	long long ans = inf;

	for(int i = 0; i < m; ++i) {
		if(n - d[i] <= g && dis[id(i, 0)] != inf) {
			ans = min(ans, 1LL * (g + r) * dis[id(i, 0)] + n - d[i]);
		}
	}

	if(ans == inf) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
