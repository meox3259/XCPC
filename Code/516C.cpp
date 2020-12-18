#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

class SegmentTree {
	vector<vector<long long> > mx;
	public:
	SegmentTree() {}
	SegmentTree(int N) : mx(N * 4 + 5, vector<long long> (3, -inf)) {}

	void update(int l, int r, int x, int p, long long v1, long long v2) {
		if (l == r) {
			mx[x] = { v1, v2, -inf };
			return;
		}
		int mid = l + r >> 1;
		if (p <= mid) {
			update(l, mid, x << 1, p, v1, v2);
		} else {
			update(mid + 1, r, x << 1 | 1, p, v1, v2);
		}
		mx[x][0] = max(mx[x << 1][0], mx[x << 1 | 1][0]);
		mx[x][1] = max(mx[x << 1][1], mx[x << 1 | 1][1]);
		mx[x][2] = max(max(mx[x << 1][2], mx[x << 1 | 1][2]), max(mx[x << 1][0] + mx[x << 1 | 1][1], mx[x << 1][1] + mx[x << 1 | 1][0]));
	}

	vector<long long> query(int l, int r, int x, int a, int b) {
		if (l > b || r < a) {
			return (vector<long long>){ -inf, -inf, -inf };
		}
		if (l >= a && r <= b) {
			return mx[x];
		}
		int mid = l + r >> 1;
		auto L = query(l, mid, x << 1, a, b);
		auto R = query(mid + 1, r, x << 1 | 1, a, b);
		return { max(L[0], R[0]), max(L[1], R[1]), max(max(L[2], R[2]), max(L[0] + R[1], L[1] + R[0])) };
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<long long> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	vector<long long> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	SegmentTree t(n + n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		t.update(0, n + n - 1, 1, i, h[i] + h[i] + sum, h[i] + h[i] - sum);
		sum += d[i];
	}

	for (int i = 0; i < n; ++i) {
		t.update(0, n + n - 1, 1, i + n, h[i] + h[i] + sum, h[i] + h[i] - sum);
		sum += d[i];
	}

	while (m --) {
		int a, b;
		cin >> a >> b;
		a --;
		b --;

		if (a <= b) {
			auto o = t.query(0, n + n - 1, 1, b + 1, a - 1 + n);
			cout << o[2] << '\n';
		} else {
			auto o = t.query(0, n + n - 1, 1, b + 1, a - 1);
			cout << o[2] << '\n';
		}
	}

	return 0;
}
