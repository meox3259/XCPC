#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, w, h;
int t[maxn], d[maxn], x[maxn], y[maxn], p[maxn], L[maxn], R[maxn], U[maxn], D[maxn], vis[maxn];
vector<int> G[maxn];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
set<pair<int, int> > s[maxn * 2];
void update(int l, int r, int x, int p,  int id) {
	s[x].insert(make_pair(y[id], id));
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		update(l, mid, x << 1, p, id);
	} else {
		update(mid + 1, r, x << 1 | 1, p, id);
	}
}
void del(int l, int r, int x, int id, int val) {
	if(l > R[id] || r < L[id]) {
		return;
	}
	if(l >= L[id] && r <= R[id]) {
		set<pair<int, int> > :: iterator it = s[x].lower_bound(make_pair(D[id], 0)), tmp;
		while((it != s[x].end()) && (it -> first <= U[id])) {
			int u = it -> second;
			if(!vis[u]) {
				vis[u] = 1;
				d[u] = val;
				for(int i = 0; i < G[u].size(); ++i) {
					q.push(make_pair(d[u] + t[G[u][i]], G[u][i]));
				}
			}
			tmp = it;
			++it;
			s[x].erase(tmp);
		}
		return;
	}
	int mid = l + r >> 1;
	del(l, mid, x << 1, id, val);
	del(mid + 1, r, x << 1 | 1, id, val);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &w, &h);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		update(1, w, 1, x[i], i);
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d%d%d%d", &p[i], &t[i], &L[i], &R[i], &D[i], &U[i]);
		--p[i];
		G[p[i]].push_back(i);
	}
	for(int i = 0; i < G[0].size(); ++i) {
		q.push(make_pair(t[G[0][i]], G[0][i]));
	}
	while(!q.empty()) {
		pair<int, int> o = q.top();
		q.pop();
		del(1, w, 1, o.second, o.first);
	}
	for(int i = 1; i < n; ++i) {
		printf("%d\n", d[i]);
	}
	return 0;
}
