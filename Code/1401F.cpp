#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
	private:
	vector<int> lc;
	vector<int> rc;
	vector<long long> sum;
	vector<int> swp;
	vector<int> lev;
	int Pool;

	public:
	vector<int> rev;

	public:
	SegmentTree(int N) : lc(N * 4), rc(N * 4), sum(N * 4), rev(20), swp(N * 4), lev(N * 4) { Pool = 0; }

	void build(int l, int r, int &x, const vector<int> &a) {
		if(x == 0) {
			x = ++Pool;
		}
		if(l == r) {
			sum[x] = a[l];
			lev[x] = 0;
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, lc[x], a);
		build(mid + 1, r, rc[x], a);
		sum[x] = sum[lc[x]] + sum[rc[x]];
		lev[x] = lev[lc[x]] + 1;
	}

	void update(int l, int r, int x, int p, int v) {
		if(l == r) {
			sum[x] = v;
			return;
		}
		int mid = l + r >> 1;
		if(rev[lev[x]] ^ swp[x]) {
			swap(lc[x], rc[x]);
			swp[x] ^= 1;
		}
		if(p <= mid) {
			update(l, mid, lc[x], p, v);
		} else {
			update(mid + 1, r, rc[x], p, v);
		}
		sum[x] = sum[lc[x]] + sum[rc[x]];
	}

	long long query(int l, int r, int x, int a, int b) {
		if(l > b || r < a) {
			return 0;
		}
		if(l >= a && r <= b) {
			return sum[x];
		}
		int mid = l + r >> 1;
		if(rev[lev[x]] ^ swp[x]) {
			swap(lc[x], rc[x]);
			swp[x] ^= 1;
		}
		return query(l, mid, lc[x], a, b) + query(mid + 1, r, rc[x], a, b);
	}

	void dfs(int l, int r, int x) {
		if(l == r) {
	//		cout << sum[x] << ' ';
			return;
		}
		int mid = l + r >> 1;
		if(rev[lev[x]] ^ swp[x]) {
			swap(lc[x], rc[x]);
			swp[x] ^= 1;
		}
		dfs(l, mid, lc[x]);
		dfs(mid + 1, r, rc[x]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	int m = 1 << n;
	vector<int> a(m);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	SegmentTree seg(m);
	int root = 0;
	seg.build(0, m - 1, root, a);
	
	int cur = 0;
	while(q--) {
		int type;
		cin >> type;

		if(type == 1) {
			int x, k;
			cin >> x >> k;
			--x;
			seg.update(0, m - 1, root, x, k);
		}

		if(type == 2) {
			int k;
			cin >> k;
			for(int i = k; i >= 1; --i) {
				seg.rev[i] ^= 1;
			}
		}

		if(type == 3) {
			int k;
			cin >> k;
			seg.rev[k + 1] ^= 1;
		}

		if(type == 4) {
			int l, r;
			cin >> l >> r;
			--l; --r;
			cout << seg.query(0, m - 1, root, l, r) << '\n';
		}

	}

	return 0;
}
