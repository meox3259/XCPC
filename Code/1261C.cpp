#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	vector<int> sum_r(m), sum_c(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	auto check = [&] (int T) {
		queue<int> q;
		vector<vector<int> > dis(n, vector<int> (m, -1));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				for(int k = 0; k < 4; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if(x >= 0 && x < n && y >= 0 && y < m) {
						q.push(x);
						q.push(y);
						dis[x][y] = 0;
					}
				}
			}
		}
		while(!q.empty()) {
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			for(int k = 0; k < 4; ++k) {
				int t_x = x + dx[k], t_y = y + dy[k];
				if(t_x >= 0 && t_x < n && t_y >= 0 && t_y < m && dis[t_x][t_y] == -1 && s[t_x][t_y] == '#') {
					dis[t_x][t_y] = dis[x][y] + 1;
					q.push(t_x);
					q.push(t_y);
				}
			}
		}
		vector<vector<bool> > vis(n, vector<bool> (m, false));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(dis[i][j] == T) {
					q.push(i);
					q.push(j);
					vis[i][j] = 1;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0 ; j < m; ++j) {
				dis[i][j] = 0;
			}
		}
		while(!q.empty()) {
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			if(dis[x][y] == T) {
				continue;
			}
			for(int k = 0; k < 4; ++k) {
				int t_x = x + dx[k], t_y = y + dy[k];
				if(t_x < 0 || t_x >= n || t_y < 0 || t_y >= m) {
					return false;
				}
				if(t_x >= 0 && t_x < n && t_y >= 0 && t_y < m && !vis[t_x][t_y]) {
					vis[t_x][t_y] = 1;
					dis[t_x][t_y] = dis[x][y] + 1;
					q.push(t_x);
					q.push(t_y);
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cout << dis[i][j] << " ";
			}
			cout << '\n';
		}
		cout << "------------------------------" << '\n';
		for(int i = 0; i < n; ++i) {
			for(int j = 0 ; j < m; ++j) {
				if(s[i][j] == '#' && !vis[i][j]) {
					return false;
				}
				if(s[i][j] == '.' && vis[i][j]) {
					return false;
				}
			}
		}
		return true;
	};
	int l = 0, r = max(n, m) + 1, ans = 0;
	while(r - l > 1) {
		int mid = l + r >> 1;
		printf("mid = %d\n", mid);
		if(check(mid)) {
			l = ans = mid;
		} else {
			r = mid;
		}
	}
	cout << ans << '\n';
	return 0;
}
