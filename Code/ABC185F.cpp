#include <bits/stdc++.h>

using namespace std;

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

    void add(int p, T val) {
        for(int i = p; i < N; i += (i & -i)) {
            v[i] ^= val;
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p; i >= 1; i -= (i & -i)) {
            sum ^= v[i];
        }
        return sum;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	FenwickTree<int> fw(n + 1);
	for (int i = 0; i < n; ++i) {
		fw.add(i + 1, a[i]);
	}

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			x --;
			fw.add(x + 1, y);
		}
		if (t == 2) {
			x --;
			y --;
			cout << (fw.query(y + 1) ^ fw.query(x)) << '\n';
		}
	}

	return 0;
}
