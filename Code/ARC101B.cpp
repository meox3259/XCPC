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

	int l = 0;
	int r = *max_element(a.begin(), a.end()) + 1;

	auto check = [&] (int mid) {
		FenwickTree<int> fw(n + n + 2);
		fw.add(0 + n + 1, 1);
		int sum = 0;
		long long cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] <= mid) {
				sum ++;
			} else {
				sum --;
			}
			cnt += fw.query(n + n + 1) - fw.query(sum + n);
			fw.add(sum + n + 1, 1);
		}
		long long m = 1LL * n * (n + 1) / 2;
		if (cnt >= (m + 1) / 2) {
			return true;
		} else {
			return false;
		}
	};

	while (r - l > 1) {
		int mid = l + r >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}

	cout << r << '\n';

	return 0;
}
