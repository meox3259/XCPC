#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

class SegmentTree {
	public:
	vector<long long> tag;
	vector<long long> sum;

	SegmentTree() {}
	SegmentTree(int N) : tag(4 * N + 5), sum(4 * N + 5) {}

	void pushdown(int x, int l, int r) {
		int mid = l + r >> 1;
		tag[x << 1] = (tag[x << 1] + tag[x]) % P;
		tag[x << 1 | 1] = (tag[x << 1 | 1] + tag[x]) % P;
		sum[x << 1] = (sum[x << 1] + 1LL * (mid - l + 1) * tag[x]) % P;
		sum[x << 1 | 1] = (sum[x << 1 | 1] + 1LL * (r - mid) * tag[x]) % P;
		tag[x] = 0;
	}

	void update(int l, int r, int x, int a, int b, int d) {
		if (l > b || r < a) {
			return;
		}
		if (l >= a && r <= b) {
			(tag[x] += d) %= P;
			(sum[x] += 1LL * (r - l + 1) * d) %= P;
			return;
		}
		pushdown(x, l, r);
		int mid = l + r >> 1;
		update(l, mid, x << 1, a, b, d);
		update(mid + 1, r, x << 1 | 1, a, b, d);
		sum[x] = ((sum[x << 1] + sum[x << 1 | 1])) % P;
	}

	long long query(int l, int r, int x, int a, int b) {
		if (l > b || r < a) {
			return 0;
		}
		if (l >= a && r <= b) {
			return sum[x];
		}
		pushdown(x, l, r);
		int mid = l + r >> 1;
		return query(l, mid, x << 1, a, b) + query(mid + 1, r, x << 1 | 1, a, b);
	}
};

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

    void add(int p, T val) {
        for(int i = p; i < N; i += (i & -i)) {
            v[i] += val;
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p; i >= 1; i -= (i & -i)) {
            sum += v[i];
        }
        return sum;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	auto solve = [&] (vector<int> a) {
		vector<int> pos(n);
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&] (int i, int j) {
			return a[i] < a[j];
		});	
		SegmentTree pre(n);
		SegmentTree suf(n);
		FenwickTree<int> fw(n + 1);
		long long ret = 0;
		for (int i = 0; i < n; ++i) {
			int p = pos[i];	
			pre.update(0, n - 1, 1, 0, p, 1);
			suf.update(0, n - 1, 1, p, n - 1, 1);
			fw.add(p + 1, 1);
			ret = (ret + 1LL * (pre.query(0, n - 1, 1, 0, p) - 1LL * (fw.query(n) - fw.query(p + 1)) * (p + 1) % P + P) % P * a[p] % P * (n - p) % P) % P;
			ret = (ret + 1LL * (suf.query(0, n - 1, 1, p, n - 1) - 1LL * fw.query(p + 1) * (n - p) % P + P) % P * a[p] % P * (p + 1) % P) % P;
		}
		for (int i = 0; i < n; ++i) {
		//	ret = (ret - a[i] + P) % P;
		}
		return ret;
	};

	cout << solve(a) << '\n';

	return 0;
}
