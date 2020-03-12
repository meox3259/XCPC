#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 22;
int n, m;
int dp[maxn], d[30][30], sum[maxn];
char s[maxn];
int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 2; i <= n; ++i) {
		++d[s[i] - 'a'][s[i - 1] - 'a'];
		++d[s[i - 1] - 'a'][s[i] - 'a'];
	}
	for(int i = 0; i < m; ++i) {
		d[i][i] = 0;
	}
	memset(dp, 0x3f3f, sizeof(dp));
	dp[0] = 0;
	for(int S = 1; S < 1 << m; ++S) {
		int p = S & (-S);
		for(int i = 0; i < m; ++i) {
			if((1 << i) == p) {
				p = i;
				break;
			}
		}
		for(int i = 0; i < m; ++i) {
			if(S >> i & 1) {
				sum[S] -= d[p][i];
			} else {
				sum[S] += d[p][i];
			}
		}
		sum[S] += sum[S ^ (1 << p)];
		for(int i = 0; i < m; ++i) {
			if(S >> i & 1) {
				dp[S] = min(dp[S], dp[S ^ (1 << i)] + sum[S]);
			}
		}
	}
	printf("%d\n", dp[(1 << m) - 1]);
	return 0;
}
