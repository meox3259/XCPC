#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 20, inf = 0x3f3f3f3f;
int n;
int dp[maxn][19][2], a[20][2], pos[maxn][20];
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i][0];
	}
	for(int i = 0; i < n; ++i) {
		cin >> a[i][1];
	}
	memset(dp, 0x3f3f, sizeof(dp));
	for(int i = 0; i < n; ++i) {
		dp[1 << i][i][i & 1] = i;
	}
	for(int S = 0; S < 1 << n; ++S) {
		for(int i = 0; i < n; ++i) {
			pos[S][i] = i;
			for(int j = i + 1; j < n; ++j) {
				if(S >> j & 1) {
					++pos[S][i];
				}
			}
		}
	}
	for(int S = 0; S < 1 << n; ++S) {
		int c = __builtin_popcount(S);
		for(int i = 0; i < n; ++i) {
			if(S >> i & 1) {
				for(int j = 0; j < n; ++j) {
					if(!(S >> j & 1)) {
						for(int k = 0; k < 2; ++k) {
							if(a[j][abs(j - c) & 1] >= a[i][k]) {
								dp[S ^ (1 << j)][j][abs(j - c) & 1] = min(dp[S ^ (1 << j)][j][abs(j - c) & 1], dp[S][i][k] + pos[S][j] - c);
							}
						}
					}
				}
			}
		}
	}
	int ans = inf;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			ans = min(ans, dp[(1 << n) - 1][i][j]);
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;
	/*
		1 2 3 -> 1 -3 -2 -> 3 -1 -2
		1 2 3 -> -2 -1 3 -> -2 -3 1
		dp[S][i][0][1] : 选中了S集合 以i为结尾最少步数
	*/
	return 0;
}
