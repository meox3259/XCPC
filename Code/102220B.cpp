#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
	vector<long long> t;

	void pushdown(int x) {
		t[x << 1] += t[x];
		t[x << 1 | 1] += t[x];
		
		t[x] = 0;
	}

	public:
		
		segment_tree(int n) {
			t.resize(4 * n + 5);
		}

		void update(int l, int r, int x, int a, int b, long long d) {
			if(l > b || r < a) {
				return;
			}

			if(l >= a && r <= b) {
				t[x] += d;
				return;
			}

			pushdown(x);

			int mid = l + r >> 1;

			update(l, mid, x << 1, a, b, d);
			update(mid + 1, r, x << 1 | 1, a, b, d);
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;

		vector<int> l;
		l.resize(m);

		for(int i = 0; i < m; ++i) {
			cin >> l[i];
		}

		vector<vector<int> > c;
		c.resize(m);

		for(int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;

			--b;

			c[b].emplace_back(a);
		}

		int sz = 0;

		for(int i = 0; i < m; ++i) {
			sz = max(sz, (int)c[i].size() + 1);
		}

		for(int i = 0; i < m; ++i) {
			sort(c[i].begin(), c[i].end(), greater<int> ());
		}

		segment_tree t(n);

		for(int i = 0; i < m; ++i) {
			long long tot = 0;
			for(int j = 0; j < c[i].size(); ++j) {
				tot += c[i][j];

				if(j + 1 >= l[i]) {
					t.update(1, sz, 1, j + 1, j + 1, tot);
				}
			}

			if(c[i].size() >= l[i]) {
				t.update(1, sz, 1, c[i].size() + 1, sz, tot);
			}
		}

		long long ansx = 0;
		long long ansy = 1;

		for(int i = 1; i < sz; ++i) {

			long long sum = t.query(1, sz, 1, i);

			if(sum * ansy > ansx * i) {
				ansx = sum;
				ansy = i;
			}
		}

		long long d = __gcd(ansx, ansy);

		cout << ansx / d << '/' << ansy / d << '\n';
	}
	return 0;
}
