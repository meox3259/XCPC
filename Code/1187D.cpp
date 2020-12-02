#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

class SegmentTree {
	vector<int> t;
	int N;

	public:
	SegmentTree() {}
	SegmentTree(int _N) : N(_N) {
		t.assign(4 * N + 5, -inf);
	}

	void update(int l, int r, int x, int p, int v) {
		if (l == r) {
			t[x] = v;
			return;
		}

		int mid = l + r >> 1;
		if (p <= mid) {
			update(l, mid, x << 1, p, v);
		} else {
			update(mid + 1, r, x << 1 | 1, p, v);
		}

		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}

	int query(int l, int r, int x, int a, int b) {
		if (l > b || r < a) {
			return -inf;
		}
		if (l >= a && r <= b) {
			return t[x];
		}

		int mid = l + r >> 1;
		return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
		}

		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			--b[i];
		}

		vector<int> ta(a);
		sort(ta.begin(), ta.end());

		vector<int> tb(b);
		sort(tb.begin(), tb.end());

		if (ta != tb) {
			cout << "NO" << '\n';
			continue;
		}
		
		SegmentTree seg(n);
		vector<vector<int> > pos(n);
		for (int i = 0; i < n; ++i) {
			pos[a[i]].emplace_back(i);
			seg.update(0, n - 1, 1, i, a[i]);
		}

		bool ok = true;
		for (int i = n - 1; i >= 0; --i) {
			int p = pos[b[i]].back();
			pos[b[i]].pop_back();
			if (seg.query(0, n - 1, 1, p, n) > b[i]) {
				ok = false;
				break;
			}
			seg.update(0, n - 1, 1, p, -inf);
		}

		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
