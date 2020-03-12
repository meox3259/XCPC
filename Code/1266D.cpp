#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
struct node {
	int u, v;
	ll w;
	node() = default;
	node(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
};
int n, m;
ll d[maxn];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		d[u] -= w;
		d[v] += w;
	}
	vector<node> ans;
	for(int i = 1, j = 1; i <= n; ++i) {
		while(d[i] > 0) {
			while(j <= n && d[j] >= 0) {
				++j;
			}
			ll delta = min(d[i], -d[j]);
			d[i] -= delta;
			d[j] += delta;
			ans.push_back(node(j, i, delta));
		}
	}
	printf("%d\n", ans.size());
	for(auto x : ans) {
		printf("%d %d %lld\n", x.u, x.v, x.w);
	}
	return 0;
}
