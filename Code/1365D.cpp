#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;

		vector<string> s(n);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		vector<vector<int> > a(n, vector<int> (m));

		bool ok = true;
		bool hav = false;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(s[i][j] == 'G') {
					hav = true;
					for(int k = 0; k < 4; ++k) {
						int x = i + dx[k];
						int y = j + dy[k];
						if(0 <= x && x < n && 0 <= y && y < m && s[x][y] == 'B') {
							ok = false;
						}
					}
				}
			}
		}

		if(!hav) {
			cout << "Yes" << '\n';
			continue;
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(s[i][j] == 'B') {
					for(int k = 0; k < 4; ++k) {
						int x = i + dx[k];
						int y = j + dy[k];
						if(0 <= x && x < n && 0 <= y && y < m) {
							a[x][y] = -1;
						}
					}
					a[i][j] = -1;
				}
				if(s[i][j] == '#') {
					a[i][j] = -1;
				}
			}
		}

		if(a[n - 1][m - 1] == -1) {
			ok = false;
		}

		vector<vector<bool> > vis(n, vector<bool> (m, false));
		
		queue<int> q;
		q.emplace(n - 1);
		q.emplace(m - 1);
		vis[n - 1][m - 1] = true;
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(0 <= xx && xx < n && 0 <= yy && yy < m && a[xx][yy] == 0 && !vis[xx][yy]) {
					q.emplace(xx);
					q.emplace(yy);
					vis[xx][yy] = true;
				}
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(s[i][j] == 'G' && !vis[i][j]) {
					ok = false;
				}
			}
		}

		if(ok) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}
