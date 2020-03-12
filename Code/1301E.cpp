#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const vector<char> color = {'R', 'G', 'Y', 'B'};
	const vector<int> dx = {0, 0, 1, 1};
	const vector<int> dy = {0, 1, 0, 1};
	int n, m, q;
	cin >> n >> m >> q;
	vector<string> s;
	vector<vector<vector<int> > > sum;
	sum.resize(n + 1);
	s.resize(n);
	for(int i = 0; i <= n; ++i) {
		sum[i].resize(m + 1);
		for(int j = 0; j <= m; ++j) {
			sum[i][j].resize(4);
		}
	}
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			for(int k = 0; k < 4; ++k) {
				sum[i + 1][j + 1][k] = 
				sum[i][j + 1][k] + 
				sum[i + 1][j][k] -
				sum[i][j][k] + (s[i][j] == color[k]);
			}
		}
	}
	vector<vector<vector<vector<int> > > > st;
	vector<int> Log;
	st.resize(n + 1);
	for(int i = 0; i <= n; ++i) {
		st[i].resize(m + 1);
		for(int j = 0; j <= m; ++j) {
			st[i][j].resize(12);
			for(int k = 0; k < 12; ++k) {
				st[i][j][k].resize(12);
			}
		}
	}
	Log.resize(501);
	function<void()> build = [&] () {
		for(int i = 2; i < 501; ++i) {
			Log[i] = Log[i >> 1] + 1;
		}
		for(int k = 1; k < 11; ++k) {
			for(int i = 0; i + (1 << k) <= n; ++i) {
				for(int j = 0; j < m; ++j) {
					st[i][j][k][0] = max(st[i][j][k - 1][0], st[i + (1 << k - 1)][j][k - 1][0]);
				}
			}
		}
		for(int y = 1; y < 11; ++y) {
			for(int x = 0; x < 11; ++x) {
				for(int i = 0; i + (1 << x) <= n; ++i) {
					for(int j = 0; j + (1 << y) <= m; ++j) {
						st[i][j][x][y] = max(st[i][j][x][y - 1], st[i][j + (1 << y - 1)][x][y - 1]);
					}
				}	 
			}
		}
	};
	auto equal = [&] (int x1, int y1, int x2, int y2, int k) {
		++x1;
		++y1;
		++x2;
		++y2;
		return (sum[x2][y2][k] - 
				sum[x1 - 1][y2][k] - 
				sum[x2][y1 - 1][k] + 
				sum[x1 - 1][y1 - 1][k] == 
				(y2 - y1 + 1) * (x2 - x1 + 1));
	};
	auto check = [&] (int x, int y, int r) {
		if(x < 0 || y < 0) {
			return false;
		}
		if(x + r * 2 - 1 >= n || y + r * 2 - 1 >= m) {
			return false;
		}
		for(int i = 0; i < 4; ++i) {
			int tx = x + dx[i] * r;
			int ty = y + dy[i] * r;
			if(!equal(tx, ty, tx + r - 1, ty + r - 1, i)) {
				return false;
			}
		}
		return true;
	};
	auto query = [&] (int x1, int y1, int x2, int y2) {
		if(x2 < x1 || y2 < y1 || 
		   x1 < 0 || x2 >= n || 
		   y1 < 0 || y2 >= m) {
			return 0;
		} 
		int a = Log[x2 - x1 + 1];
		int b = Log[y2 - y1 + 1];
		return max(max(st[x1][y1][a][b], 
					   st[x2 - (1 << a) + 1][y1][a][b]),
				   max(st[x1][y2 - (1 << b) + 1][a][b], 
					   st[x2 - (1 << a) + 1][y2 - (1 << b) + 1][a][b]));
	};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			int l = 0, r = 501;
			while(r - l > 1) {
				int mid = l + r >> 1;
				if(check(i - mid + 1, j - mid + 1, mid)) {
					l = st[i][j][0][0] = mid;
				} else {
					r = mid;
				}
			}
		}
	}
	build();
	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;
		--x2;
		--y2;
		int l = 0, r = 251, ans = 0;
		while(r - l > 1) {
			int mid = l + r >> 1;
			if(query(x1 + mid - 1, 
					 y1 + mid - 1, 
					 x2 - mid, 
					 y2 - mid) >= mid) {
				ans = l = mid;
			} else {
				r = mid;
			}
		}
		cout << ans * ans * 4 << '\n';
	}
	return 0;
}
