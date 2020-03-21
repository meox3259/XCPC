#include <bits/stdc++.h>

using namespace std;

class segment_tree {
	public:
		vector<long long> t;
		
		segment_tree(int n) {
			t.resize(4 * n + 5);
		}

		void build(int l, int r, int x, vector<int>& a) {
			if(l == r) {
				t[x] = a[l];
				return;
			}

			int mid = l + r >> 1;

			build(l, mid, x << 1, a);
			build(mid + 1, r, x << 1 | 1, a);
		}

		void pushdown(int x) {
			t[x << 1] += t[x];
			t[x << 1 | 1] += t[x];
			t[x] = 0;
		}

		void update(int l, int r, int x, int a, int b, int k) {
			if(l > b || r < a) {
				return;
			}

			if(l >= a && r <= b) {
				t[x] += k;
				return;
			}

			pushdown(x);

			int mid = l + r >> 1;
		
			update(l, mid, x << 1, a, b, k);
			update(mid + 1, r, x << 1 | 1, a, b, k);
		}

		long long query(int l, int r, int x, int p) {
			if(l == r) {
				return t[x];
			}

			pushdown(x);

			int mid = l + r >> 1;

			if(p <= mid) {
				return query(l, mid, x << 1, p);
			} else {
				return query(mid + 1, r, x << 1 | 1, p);
			}
		}
};

class fenwick {
	vector<long long> t;

	public:
		
		fenwick(int n) {
			t.resize(n + 1);
		}

		void add(int p, long long d) {
			for(; p < (int)t.size(); p += p & -p) {
				t[p] += d;
			}
		} 

		long long query(int p) {
			long long ret = 0;

			for(; p; p -= p & -p) {
				ret += t[p];
			}

			return ret;
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;

		vector<int> a;
		a.resize(n + 1);

		for(int i = 0; i < n; ++i) {
			cin >> a[i + 1];
		}

		segment_tree t(n);

		t.build(1, n, 1, a);

		fenwick fenwick(n);

		for(int i = 0; i < n; ++i) {
			fenwick.add(i + 1, max(0, a[i + 1] - a[i]));
		}

		while(m--) {
			int x, l, r;
			cin >> x >> l >> r;
	
			if(x == 1) {
				int k;
				cin >> k;

				t.update(1, n, 1, l, r, k);			
				
				if(r < n) {
					long long u = t.query(1, n, 1, r);
					long long v = t.query(1, n, 1, r + 1);

					long long last = max(0LL, v + k - u);

					fenwick.add(r + 1, -last);
					fenwick.add(r + 1, max(0LL, v - u));
				}

				if(l > 1) {
					long long u = t.query(1, n, 1, l - 1);
					long long v = t.query(1, n, 1, l);

					long long last = max(0LL, v - k - u);

					fenwick.add(l, -last);
					fenwick.add(l, max(0LL, v - u));
				}
			}

			if(x == 2) {
				long long ans = 0;

				ans += fenwick.query(r) - fenwick.query(l);
				ans += t.query(1, n, 1, l);

				cout << ans << '\n';
			}
		}
	}
	return 0;
}

