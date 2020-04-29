#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	int n, m, s;
	cin >> n >> m >> s;

	auto id = [&] (int i, int j) {
		return i * 2501 + j;
	};

	vector<vector<pair<int, int> > > G;
	G.resize(id(n, 0));

	for(int i = 0; i < m; ++i) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		
		--u;
		--v;

		for(int j = 2500; j >= a; --j) {
			G[id(u, j)].emplace_back(id(v, j - a), b);
			G[id(v, j)].emplace_back(id(u, j - a), b);
		}
	}

	for(int i = 0; i < n; ++i) {
		int c, d;
		cin >> c >> d;

		c = min(c, 2500);

		for(int j = 0; j < 2500; ++j) {
			G[id(i, j)].emplace_back(id(i, min(j + c, 2500)), d);
		}
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
	
	q.emplace(0, id(0, min(2500, s)));

	vector<long long> d;
	d.assign(id(n, 0), inf);

	d[id(0, min(2500, s))] = 0;

	while(!q.empty()) {
		auto o = q.top();
		q.pop();

		int u = o.second;

		if(d[u] < o.first) {
			continue;
		}

		for(auto t : G[u]) {
			int v = t.first;
			int w = t.second;

			if(d[u] + w < d[v]) {
				d[v] = d[u] + w;
				q.emplace(d[v], v);
			}
		}
	}

	for(int i = 1; i < n; ++i) {
		long long ans = inf;

		for(int j = 0; j <= 2500; ++j) {
			ans = min(ans, d[id(i, j)]);
		}

		cout << ans << '\n';
	}

	return 0;
}
