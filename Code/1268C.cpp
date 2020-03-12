#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 5;
int n;
int a[maxn], pos[maxn], t[maxn];
ll s[maxn * 4], d[maxn * 4], mn[maxn * 4];
void add(int p, int d) {
	for(; p <= n; p += p & -p) {
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
struct Seg {
    ll a, b;
    Seg() {}
    Seg(ll _a, ll _b) : a(_a), b(_b) {}
    ll c(ll x) { return a * x + b; }
} seg[maxn * 4];
void pushdown(int l, int r, int x, Seg t) {
    int mid = (l + r) >> 1;
    ll A1 = seg[x].c(d[mir[l]]), A2 = t.c(d[mir[l]]), B1 = seg[x].c(d[mir[r]]), B2 = t.c(d[mir[r]]);
    if(!flag[x]) { flag[x] = 1; seg[x] = t; } 
    else if(A1 >= A2 && B1 >= B2) seg[x] = t; 
    else if(A1 <= A2 && B1 <= B2) return;
    else if(t.a < seg[x].a) {
        ll tmp = (t.b - seg[x].b) / (seg[x].a - t.a) + 1;
        if(tmp <= d[mir[mid]]) { pushdown(l, mid, x << 1, seg[x]); seg[x] = t; } 
        else pushdown(mid + 1, r, x << 1 | 1, t);
    } else {
        ll tmp = (seg[x].b - t.b - 1) / (t.a - seg[x].a);
        if(tmp > d[mir[mid]]) { pushdown(mid + 1, r, x << 1 | 1, seg[x]); seg[x] = t;  }
        else pushdown(l, mid, x << 1, t);
    }
    if(l != r) mn[x] = min(mn[x << 1], mn[x << 1 | 1]); 
    mn[x] = min(mn[x], min(seg[x].c(d[mir[l]]), seg[x].c(d[mir[r]])));
}
void update(int l, int r, int x, int a, int b, Seg t) {
    if(l > b || r < a) return;
    if(l >= a && r <= b) {
        pushdown(l, r, x, t);
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, x << 1, a, b, t);
    update(mid + 1, r, x << 1 | 1, a, b, t);
    mn[x] = min(mn[x], min(mn[x << 1], mn[x << 1 | 1]));
    if(flag[x]) mn[x] = min(mn[x], min(seg[x].c(d[mir[l]]), seg[x].c(d[mir[r]])));
}
ll query(int l, int r, int x, int a, int b) {
    if(l > b || r < a) return inf;
    if(l >= a && r <= b) return mn[x];
    int mid = (l + r) >> 1;
    ll ans = inf;
    if(flag[x]) ans = min(seg[x].c(d[mir[max(a, l)]]), seg[x].c(d[mir[min(b, r)]])); 
    return min(ans, min(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b)));
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
		mir[i] = i;
	}
	long long tot = 0;
	for(int i = 1; i <= n; ++i) {
		tot += ask(n) - ask(pos[i]);
		add(pos[i], 1);
		if(pos[i] - i + 1 > 0) {
			update(1, n, 1, 1, pos[i] - i + 1, Seg(pos[i] - i, -1));
		}
		if(pos[i] - i + 1 <= n) {
			update(1, n, 1, pos[i] - i + 1, n, Seg(0, 1));
		}
		printf("%lld ", tot + query(1, n, 1, 1, n - i + 1));
	}
	return 0;
}
