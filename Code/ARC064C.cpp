#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;

	int n;
	cin >> n;

	vector<int> x;
	vector<int> y;
	vector<int> r;
	x.resize(n + 1);
	y.resize(n + 1);
	r.resize(n + 1);
	
	x[0] = sx;
	y[0] = sy;
	r[0] = 0;

	for(int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> r[i];
	}

	vector<double> dis;
	dis.assign(n + 1, inf);
	dis[0] = 0;

	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;
	q.emplace(0, 0);

	auto d = [&] (int sx, int sy, int tx, int ty) {
		return sqrt(1. * (sx - tx) * (sx - tx) + 1. * (sy - ty) * (sy - ty));
	};

	while(!q.empty()) {
		auto p = q.top();
		q.pop();

		int u = p.second;

		if(p.first > dis[u]) {
			continue;
		}

		for(int i = 1; i <= n; ++i) {
			double tmp = dis[u] + max(.0, d(x[u], y[u], x[i], y[i]) - r[u] - r[i]); 

			if(dis[i] > tmp) {
				dis[i] = tmp;
				q.emplace(dis[i], i);
			}
		}
	}

	double ans = inf;

	for(int i = 0; i <= n; ++i) {
		ans = min(ans, dis[i] + max(.0, d(tx, ty, x[i], y[i]) - r[i]));
	}

	cout << fixed << setprecision(15);

	cout << ans << '\n';

	return 0;
}
