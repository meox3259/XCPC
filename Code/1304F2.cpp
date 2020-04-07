#include <bits/stdc++.h>

using namespace std;

int n, m, k;

class seg {
	vector<long long> t;
	vector<long long> tag;

	public:
	seg(int n) {
		t.resize(4 * n + 5);
		tag.resize(4 * n + 5);
	}

	void pushdown(int x) {
		tag[x << 1] += tag[x];
		tag[x << 1 | 1] += tag[x];

		t[x << 1] += tag[x];
		t[x << 1 | 1] += tag[x];

		tag[x] = 0;
	}
	
	void build(int l, int r, int x, const vector<long long> &a, const vector<long long> &b) {
		if(l == r) {
			t[x] = a[l] + b[min(l + k - 1, m - 1)] - (l > 0 ? b[l - 1] : 0);
			return;
		}

		int mid = l + r >> 1;

		build(l, mid, x << 1, a, b);
		build(mid + 1, r, x << 1 | 1, a, b);

		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}

	void update(int l, int r, int x, int a, int b, int d) {
		if(l > b || r < a) {
			return;
		}

		if(l >= a && r <= b) {
			tag[x] += d;
			t[x] += d;

			return;
		}

		pushdown(x);

		int mid = l + r >> 1;

		update(l, mid, x << 1, a, b, d);
		update(mid + 1, r, x << 1 | 1, a, b, d);

		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}

	long long query(int l, int r, int x, int a, int b) {
		if(l > b || r < a) {
			return 0;
		}

		if(l >= a && r <= b) {
			return t[x];
		}

		pushdown(x);

		int mid = l + r >> 1;

		return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
	}

	long long get_max() {
		return t[1];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	vector<vector<long long> > a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		a[i].resize(m);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vector<vector<long long> > sum;
	sum.resize(n);

	for(int i = 0; i < n; ++i) {
		sum[i].resize(m);
	}

	for(int i = 0; i < n; ++i) {
		sum[i][0] = a[i][0];

		for(int j = 0; j + 1 < m; ++j) {
			sum[i][j + 1] += sum[i][j] + a[i][j + 1];	
		}
	}

	vector<vector<long long> > dp;
	dp.resize(n);

	for(int i = 0; i < n; ++i) {
		dp[i].resize(m);
	}

	for(int i = 0; i < m; ++i) {
		dp[0][i] = sum[0][min(m - 1, i + k - 1)] - (i > 0 ? sum[0][i - 1] : 0);
	}

	for(int i = 0; i < n - 1; ++i) {
		seg seg(m);

		seg.build(0, m - 1, 1, dp[i], sum[i + 1]);

		for(int j = 0; j < k; ++j) {
			seg.update(0, m - 1, 1, max(0, j + 1 - k), j, -a[i + 1][j]);
		}

		for(int j = 0; j < m; ++j) {
			dp[i + 1][j] = sum[i + 1][min(m - 1, j + k - 1)] - (j > 0 ? sum[i + 1][j - 1] : 0) + seg.get_max();

			seg.update(0, m - 1, 1, max(0, j + 1 - k), j, a[i + 1][j]);

			if(j + k < m) {
				seg.update(0, m - 1, 1, j + 1, j + k, -a[i + 1][j + k]);
			}
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';

	return 0;
}
