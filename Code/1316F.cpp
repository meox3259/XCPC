#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
const int N = 1e9 + 5;

vector<long long> pow2;
vector<long long> inv2;
vector<pair<int, int> > val;

class node {
	public:
	long long sz, f, g, sum;

	node() = default;

	node(long long _sz, long long _f, long long _g, long long _sum) : sz(_sz), f(_f), g(_g), sum(_sum) {}

	node friend operator + (const node &a, const node &b) {
		return { a.sz + b.sz, (a.f + b.f * pow2[a.sz]) % P, 
				 (a.g + b.g * inv2[a.sz]) % P, (a.sum + b.sum + a.f * b.g % P * inv2[a.sz]) % P };
	}
};

class segment_tree {
	vector<node> t;

	public:
	segment_tree(int n) {
		t.resize(4 * n + 5);
	}

	void update(int l, int r, int x, int p, int d) {
		t[x].sz += d;

		if(l == r) {
			if(d == 1) {
				t[x].sum = 0;
				t[x].f = val[l].first;
				t[x].g = val[l].first * inv2[1] % P;
			} else {
				t[x].sum = 0;
				t[x].f = 0;
				t[x].g = 0;
			}

			return;
		}

		int mid = l + r >> 1;

		if(p <= mid) {
			update(l, mid, x << 1, p, d);
		} else {
			update(mid + 1, r, x << 1 | 1, p, d);
		}

		t[x] = t[x << 1] + t[x << 1 | 1];
	}

	long long ans() {
		return t[1].sum;
	}
};

long long power(long long x, long long t) {
	long long ret = 1;
	
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p;
	p.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	for(int i = 0; i < n; ++i) {
		val.emplace_back(p[i], i);
	}

	int m;
	cin >> m;

	vector<pair<int, int> > q;
	q.resize(m);

	for(int i = 0; i < m; ++i) {
		cin >> q[i].first >> q[i].second;
		val.emplace_back(q[i].second, i + n);
	}

	sort(val.begin(), val.end());

	vector<int> pos;
	pos.resize(n + m);

	segment_tree seg(n + m);
	
	pow2.resize(n + m + 1);
	inv2.resize(n + m + 1);

	pow2[0] = 1;
	inv2[0] = 1;

	for(int i = 0; i < n + m; ++i) {
		pow2[i + 1] = pow2[i] * 2 % P;
	}

	inv2[1] = power(2, P - 2);

	for(int i = 1; i < n + m; ++i) {
		inv2[i + 1] = inv2[i] * inv2[1] % P;
	}

	for(int i = 0; i < n + m; ++i) {
		pos[val[i].second] = i;
	}

	for(int i = 0; i < n; ++i) {
		seg.update(0, n + m - 1, 1, pos[i], 1);
	}

	cout << seg.ans() << '\n';

	for(int _ = 0; _ < m; ++_) {
		auto [i, x] = q[_];
		seg.update(0, n + m - 1, 1, pos[i - 1], -1);
		seg.update(0, n + m - 1, 1, pos[_ + n], 1);

		pos[i - 1] = pos[_ + n];

		cout << seg.ans() << '\n';
	}

	return 0;
}
