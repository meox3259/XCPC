#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
int n;
int dp[maxn], val[maxn], cost[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int E, F;
		scanf("%d%d%d", &E, &F, &n);
		int m = F - E;
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &val[i], &cost[i]);
		}
		for(int i = 1; i <= m; ++i) {
			dp[i] = 1e9;
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = cost[i]; j <= m; ++j) {
				dp[j] = min(dp[j], dp[j - cost[i]] + val[i]);
			}
		}
		if(dp[m] == 1e9) {
			puts("This is impossible.");
		} else {
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
		}
	}
	return 0;
}
