#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> dx = {0, -1, 0, 1};
	vector<int> dy = {-1, 0, 1, 0};
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int> > > p;
	vector<vector<int> > a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i].resize(m);
	}
	p.resize(k);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
			--a[i][j];
			p[a[i][j]].emplace_back(i, j);
		}
	}
	vector<vector<vector<int> > > dis;
	dis.resize(k);
	function<void(int)> bfs = [&] (int c) {
		queue<pair<int, int> > q;
		dis[c].resize(n);
		for(int i = 0; i < n; ++i) {
			dis[c][i].assign(m, -1);
		}
		for(auto [x, y] : p[c]) {
			q.emplace(x, y);
			dis[c][x][y] = 0;
		}
		vector<int> vis;
		vis.resize(k);
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			int C = a[x][y];
			if(vis[C] == 0) {
				vis[C] = 1;
				for(auto [tx, ty] : p[C]) {
					if(dis[c][tx][ty] == -1) {
						dis[c][tx][ty] = dis[c][x][y] + 1;
						q.emplace(tx, ty);
					}
				}
			}
			for(int i = 0; i < 4; ++i) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if(tx >= 0 && tx < n && ty >= 0 && ty < m && dis[c][tx][ty] == -1) {
					dis[c][tx][ty] = dis[c][x][y] + 1;
					q.emplace(tx, ty);
				} 
			}
		}
	};
	for(int i = 0; i < k; ++i) {
		bfs(i);
	}
	int q;
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;
		--x2;
		--y2;
		int ans = abs(x1 - x2) + abs(y1 - y2);
		for(int i = 0; i < k; ++i) {
			if(dis[i][x1][y1] != -1 && dis[i][x2][y2] != -1) {
				ans = min(ans, dis[i][x1][y1] + dis[i][x2][y2] + 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
