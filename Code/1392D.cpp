#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'L') {
				a[i] = 0;
			} else {
				a[i] = 1;
			}
		}
	
		auto check = [&] (int x, int y, int z) {	
			int cnt = (x == 1) + (z == 0);
			if(cnt == 1) {
				if(x == 1 && y == 1) {
					return false;
				}
				if(y == 0 && z == 0) {
					return false;
				}
			}
			return true;
		};

		int ans = inf;
		for(int X = 0; X < 2; ++X) {
			for(int Y = 0; Y < 2; ++Y) {
				vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (2, vector<int> (2, inf)));
				dp[2][X][Y] = (X != a[0]) + (Y != a[1]);
				for(int i = 2; i < n; ++i) {
					for(int x = 0; x < 2; ++x) {
						for(int y = 0; y < 2; ++y) {
							for(int z = 0; z < 2; ++z) {
								if(check(x, y, z)) {
									dp[i + 1][y][z] = min(dp[i + 1][y][z], dp[i][x][y] + (a[i] != z));
								}
							}
						}
					}
				}
				for(int i = 0; i < 2; ++i) {
					for(int j = 0; j < 2; ++j) {
						if(check(i, j, X) && check(j, X, Y)) {
							ans = min(ans, dp[n][i][j]);
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
