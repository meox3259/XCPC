#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
const char dir[] = {'R', 'D', 'L', 'U'}; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int> > x;
	vector<vector<int> > y;
	vector<vector<int> > vis;
	vis.resize(n);
	x.resize(n);
	y.resize(n);
	for(int i = 0; i < n; ++i) {
		x[i].resize(n);
	}
	for(int i = 0; i < n; ++i) {
		y[i].resize(n);
	}
	for(int i = 0; i < n; ++i) {
		vis[i].resize(n);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> x[i][j] >> y[i][j]; 
			if(x[i][j] > 0) {
				--x[i][j];
			}
			if(y[i][j] > 0) {
				--y[i][j];
			}
		}
	}
	vector<vector<char> > ans;
	ans.resize(n);
	for(int i = 0; i < n; ++i) {
		ans[i].resize(n, '.');
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(x[i][j] == i && y[i][j] == j) {
				ans[i][j] = 'X';
				queue<int> q;
				q.emplace(i);
				q.emplace(j);
				vis[i][j] = 1;
				while(!q.empty()) {
					int X = q.front();
					q.pop();
					int Y = q.front();
					q.pop();
					for(int k = 0; k < 4; ++k) {
						int XX = X + dx[k];
						int YY = Y + dy[k];
						if(XX >= 0 && XX < n && YY >= 0 && YY < n && x[XX][YY] == i && y[XX][YY] == j && !vis[XX][YY]) {
							vis[XX][YY] = 1;
							ans[XX][YY] = dir[k];
							q.emplace(XX);
							q.emplace(YY);
						}
					}
				}
			}
		}
	}
/*	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(x[i][j] != -1 && y[i][j] != -1) {
				if(!vis[i][j]) {
					cout << "INVALID" << '\n';
					return 0;
				}
			}
		}
	}
*/	vector<vector<int> > d;
	d.resize(n);
	for(int i = 0; i < n; ++i) {
		d[i].resize(n);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(x[i][j] == -1) {
				bool f = 0;
				for(int k = 0; k < 4; ++k) {
					int X = i + dx[k];
					int Y = j + dy[k];
					if(X >= 0 && X < n && Y >= 0 && Y < n && x[X][Y] == -1) {
						ans[X][Y] = dir[k];
						if(ans[X][Y] == 'L') {
							ans[i][j] = 'R';
						}
						if(ans[X][Y] == 'R') {
							ans[i][j] = 'L';
						}
						if(ans[X][Y] == 'U') {
							ans[i][j] = 'D';
						}
						if(ans[X][Y] == 'D') {
							ans[i][j] = 'U';
						}
						f = 1;
						vis[X][Y] = vis[i][j] = 1;
						queue<int> q;
						q.emplace(i);
						q.emplace(j);
						while(!q.empty()) {
							int u = q.front();
							q.pop();
							int v = q.front();
							q.pop();
							for(int k = 0; k < 4; ++k) {
								int X = u + dx[k];
								int Y = v + dy[k];
								if(X >= 0 && X < n && Y >= 0 && Y < n && !vis[X][Y] && x[X][Y] == -1) {
									q.emplace(X);
									q.emplace(Y);
									vis[X][Y] = 1;
									ans[X][Y] = dir[k];
								}
							}
						}
					}
				}
				if(!f) {
					cout << "INVALID" << '\n';
					return 0;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(!vis[i][j]) {
				cout << "INVALID" << '\n';
				return 0;
			}
		}
	}
	cout << "VALID" << '\n';
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}
