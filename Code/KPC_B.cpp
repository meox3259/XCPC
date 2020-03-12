#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, inf = 1e9 + 5;
int n, root, Pool;
int mx[maxn * 30], rc[maxn * 30], lc[maxn * 30];
void update(int l, int r, int &x, int p, int d) {
	if(!x) {
		x = ++Pool;
	}
	mx[x] = max(mx[x], d);
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
		return mx[x];
	}
	int mid = l + r >> 1;
	return max(query(l, mid, lc[x], a, b), query(mid + 1, r, rc[x], a, b));
}
int main() {
	scanf("%d", &n);
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; ++i) {
		int x, l;
		scanf("%d%d", &x, &l);
		v.emplace_back(x + l, x - l);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i < v.size(); ++i) {
		int tmp = query(-inf, inf, root, -inf, v[i].second) + 1;
		ans = max(ans, tmp);
		update(-inf, inf, root, v[i].first, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
