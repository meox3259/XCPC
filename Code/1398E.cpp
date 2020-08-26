#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000001;

class SegmentTree {
	private:
	vector<int> sz;
	vector<long long> sum;
	vector<int> lc;
	vector<int> rc;
	int Pool;

	public:
	SegmentTree(int N) : sz(N * 30), sum(N * 30), lc(N * 30), rc(N * 30) { Pool = 0; }

	void update(int l, int r, int &x, int p, int v) {
		if(x == 0) {
			x = ++Pool;
		}
		sz[x] += v;
		sum[x] += p * v;

		if(l == r) {
			return;
		}

		int mid = l + r >> 1;
		if(p <= mid) {
			update(l, mid, lc[x], p, v);
		} else {
			update(mid + 1, r, rc[x], p, v);
		}
	}

	long long query(int l, int r, int x, int k) {
		if(l == r) {
			return 1LL * min(k, sz[x]) * l;
		}

		int mid = l + r >> 1;
		if(sz[rc[x]] >= k) {
			return query(mid + 1, r, rc[x], k);
		} else {
			return sum[rc[x]] + query(l, mid, lc[x], k - sz[rc[x]]);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int light = 0;
	int root = 0;
	long long ans = 0;
	SegmentTree seg(n);
	multiset<int> big;
	for(int i = 0; i < n; ++i) {
		int type, d;
		cin >> type >> d;

		ans += d;

		if(type == 0) {
			if(d > 0) {
				seg.update(0, inf, root, d, 1);
			} else {
				seg.update(0, inf, root, -d, -1);
			}
		}

		if(type == 1) {
			if(d > 0) {
				light += 1;
				seg.update(0, inf, root, d, 1);
				if(!big.empty()) {
					seg.update(0, inf, root, *big.begin(), 1);	
				}
				big.emplace(d);
				seg.update(0, inf, root, *big.begin(), -1);
			} else {
				d = -d;
				light -= 1;
				seg.update(0, inf, root, d, -1);
				seg.update(0, inf, root, *big.begin(), 1);
				big.erase(big.find(d));
				if(!big.empty()) {
					seg.update(0, inf, root, *big.begin(), -1);
				}
			}
		}

		cout << ans + seg.query(0, inf, root, light) << '\n';
	}

	return 0;
}
