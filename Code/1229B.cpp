#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5, P = 1e9 + 7;
int n;
ll ans;
unordered_map<ll, ll> dp[maxn];
ll x[maxn];
vector<int> G[maxn];
ll dfs(int u, int f, ll g) {
	if(dp[u].find(g) != dp[u].end()) {
		return dp[u][g];
	}
	dp[u][g] = (dp[u][g] + g) % P;
	for(auto v : G[u]) {
		if(v != f) {
			dp[u][g] = (dp[u][g] + dfs(v, u, __gcd(g, x[v]))) % P;
		}
	}
	return dp[u][g];
}
void dfs(int u, int f) {
	for(auto v : G[u]) {
		if(v != f) {
			dfs(v, u);
		}
	}
	ans = (ans + dfs(u, f, x[u])) % P;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &x[i]);
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	ans = 0;
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
