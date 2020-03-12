#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int q, x;
int mn[maxn * 4], cnt[maxn * 4], a[maxn];
void update(int l, int r, int x, int p) {
	if(l == r) {
		++cnt[l];
		return;
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		update(l, mid, x << 1, p);
	} else {
		update(mid + 1, r, x << 1 | 1, p);
	}
	mn[x] = cnt[mn[x << 1]] <= cnt[mn[x << 1 | 1]] ? mn[x << 1] : mn[x << 1 | 1];
}
void build(int l, int r, int x) {
	if(l == r) {
		mn[x] = l;
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, x << 1);
	build(mid + 1, r, x << 1 | 1);
	mn[x] = l;
}
int main() {
	scanf("%d%d", &q, &x);
	build(0, x - 1, 1);
	while(q--) {
		int v;
		scanf("%d", &v);
		v %= x;
		++a[v];
		update(0, x - 1, 1, v);
		printf("%d\n", a[mn[1]] * x + mn[1]);
	}
	return 0;
}
