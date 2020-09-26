#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

class SegmentTree {
	vector<vector<vector<long long> > > f;
	public:

	SegmentTree() {}
	SegmentTree(int N) : f(N * 4 + 5, vector<vector<long long> > (2, vector<long long> (2, -inf))) {};

	void merge(int x) {
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				f[x][i][j] = max(f[x << 1][i][j], f[x << 1 | 1][i][j]);
			}
		}
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				for(int k = 0; k < 2; ++k) {
					f[x][i][k] = max(f[x][i][k], f[x << 1][i][j] + f[x << 1 | 1][j ^ 1][k]);
				}
			}
		}
	}

	void build(int l, int r, int x, const vector<long long> &a) {
		if(l == r) {
			f[x][0][0] = a[l];
			f[x][1][1] = -a[l];
			return;
		}

		int mid = l + r >> 1;
		build(l, mid, x << 1, a);
		build(mid + 1, r, x << 1 | 1, a);

		merge(x);
	}

	void update(int l, int r, int x, int p, long long v) {
		if(l == r) {
			f[x][0][0] = v;
			f[x][1][1] = -v;
			return;
		}

		int mid = l + r >> 1;
		if(p <= mid) {
			update(l, mid, x << 1, p, v);
		} else {
			update(mid + 1, r, x << 1 | 1, p, v);
		}

		merge(x);
	}

	long long out() {
		return max(max(f[1][0][0], f[1][0][1]), max(f[1][1][0], f[1][1][1]));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, q;
		cin >> n >> q;
	
		vector<long long> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		SegmentTree seg(n);
		seg.build(0, n - 1, 1, a);

		cout << seg.out() << '\n';

		while(q--) {
			int l, r;
			cin >> l >> r;
			--l; --r;
			seg.update(0, n - 1, 1, l, a[r]);
			seg.update(0, n - 1, 1, r, a[l]);
			swap(a[l], a[r]);

			cout << seg.out() << '\n';
		}
	}

	return 0;
}
