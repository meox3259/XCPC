#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, a, b, ca, cb;
int vis[maxn];
vector<int> G[maxn];
void dfs_1(int u) {
	if(vis[u]) {
		return;
	}
	vis[u] = 1;
	++ca;
	for(auto v : G[u]) {
		dfs_1(v);
	}
} 
void dfs_2(int u) {
	if(vis[u]) {
		return;
	}
	vis[u] = 1;
	++cb;
	for(auto v : G[u]) {
		dfs_2(v);
	}
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ca = cb = 0;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
		}
		for(int i = 1; i <= m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 1; i <= n; ++i) {
			vis[i] = 0;
		}
		vis[b] = 1; 
		dfs_1(a);
		for(int i = 1; i <= n; ++i) {
			vis[i] = 0;
		}
		vis[a] = 1;
		dfs_2(b);
		printf("%lld\n", 1LL * (n - ca - 1) * (n - cb - 1));
	}
	return 0;
}
