#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

class SegmentTree {
	vector<long long> mn;

	public:
	SegmentTree() {}
	SegmentTree(int N) : mn(N * 4 + 5, inf) {}

	void update(int l, int r, int x, int p, long long v) {
		if (l == r) {
			mn[x] = v;
			return;
		}

		int mid = l + r >> 1;
		if (p <= mid) {
			update(l, mid, x << 1, p, v);
		} else {
			update(mid + 1, r, x << 1 | 1, p, v);
		}

		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}

	long long query(int l, int r, int x, int a, int b) {
		if (l > b || r < a) {
			return inf;
		}
		if (l >= a && r <= b) {
			return mn[x];
		}
		int mid = l + r >> 1;
		return min(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<long long> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		
		auto solve = [&] (vector<long long> a) {
			SegmentTree to(n);
			SegmentTree te(n);
			long long odd = 0;
			long long even = 0;
			long long sum = 0;
			for (int i = 0; i < n; ++i) {
				if (i & 1) {
					odd += a[i];
					to.update(0, n - 1, 1, i, odd - even);
				} else {
					even += a[i];
					te.update(0, n - 1, 1, i, even - odd);
				}
			}

			if (n & 1) {
				sum = even - odd;
			} else {
				sum = odd - even;
			}

			bool ok = false;

			if (to.query(0, n - 1, 1, 0, n - 1) >= 0 && te.query(0, n - 1, 1, 0, n - 1) >= 0 && sum == 0) {
				ok = true;
			}

			for (int i = 0; i < n - 1; ++i) {
				bool flag = true;
				if (n & 1) {
					if (i & 1) {
						if (sum + a[i] * 2 - a[i + 1] * 2 != 0) {
							flag = false;
						}	
					} else {
						if (sum - a[i] * 2 + a[i + 1] * 2 != 0) {
							flag = false;
						}
					}
				} else {
					if (i & 1) {
						if (sum - a[i] * 2 + a[i + 1] * 2 != 0) {
							flag = false;
						}
					} else {
						if (sum + a[i] * 2 - a[i + 1] * 2 != 0) {
							flag = false;
						}
					}
				}

				if (to.query(0, n - 1, 1, 0, i - 1) < 0 || te.query(0, n - 1, 1, 0, i - 1) < 0) {
					flag = false;
				}

				if (i & 1) {
					if (to.query(0, n - 1, 1, i, i) < (a[i] - a[i + 1])) {
						flag = false;
					}	
					if (to.query(0, n - 1, 1, i, n - 1) < (a[i] * 2 - a[i + 1] * 2)) {
						flag = false;
					}
					if (te.query(0, n - 1, 1, i, n - 1) < (a[i + 1] * 2 - a[i] * 2)) {
						flag = false;
					}
				} else {
					if (te.query(0, n - 1, 1, i, i) < (a[i] - a[i + 1])) {
						flag = false;
					}	
					if (te.query(0, n - 1, 1, i, n - 1) < (a[i] * 2 - a[i + 1] * 2)) {
						flag = false;
					}
					if (to.query(0, n - 1, 1, i, n - 1) < (a[i + 1] * 2 - a[i] * 2)) {
						flag = false;
					}
				}

				if (flag) {
					ok = true;
				}
			}

			return ok;
		};

		bool ok = false;
		if (solve(a)) {
			ok = true;
		}

		reverse(a.begin(), a.end());

		if (solve(a)) {
			ok = true;
		}

		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
