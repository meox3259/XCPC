#include <bits/stdc++.h>

using namespace std;

int sum[4000005];

void update(int l, int r, int x, int p, int v) {
	sum[x] += v;
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		update(l, mid, x << 1, p, v);
	} else {
		update(mid + 1, r, x << 1 | 1, p, v);
	}
}

int query(int l, int r, int x, int k) {
	if(l == r) {
		return l;
	}
	int mid = l + r >> 1;
	if(sum[x << 1] >= k) {
		return query(l, mid, x << 1, k);
	} else {
		return query(mid + 1, r, x << 1 | 1, k - sum[x << 1]);
	}
}

void dfs(int l, int r, int x) {
	if(sum[x] == 0) {
		return;
	}
	if(l == r) {
		cout << l << '\n';
		exit(0);
	}
	int mid = l + r >> 1;
	dfs(l, mid, x << 1);
	dfs(mid + 1, r, x << 1 | 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		update(1, n, 1, a, 1);
	}

	for(int i = 0; i < q; ++i) {
		int k;
		cin >> k;
		if(1 <= k && k <= n) {
			update(1, n, 1, k, 1);
		} else {
			k = -k;
			int v = query(1, n, 1, k);
			update(1, n, 1, v, -1);
		}
	}

	if(sum[1] == 0) {
		cout << 0 << '\n';
	} else {
		dfs(1, n, 1);
	}

	return 0;
}
