#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m;
long long ans;
vector<int> G[maxn];
int fa[maxn], dep[maxn];
long long d[maxn];
map<pair<int, int>, int> mp;
long long dp[maxn][1 << 21];
void dfs(int u, int f) {
	fa[u] = f;
	for(auto v : G[u]) {
		if(v != f) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}
void Dfs(int u, int f) {
	dp[u][0] = 1;
	for(auto v : G[u]) {
		if(v != f) {
			Dfs(v, u);
			for(int S = 0; S < 1 << m; ++S) {
		//		dp[u][S] += dp[v][S] * sum[u][S] + dp[u][S] * sum[v][S];
				int s = S | mp[make_pair(v, u)];
		//		dp[u][S | mp[make_pair(v, u)]] += dp[v][s] * sum[u][s] + ;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		mp[minmax(u, v)] = i - 1;
	}
	dfs(1, 0);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		while(u != v) {
			if(dep[u] < dep[v]) {
				swap(u, v);
			}
			d[i] |= 1LL << mp[minmax(u, fa[u])];
			u = fa[u];
		}
	}
	for(int S = 0; S < 1 << m; ++S) {
		long long e = 0;
		for(int i = 0; i < m; ++i) {
			if(S >> i & 1) {
				e |= d[i];
			}
		}
		int c = 0;
		for(int i = 0; i < n - 1; ++i) {
			if(e & (1LL << i)) {
				++c;
			}
		}
		if((__builtin_popcount(S) & 1) == (m & 1)) {
			ans += ((1LL << c) - 1) * (1LL << (n - c - 1));
		} else {
			ans -= ((1LL << c) - 1) * (1LL << (n - c - 1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
