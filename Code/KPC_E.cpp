#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, inf = 1e9;
int n, m;
int d[maxn], a[maxn], b[maxn], c[maxn];
map<pair<int, int>, int> mp;
vector<int> G[maxn];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; ++i) {
		v.emplace_back(d[i], i);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); ++i) {
		int u = v[i].second;
		int p = 0;
		if(c[u]) {
			continue;
		}
		for(auto v : G[u]) {
			if(d[v] <= d[u]) {
				p = v;
				break;
			}
		}
		if(!p) {
			puts("-1");
			return 0;
		}
		if(!c[p]) {
			c[p] = 1;
		}	
		c[u] = -c[p];
		mp[minmax(u, p)] = d[u];
	}
	for(int i = 1; i <= n; ++i) {
		putchar(c[i] == 1 ? 'B' : 'W');
	}
	puts("");
	for(int i = 1; i <= m; ++i) {
		printf("%d\n", mp.count(minmax(a[i], b[i])) ? mp[minmax(a[i], b[i])] : inf);
	}
	return 0;
}
