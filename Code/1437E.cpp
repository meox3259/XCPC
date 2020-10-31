#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

    void update(int p, T val) {
        for(int i = p; i < N; i += (i & -i)) {
            v[i] = max(v[i], val);
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p; i >= 1; i -= (i & -i)) {
            sum = max(sum, v[i]);
        }
        return sum;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(k);
	for(int i = 0; i < k; ++i) {
		cin >> b[i];
	}

	for(int i = 0; i < k; ++i) {
		b[i] -= 1;
	}

	for(int i = 0; i + 1 < k; ++i) {
		if(a[b[i + 1]] - a[b[i]] < b[i + 1] - b[i]) {
			cout << -1 << '\n';
			exit(0);
		}
	}

	int ans = 0;

	if(b.empty()) {
		vector<int> tmp;
		for(int i = 0; i < n; ++i) {
			tmp.emplace_back(a[i] - i - 1);
		}
		vector<int> s;
		for(int i : tmp) {
			s.emplace_back(i);
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		int m = s.size();
		FenwickTree<int> t(m + 1);
		for(int i : tmp) {
			int p = lower_bound(s.begin(), s.end(), i) - s.begin() + 1;
			int d = t.query(p) + 1;
			t.update(p, d);
		}

		ans += tmp.size() - t.query(m);
		cout << ans << '\n';
		exit(0);
	}

	if(!b.empty()) {
		vector<int> tmp;
		for(int i = 0; i < b[0]; ++i) {
			if(a[i] <= a[b[0]] - (b[0] - i)) {
				tmp.emplace_back(a[i] - i - 1);
			} else {
				ans += 1;
			}
		}
		vector<int> s;
		for(int i : tmp) {
			s.emplace_back(i);
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		int m = s.size();
		FenwickTree<int> t(m + 1);
		for(int i : tmp) {
			int p = lower_bound(s.begin(), s.end(), i) - s.begin() + 1;
			int d = t.query(p) + 1;
			t.update(p, d);
		}

		ans += tmp.size() - t.query(m);
	}

	if(!b.empty()) {
		vector<int> tmp;
		for(int i = b.back() + 1; i < n; ++i) {
			if(a[i] >= i - b.back() + a[b.back()]) {
				tmp.emplace_back(a[i] - i - 1);
			} else {
				ans += 1;
			}
		}
		vector<int> s;
		for(int i : tmp) {
			s.emplace_back(i);
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		int m = s.size();
		FenwickTree<int> t(m + 1);
		for(int i : tmp) {
			int p = lower_bound(s.begin(), s.end(), i) - s.begin() + 1;
			int d = t.query(p) + 1;
			t.update(p, d);
		}

		ans += tmp.size() - t.query(m);
	}

	for(int cur = 0; cur + 1 < k; ++cur) {
		vector<int> tmp;
		for(int j = b[cur] + 1; j < b[cur + 1]; ++j) {
			if(a[b[cur]] + j - b[cur] <= a[j] && a[j] <= a[b[cur + 1]] - b[cur + 1] + j) {
				tmp.emplace_back(a[j] - j - 1);
			} else {
				ans += 1;
			}
		}
		vector<int> s;
		for(int i : tmp) {
			s.emplace_back(i);
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		int m = s.size();
		FenwickTree<int> t(m + 1);
		for(int i : tmp) {
			int p = lower_bound(s.begin(), s.end(), i) - s.begin() + 1;
			int d = t.query(p) + 1;
			t.update(p, d);
		}

		ans += tmp.size() - t.query(m);
	}

	cout << ans << '\n';

	return 0;
}
