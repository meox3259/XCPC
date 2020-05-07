#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

char s[1005][1005];

bool vis[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	bool ok = true;

	bool X = false;
	bool Y = false;

	for(int i = 0; i < n; ++i) {
		vector<int> st;
		for(int j = 0; j < m; ++j) {
			if(s[i][j] == '#') {
				st.emplace_back(j);
			}
		}
		if(st.empty()) {
			X = true;
		}
		for(int j = 1; j < st.size(); ++j) {
			if(st[j - 1] != st[j] - 1) {
				ok = false;
			}
		}
	}

	for(int j = 0; j < m; ++j) {
		vector<int> st;
		for(int i = 0; i < n; ++i) {
			if(s[i][j] == '#') {
				st.emplace_back(i);
			}
		}
		if(st.empty()) {
			Y = true;
		}
		for(int i = 1; i < st.size(); ++i) {
			if(st[i - 1] != st[i] - 1) {
				ok = false;
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(s[i][j] == '#' && !vis[i][j]) {
				++ans;
				queue<int> q;
				q.emplace(i);
				q.emplace(j);
				vis[i][j] = 1;
				while(!q.empty()) {
					int x = q.front();
					q.pop();
					int y = q.front();
					q.pop();
					vis[x][y] = 1;
					for(int k = 0; k < 4; ++k) {
						int xx = x + dx[k];
						int yy = y + dy[k];
						if(0 <= xx && xx < n && 0 <= yy && yy < m && s[xx][yy] == '#' && !vis[xx][yy]) {
							q.emplace(xx);
							q.emplace(yy);
							vis[xx][yy] = 1;
						} 
					}
				}
			}
		}
	}

	if(X != Y) {
		ok = false;
	}

	if(ans == 0) {
		cout << 0 << '\n';
		exit(0);
	}

	if(!ok) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
