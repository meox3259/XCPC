#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	auto in = [&] (int x, int y) {
		return (0 <= x && x < n && 0 <= y && y < m);
	};

	vector<vector<int> > d(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				for (int k = 0; k < 4; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (in(x, y) && s[x][y] == '.') {
						d[x][y] ++;
					}
				}
			}
		}
	}

	vector<vector<bool> > vis(n, vector<bool> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && s[i][j] == '.') {
				queue<int> q;
				vector<int> cnt(2);
				q.emplace(i);
				q.emplace(j);
				vis[i][j] = true;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					int y = q.front();
					q.pop();
					cnt[(x + y) & 1] ++;
					for (int k = 0; k < 4; ++k) {
						int xx = x + dx[k];
						int yy = y + dy[k];
						if (in(xx, yy) && s[xx][yy] == '.' && !vis[xx][yy]) {
							q.emplace(xx);
							q.emplace(yy);
							vis[xx][yy] = true;
						}
					}
				}

				if (cnt[0] != cnt[1]) {
					cout << "Not unique" << '\n';
					exit(0);
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vis[i][j] = false;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.' && d[i][j] == 1) {
				q.emplace(i);
				q.emplace(j);
				vis[i][j] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				cnt ++;
			}
		}
	}

	vector<vector<bool> > eat(n, vector<bool> (m));
	vector<tuple<int, int, int, int> > ans;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (in(xx, yy) && s[xx][yy] == '.' && !eat[xx][yy]) {
				d[xx][yy] --;
			}
		}
		for (int k = 0; k < 4; ++k) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (in(xx, yy) && s[xx][yy] == '.' && !eat[xx][yy]) {
				ans.emplace_back(x, y, xx, yy);
				vis[xx][yy] = true;
				eat[x][y] = true;
				eat[xx][yy] = true;
				cnt -= 2;
				for (int kk = 0; kk < 4; ++kk) {
					int xxx = xx + dx[kk];
					int yyy = yy + dy[kk];
					if (in(xxx, yyy) && s[xxx][yyy] == '.' && !eat[xxx][yyy]) {
						-- d[xxx][yyy];	
						if (d[xxx][yyy] == 1) {
							q.emplace(xxx);
							q.emplace(yyy);
							vis[xxx][yyy] = true;
						}
					}
				}
			}
		}
	}

	if (cnt != 0) {
		cout << "Not unique" << '\n';
		exit(0);
	}

	for (auto [x, y, xx, yy] : ans) {
		if (x != xx) {
			if (x > xx) {
				swap(x, xx);
				swap(y, yy);
			}
			s[x][y] = '^';
			s[xx][yy] = 'v';
		}
		if (y != yy) {
			if (y > yy) {
				swap(x, xx);
				swap(y, yy);
			}
			s[x][y] = '<';
			s[xx][yy] = '>';
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << s[i] << '\n';
	}

	return 0;
}
