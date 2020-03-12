#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5; 
struct edge {
	int nxt, to, w;
} e[maxn * 2];
int n, k, rt, cnt = 1;
ll G, B;
int h[maxn], d[maxn], sz[maxn];
void link(int u, int v, int w) {
	e[++cnt].nxt = h[u];
	h[u] = cnt;
	e[cnt].to = v;
	e[cnt].w = w;
}
void dfs(int u, int f) {
	sz[u] = 1;
	for(int i = h[u]; i; i = e[i].nxt) {
		if(e[i].to != f) {
			dfs(e[i].to, u);
			sz[u] += sz[e[i].to];
			G += 1LL * e[i].w * min(n - sz[e[i].to], sz[e[i].to]);
			B += (sz[e[i].to] & 1) * e[i].w;
		}
	}
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &k);
		n = 2 * k;
		G = 0;
		B = 0;
		for(int i = 1; i <= n; ++i) {
			h[i] = 0;
		}
		cnt = 1;
		for(int i = 1; i < n; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			link(u, v, w);
			link(v, u, w);
		}
		dfs(1, 0);
		printf("%lld %lld\n", B, G);
	}
	return 0;
}
