#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, k;
int x[maxn], y[maxn], ans[maxn];
set<int> s, G[maxn];
void del(int u) {
	if(G[u].size() < k && s.erase(u)) 
		for(auto v : G[u]) {
			G[v].erase(u);
			del(v);
		}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		G[x[i]].insert(y[i]);
		G[y[i]].insert(x[i]);
	}
	for(int i = 1; i <= n; ++i) s.insert(i);
	for(int i = 1; i <= n; ++i) del(i);
	for(int i = m; i; --i) {
		ans[i] = s.size();
		G[x[i]].erase(y[i]);
		G[y[i]].erase(x[i]);
		del(x[i]);
		del(y[i]);
	}
	for(int i = 1; i <= m; ++i) 
		printf("%d\n", ans[i]);
	return 0;
}
