#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, sum;
int tag[maxn * 4], mn[maxn * 4], mx[maxn * 4], vis[maxn];
char s[maxn], t[maxn];
void pushdown(int x) {
	tag[x << 1] += tag[x];
	tag[x << 1 | 1] += tag[x];
	mn[x << 1] += tag[x];
	mn[x << 1 | 1] += tag[x];
	mx[x << 1] += tag[x];
	mx[x << 1 | 1] += tag[x];
	tag[x] = 0;
}
void update(int l, int r, int x, int a, int b, int d) {
	if(l > b || r < a) return;
	if(l >= a && r <= b) {
		tag[x] += d;
		mn[x] += d;
		mx[x] += d;
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	update(l, mid, x << 1, a, b, d);
	update(mid + 1, r, x << 1 | 1, a, b, d);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
int query(int l, int r, int x, int p) {
	if(p == 0) return 0;
	if(l == r) return mn[x];
	pushdown(x);
	int mid = l + r >> 1;
	if(p <= mid) return query(l, mid, x << 1, p);
	else return query(mid + 1, r, x << 1 | 1, p);
} 
int main() {
	scanf("%d%s", &n, s + 1);
	int p = 1, lim = 1;
	vis[1] = 1;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'R') ++p;
		else if(s[i] == 'L') {
			--p;
			p = max(p, 1);
		} else {
			if(t[p] == '(') update(1, maxn - 1, 1, p, maxn - 1, -1);
			if(t[p] == ')') update(1, maxn - 1, 1, p, maxn - 1, 1);
			if(s[i] == '(') update(1, maxn - 1, 1, p, maxn - 1, 1);
			if(s[i] == ')') update(1, maxn - 1, 1, p, maxn - 1, -1);
			if(t[p] == '(') --sum;
			if(t[p] == ')') ++sum;
			t[p] = s[i];
			if(t[p] == '(') ++sum;
			if(t[p] == ')') --sum;
		}/*
		if(!vis[p]) {
			vis[p] = 1;
			if(p != 1) update(1, maxn - 1, 1, p, p, query(1, maxn - 1, 1, p - 1));
		}
		lim = max(lim, p); */
		if(mn[1] < 0 || sum != 0) printf("-1 ");
		else {
			printf("%d ", mx[1]);	
		}
	}
	return 0;
}
