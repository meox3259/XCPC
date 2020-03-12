#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 5, se = 19992147;
int n, l, m, cnt, id;
int ans[1005], mx[maxn], lc[maxn], rc[maxn], sz[maxn], root[maxn];
ll h[1005];
char s[1005][105];
map<ll, int> mp;
ll H(char *s) {
	ll ret = 0;
	for(int i = 1; i <= l; ++i) {
		ret = ret * se + s[i] - 'a';
	}
	return ret;
}
void pushdown(int x) {
	if(lc[x]) {
		mx[lc[x]] = max(mx[lc[x]], mx[x]);
	}
	if(rc[x]) {
		mx[rc[x]] = max(mx[rc[x]], mx[x]);
	}
	mx[x] = 0;
}
void add(int l, int r, int &x, int p) {
	if(!x) {
		x = ++cnt;
	}
	++sz[x];
	if(l == r) {
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	if(p <= mid) {
		add(l, mid, lc[x], p);
	} else {
		add(mid + 1, r, rc[x], p);
	}
}
void del(int l, int r, int &x, int p) {
	--sz[x];
	if(l == r) {
		ans[p] = max(ans[p], mx[x]); 
		if(!sz[x]) {
			x = 0;
		}
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	if(p <= mid) {
		del(l, mid, lc[x], p);
	} else {
		del(mid + 1, r, rc[x], p);
	}
	if(!sz[x]) {
		x = 0;
	}
}
void dfs(int l, int r, int x) {
	if(!x) {
		return;
	}
	if(l == r) {
		ans[l] = max(ans[l], mx[x]);
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	dfs(l, mid, lc[x]);
	dfs(mid + 1, r, rc[x]);
}
int main() {
	scanf("%d%d%d", &n, &l, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		h[i] = H(s[i]);
		if(!mp.count(h[i])) {
			mp[h[i]] = ++id;
		}
		add(1, n, root[mp[h[i]]], i);
		mx[root[mp[h[i]]]] = max(mx[root[mp[h[i]]]], sz[root[mp[h[i]]]]);
	}
	while(m--) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		swap(s[a][b], s[c][d]);
		if(a == c) {
			del(1, n, root[mp[h[a]]], a);
			h[a] = H(s[a]);
			if(!mp.count(h[a])) {
				mp[h[a]] = ++id;
			}
			add(1, n, root[mp[h[a]]], a);
			mx[root[mp[h[a]]]] = max(mx[root[mp[h[a]]]], sz[root[mp[h[a]]]]);
		} else {
			int t;
			del(1, n, root[mp[h[a]]], a);
			del(1, n, root[mp[h[c]]], c);
			h[a] = H(s[a]);
			if(!mp.count(h[a])) {
				mp[h[a]] = ++id;
			}
			add(1, n, root[mp[h[a]]], a);
			h[c] = H(s[c]);
			if(!mp.count(h[c])) {
				mp[h[c]] = ++id;
			}
			add(1, n, root[mp[h[c]]], c);
			t = root[mp[h[a]]];
			mx[t] = max(mx[t], sz[t]);
			t = root[mp[h[c]]];
			mx[t] = max(mx[t], sz[t]);
		}
	}
	for(int i = 1; i <= id; ++i) {
		dfs(1, n, root[i]);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
