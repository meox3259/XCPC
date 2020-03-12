#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, ans;
vector<int> G[maxn];
int dp[maxn];
void dfs(int u, int f) {
	int tot = 0, mx1 = 0, mx2 = 0, c = 0;
	for(auto v : G[u]) {
		if(v != f) {
			dfs(v, u);
			if(dp[v] >= mx1) {
				mx2 = mx1;
				mx1 = dp[v];
			} else if(dp[v] > mx2) {
				mx2 = dp[v];
			}
			++c;
		}
	}
	int d = G[u].size();
	if(c > 1) {
		ans = max(ans, mx1 + mx2 + d - 1);
		dp[u] = mx1 + c;
	} else if(c == 1) {
		ans = max(ans, mx1 + d);
		dp[u] = mx1 + 1;
	} else {
		dp[u] = 1;
		ans = max(ans, 1);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			dp[i] = 0;
		}
		for(int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
