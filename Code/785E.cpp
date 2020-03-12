#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
int n, q, Pool;
ll ans;
int root[maxn], sz[maxn * 100], lc[maxn * 100], rc[maxn * 100], a[maxn];
void update(int l, int r, int &x, int p, int d) {
	if(!x) {
		x = ++Pool;
	}
	sz[x] += d;
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		update(l, mid, lc[x], p, d);
	} else {
		update(mid + 1, r, rc[x], p, d);
	}
}
int query(int l, int r, int x, int a, int b) {
	if(!x || l > b || r < a) {
		return 0;
	}
	if(l >= a && r <= b) {
		return sz[x];
	}
	int mid = l + r >> 1;
	return query(l, mid, lc[x], a, b) + query(mid + 1, r, rc[x], a, b);
}
void add(int p, int val, int d) {
	for(; p <= n; p += p & -p) {
		update(1, n, root[p], val, d);
	}
}
int ask(int p, int l, int r) {
	int ret = 0;
	for(; p; p -= p & -p) {
		ret += query(1, n, root[p], l, r);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		a[i] = i;
		add(i, i, 1);
	}
	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		if(l == r) {
			printf("%lld\n", ans);
			continue;
		}
		ans -= ask(r, 1, a[l]) - ask(l, 1, a[l]) + ask(r, a[r], n) - ask(l, a[r], n);
		add(r, a[r], -1);
		add(l, a[l], -1);
		add(l, a[r], 1);
		add(r, a[l], 1);
		swap(a[l], a[r]);
		ans += ask(r, 1, a[l]) - ask(l, 1, a[l]) + ask(r, a[r], n) - ask(l, a[r], n);
		printf("%lld\n", ans);
	}
	return 0;
}
