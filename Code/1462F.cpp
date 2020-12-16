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

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> l(n);
		vector<int> r(n);
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i];
		}

		vector<int> v;
		for (int i : l) {
			v.emplace_back(i);
		}
		for (int i : r) {
			v.emplace_back(i);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		auto id = [&] (int x) {
			return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
		};

		int m = v.size();

		FenwickTree<int> pre(m + 1);
		FenwickTree<int> suf(m + 1);
		for (int i : l) {
			pre.add(id(i), 1);
		}
		for (int i : r) {
			suf.add(id(i), 1);
		}
		int ans = n - 1;
		for (int i = 0; i < n; ++i) {
			ans = min(ans, suf.query(id(l[i]) - 1) + pre.query(m) - pre.query(id(r[i])));	
		}

		cout << ans << '\n';
	}

	return 0;
}
