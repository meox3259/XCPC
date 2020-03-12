#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, m, top;
int a[maxn], l[maxn], r[maxn], vis[maxn], pre[maxn];
struct BIT {
	int t[maxn];
	BIT() { memset(t, 0, sizeof(t)); }
	void add(int p, int d) {
		for(; p < maxn; p += p & -p) {
			t[p] += d;
		}
	}
	int ask(int p) {
		int ret = 0;
		for(; p; p -= p & -p) {
			ret += t[p];
		}
		return ret;
	}
} t1, t2;
struct node {
	int l, r, id;
	node() = default;
	node(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
	bool friend operator < (const node &a, const node &b) {
		return a.r < b.r;
	}
} st[maxn * 10];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		l[i] = i;
		r[i] = i;
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		l[a[i]] = 1;
	}
	for(int i = 1; i <= m; ++i) {
		if(!vis[a[i]]) {
			vis[a[i]] = 1;
			r[a[i]] = max(r[a[i]], a[i] + t1.ask(n) - t1.ask(a[i]));
			t1.add(a[i], 1);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			r[i] = max(r[i], i + t1.ask(n) - t1.ask(i));
		}
	}
	for(int i = 1; i <= m; ++i) {
		if(!pre[a[i]]) {
			pre[a[i]] = i;
		} else {
			st[++top] = node(pre[a[i]], i, a[i]);
			pre[a[i]] = i;
		}
	}
	memset(vis, 0, sizeof(vis));
	for(int i = m; i; --i) {
		if(!vis[a[i]]) {
			vis[a[i]] = 1;
			st[++top] = node(i, m, a[i]);
		}
	}
	memset(pre, 0, sizeof(pre));
	sort(st + 1, st + top + 1);
	int pos = 0;
	for(int i = 1; i <= m; ++i) {
		if(pre[a[i]]) {
			t2.add(pre[a[i]], -1);
		}
		pre[a[i]] = i;
		t2.add(i, 1);
		while(st[pos + 1].r == i && pos < top) {
			++pos;
			r[st[pos].id] = max(r[st[pos].id], t2.ask(st[pos].r) - t2.ask(st[pos].l - 1));
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d %d\n", l[i], r[i]);
	}
	return 0;
}
