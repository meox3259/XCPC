#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		--a[i]; --b[i];
	}

	vector<int> c(m);
	vector<int> d(m);
	for(int i = 0; i < m; ++i) {
		cin >> c[i] >> d[i];
		--c[i]; --d[i];
	}

	vector<vector<pair<int, int> > > row(h);
	vector<vector<pair<int, int> > > col(w);
	for(int i = 0; i < n; ++i) {
		row[a[i]].emplace_back(b[i], -1);
		col[b[i]].emplace_back(a[i], -1);
	}

	for(int i = 0; i < m; ++i) {
		row[c[i]].emplace_back(d[i], 1);
		col[d[i]].emplace_back(c[i], 1);
	}

	vector<vector<int> > vish(h, vector<int> (w));
	vector<vector<int> > visw(h, vector<int> (w));
	for(int i = 0; i < h; ++i) {
		sort(row[i].begin(), row[i].end());
		for(auto o : row[i]) {
			if(o.second == 1) {
				visw[i][o.first] = -1;
			}
		}
		for(int j = 0; j < row[i].size(); ++j) {
			int p = row[i][j].first;
			int type = row[i][j].second;
			if(type == -1) {
				for(int cur = p; cur < w && visw[i][cur] == 0; ++cur) {
					visw[i][cur] = 1;
				} 
				for(int cur = p - 1; cur >= 0 && visw[i][cur] == 0; --cur) {
					visw[i][cur] = 1;
				}
			}
		}
	}

	for(int i = 0; i < w; ++i) {
		sort(col[i].begin(), col[i].end());
		for(auto o : col[i]) {
			if(o.second == 1) {
				vish[o.first][i] = -1;
			}
		}
		for(int j = 0; j < col[i].size(); ++j) {
			int p = col[i][j].first;
			int type = col[i][j].second;
			if(type == -1) {
				for(int cur = p; cur < h && vish[cur][i] == 0; ++cur) {
					vish[cur][i] = 1;
				}
				for(int cur = p - 1; cur >= 0 && vish[cur][i] == 0; --cur) {
					vish[cur][i] = 1;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(visw[i][j] > 0 || vish[i][j] > 0) {
				ans += 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
