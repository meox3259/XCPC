#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int a[N];
int mn[N * 4], mx[N * 4];
vector<int> pos[N];
int V[N];

void build(int l, int r, int x) {
	if (l == r) {
		mn[x] = a[l];
		mx[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, x << 1);
	build(mid + 1, r, x << 1 | 1);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}

int query_mx(int l, int r, int x, int a, int b) {
	if (l > b || r < a) {
		return 0;
	}
	if (l >= a && r <= b) {
		return mx[x];
	}
	int mid = l + r >> 1;
	return max(query_mx(l, mid, x << 1, a, b), query_mx(mid + 1, r, x << 1 | 1, a, b));
}

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

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		pos[a[i]].emplace_back(i);
	}

	build(1, n, 1);

	vector<int> need { 0 };
	for (int i = 1; i <= x; ++i) {
		if (!pos[i].empty()) {
			int r = *pos[i].rbegin();
			V[i] = query_mx(1, n, 1, 1, r - 1);
			if (V[i] > i) {
				need.emplace_back(i);
			} 
		}
	}

	long long ans = 0;
	FenwickTree<int> fw(n + 1);
	int Min = x;
	int Max = 0;
	for (int i = 1; i <= x; ++i) {
		bool ok = true;
		for (int j : pos[i]) {
			if (fw.query(n) - fw.query(j) >= 1) {
				ok = false;
			}
		}
		for (int j : pos[i]) {
			fw.add(j, 1);
		}
		int j = max(Max, max(need.back(), i));
		ans += x - j + 1;
		Max = max(Max, V[i]);
		if (!ok) {
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}
