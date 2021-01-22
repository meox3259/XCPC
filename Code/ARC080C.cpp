#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max() / 2;

class SegmentTree {
	vector<int> mn;

	public:
	SegmentTree() {}
	SegmentTree(int N) : mn(N * 4 + 5, inf) {}

	void init(int N) {
		mn.resize(N * 4 + 5, inf);
	}

	void update(int l, int r, int x, int p, int v) {
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

	int query(int l, int r, int x, int a, int b) {
		if (l > b || r < a) {
			return inf;
		}
		if (l >= a && r <= b) {
			return mn[x];
		}
		int mid = l + r >> 1;
		return min(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
	}
} t[2];

int n;

vector<int> pos;

pair<int, int> calc(int l, int r) {
	if (r - l < 1 || l < 0 || r >= n) {
		return make_pair(inf, inf);
	}
	int w = l & 1;
	int x = t[w].query(0, n - 1, 1, l, r);
	int y = t[w ^ 1].query(0, n - 1, 1, pos[x] + 1, r);
	return make_pair(x, y);
}	

class node {
	public:
	int l;
	int r;

	node() {}
	node(int _l, int _r) : l(_l), r(_r) {}

	bool friend operator < (const node &a, const node &b) {
		return calc(a.l, a.r) > calc(b.l, b.r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] --;
	}

	pos.resize(n);
	for (int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}

	for (int i = 0; i < 2; ++i) {
		t[i].init(n);
	}

	for (int i = 0; i < n; ++i) {
		t[i & 1].update(0, n - 1, 1, i, a[i]);
	}

	priority_queue<node> q;
	q.emplace(0, n - 1);

	vector<int> ans;
	while (!q.empty()) {
		auto [l, r] = q.top();
		q.pop();
		
		if (l > r || l < 0 || r >= n) {
			continue;
		}

		auto o = calc(l, r);
		ans.emplace_back(o.first);
		ans.emplace_back(o.second);

		int x = pos[o.first];
		int y = pos[o.second];

		q.emplace(l, x - 1);
		q.emplace(x + 1, y - 1);
		q.emplace(y + 1, r);
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << " \n"[i == n - 1];
	}

	return 0;
}
