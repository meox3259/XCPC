#include <bits/stdc++.h>
using namespace std;
int tot;
int a[10][10], to[105], id[10][10];
double dp[105];
int main() {
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			int p = ((i & 1) ? 9 - j : j);
			id[i][p] = ++tot; 
		}
	}
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			to[id[i][j]] = id[i - a[i][j]][j];
		}
	}
	for(int i = 2; i <= 10 * 10; ++i) {
		double d = 0;
		dp[i] = 6;
		for(int j = 1; j <= 6; ++j) {
			if(i - j > 0) {
				d += 1.0;
				dp[i] += min(dp[i - j], dp[to[i - j]]);
			}
		}
		dp[i] = dp[i] / d;
//		dp[i] = min(dp[i], dp[to[i]]);
	}
	printf("%.10f\n", dp[10 * 10]);
	return 0;
}
