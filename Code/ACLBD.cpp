#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
const int inf = 1000000000;

int mx[N * 4];

void update(int l, int r, int x, int p, int v) {
	if(l == r) {
		mx[x] = v;
		return;
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		update(l, mid, x << 1, p, v);
	} else {
		update(mid + 1, r, x << 1 | 1, p, v);
	}
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}

int query(int l, int r, int x, int a, int b) {
	if(l > b || r < a) {
		return -inf;
	}
	if(l >= a && r <= b) {
		return mx[x];
	}
	int mid = l + r >> 1;
	return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	memset(mx, -0x3f3f, sizeof(mx));

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for(int i = 0; i < n; ++i) {
		int x = query(0, N - 1, 1, max(a[i] - k, 0), min(a[i] + k, N - 1));
		x = max(x, 0) + 1;
		update(0, N - 1, 1, a[i], x);
	}

	cout << mx[1] << '\n';

	return 0;
}
