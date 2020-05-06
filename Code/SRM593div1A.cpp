#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

class HexagonalBoard {
	public:
	int minColors(vector<string> b) {
		int n = b.size();
		auto id = [&] (int i, int j) {
			return i * n + j; 
		};

		vector<vector<int> > G(n * n);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < 4; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if(0 <= x && x < n && 0 <= y && y < n) {
						G[id(i, j)].emplace_back(id(x, y));
					}
					if(i + 1 < n && j >= 1) {
						G[id(i, j)].emplace_back(id(i + 1, j - 1));
						G[id(i + 1, j - 1)].emplace_back(id(i, j));
					}
				}
			}
		}

		vector<bool> mark(n * n, false);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(b[i][j] == 'X') {
					mark[id(i, j)] = true;
				}
			}
		}

		vector<int> c(n * n, -1);
		vector<int> sz(n * n);

		bool zero = true;
		bool one = true;
		bool two = true;

		function<void(int, int)> dfs = [&] (int u, int f) {
			c[u] = f;
			sz[u] = 1;
			for(int v : G[u]) {
				if(mark[v]) {
					if(c[v] == -1) {
						dfs(v, f ^ 1);
						sz[u] += sz[v];
					} else if(c[v] == c[u]) {
						two = false;
					}
				}
			}
		}; 

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(mark[id(i, j)] && c[id(i, j)] == -1) {
					zero = false;
					dfs(id(i, j), 0);
					if(sz[id(i, j)] > 1) {
						one = false;
					}
				}
			}
		}

		if(zero) {
			return 0;
		}
		if(one) {
			return 1;
		}
		if(two) {
			return 2;
		}
		return 3;
	}
};
