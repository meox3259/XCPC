#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e16;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, l;
	cin >> n >> m >> l;

	vector<vector<long long> > d;
	d.resize(n);
	for(int i = 0; i < n; ++i) {
		d[i].resize(n, inf);
	}
	for(int i = 0; i < n; ++i) {
		d[i][i] = 0;
	}

	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;

		if(c <= l) {
			d[a][b] = min(d[a][b], (long long)c);
			d[b][a] = min(d[b][a], (long long)c);
		}
	}

	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	vector<vector<long long> > cost;
	cost.resize(n);
	
	for(int i = 0; i < n; ++i) {
		cost[i].resize(n, inf);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(d[i][j] <= l) {
				cost[i][j] = 1;
			}
		}
	}

	for(int k = 0; k < n; ++k){
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	int q;
	cin >> q;

	while(q--) {
		int s, t;
		cin >> s >> t;
		--s;
		--t;

		if(cost[s][t] == inf) {
			cout << -1 << '\n';
		} else {
			cout << cost[s][t] - 1 << '\n';
		}
	}
	return 0;
}
