#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
int n, k;
ll dp[maxn][2];
vector<pair<int, int> > G[maxn];
void dfs(int u, int f) {
	vector<ll> vec;
	for(auto [v, w] : G[u]) {
		if(v != f) {
			dfs(v, u);
			dp[v][1] += w;
			dp[u][1] += dp[v][0];
			if(dp[v][1] > dp[v][0]) {
				vec.push_back(dp[v][1] - dp[v][0]);
			}
		}
	}
	sort(vec.begin(), vec.end(), greater<ll>());
	for(int i = 0; i < min(k - 1, (int)vec.size()); ++i) {
		dp[u][1] += vec[i];
	}
	dp[u][0] = dp[u][1];
	if(vec.size() >= k) {
		dp[u][0] += vec[k - 1];
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i) {
			dp[i][0] = dp[i][1] = 0;
			G[i].clear();
		}
		for(int i = 1; i < n; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].emplace_back(v, w);
			G[v].emplace_back(u, w);
		}
		dfs(1, 0);
		// dp[u][0 / 1] : the maximum value that whether we leave an edge for node u's father or not 
		printf("%lld\n", dp[1][0]);
	}
	return 0;
}
