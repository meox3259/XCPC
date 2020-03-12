#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h, w;
	cin >> h >> w;
	vector<vector<int> > a;
	vector<vector<int> > b;
	a.resize(h);
	b.resize(h);
	for(int i = 0; i < h; ++i) {
		a[i].resize(w);
		b[i].resize(w);
	}
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			cin >> b[i][j];
		}
	}
	vector<vector<vector<int> > > dp;
	dp.resize(h);
	for(int i = 0; i < h; ++i) {
		dp[i].resize(w);
		for(int j = 0; j < w; ++j) {
			dp[i][j].resize(6405);
		}
	}
	dp[0][0][abs(a[0][0] - b[0][0])] = 1;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			for(int k = 0; k < dp[i][j].size(); ++k) {
				if(dp[i][j][k] == 1) {
					if(i + 1 < h) {
						int t1 = abs(k - abs(a[i + 1][j] - b[i + 1][j]));
						int t2 = abs(k + abs(a[i + 1][j] - b[i + 1][j]));
						if(t1 < dp[i + 1][j].size()) {
							dp[i + 1][j][t1] = 1;
						}
						if(t2 < dp[i + 1][j].size()) {
							dp[i + 1][j][t2] = 1;
						}
					}
					if(j + 1 < w) {
						int t1 = abs(k - abs(a[i][j + 1] - b[i][j + 1]));
						int t2 = abs(k + abs(a[i][j + 1] - b[i][j + 1]));
						if(t1 < dp[i][j + 1].size()) {
							dp[i][j + 1][t1] = 1;
						}
						if(t2 < dp[i][j + 1].size()) {
							dp[i][j + 1][t2] = 1;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < dp[h - 1][w - 1].size(); ++i) {
		if(dp[h - 1][w - 1][i] == 1) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}
