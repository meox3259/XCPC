#include <bits/stdc++.h>

using namespace std;

const int inf = 100000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > G(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x --;
		y --;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}

	vector<int> s(2);
	vector<int> t(2);
	vector<int> l(2);
	for (int i = 0; i < 2; ++i) {
		cin >> s[i] >> t[i] >> l[i];
		s[i] --;
		t[i] --;
	}

	vector<vector<int> > d(n, vector<int> (n, -inf));
	for (int i = 0; i < n; ++i) {
		d[i][i] = 0;
		queue<int> q;
		q.emplace(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : G[u]) {
				if (d[i][v] == -inf) {
					d[i][v] = d[i][u] + 1;
					q.emplace(v);
				} 
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (d[i][j] + min(d[s[0]][i] + d[j][t[0]], d[t[0]][i] + d[j][s[0]]) <= l[0]
			 && d[i][j] + min(d[s[1]][i] + d[j][t[1]], d[t[1]][i] + d[j][s[1]]) <= l[1]) {
				ans = max(ans, m - (d[i][j] + min(d[s[0]][i] + d[j][t[0]], d[t[0]][i] + d[j][s[0]]) +
							   min(d[s[1]][i] + d[j][t[1]], d[t[1]][i] + d[j][s[1]])));
			}	
		}
	}

	if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1]) {
		ans = max(ans, m - (d[s[0]][t[0]] + d[s[1]][t[1]]));
	}

	cout << ans << '\n';

	return 0;
}
