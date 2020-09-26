#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int N = 200005;

long long ten[N];
long long pre[N];
long long sum[N * 4];
long long tag[N * 4];

void build(int l, int r, int x) {
	if(l == r) {
		sum[x] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, x << 1);
	build(mid + 1, r, x << 1 | 1);
	sum[x] = (sum[x << 1] * ten[r - mid] + sum[x << 1 | 1]) % P;
}

void pushdown(int x, int l, int r) {
	int mid = l + r >> 1;
	if(tag[x] != 0) {
		tag[x << 1] = tag[x];
		tag[x << 1 | 1] = tag[x];
		sum[x << 1] = pre[mid - l] * tag[x] % P;
		sum[x << 1 | 1] = pre[r - mid - 1] * tag[x] % P;
		tag[x] = 0;
	}
}

void update(int l, int r, int x, int a, int b, int d) {
	if(l > b || r < a) {
		return;
	}
	if(l >= a && r <= b) {
		tag[x] = d;
		sum[x] = pre[r - l] * d % P; 
		return;
	}
	pushdown(x, l, r);
	int mid = l + r >> 1;
	update(l, mid, x << 1, a, b, d);
	update(mid + 1, r, x << 1 | 1, a, b, d);
	sum[x] = (sum[x << 1] * ten[r - mid] + sum[x << 1 | 1]) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	ten[0] = 1;
	for(int i = 0; i < n; ++i) {
		ten[i + 1] = ten[i] * 10 % P;
	}
	pre[0] = ten[0];
	for(int i = 0; i < n; ++i) {
		pre[i + 1] = (pre[i] + ten[i + 1]) % P; 
	}

	build(1, n, 1);

	while(q--) {
		int l, r, d;
		cin >> l >> r >> d;
		update(1, n, 1, l, r, d);
		cout << sum[1] << '\n';
	}

	return 0;
}
