#include <bits/stdc++.h>

using namespace std;

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

	void clear() {
		for (int i = 0; i < v.size(); ++i) {
			v[i] = 0;
		}
	}

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

	string s;
	cin >> s;

	int n = s.size();

	long long x, y;
	cin >> x >> y;

	long long tot = 0;
	int c0 = 0;
	int c1 = 0;
	FenwickTree<int> t0(n + 1);
	FenwickTree<int> t1(n + 1);
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (c == '0') {
			c0 ++;
			tot += y * c1; 
			t0.add(i + 1, 1);
		} else {
			c1 ++;	
			tot += x * c0;
			t1.add(i + 1, 1);
		}
	}

	long long ans = tot;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			long long c00 = t0.query(i);
			long long c01 = t0.query(n) - t0.query(i + 1);
			long long c10 = t1.query(i);
			long long c11 = t1.query(n) - t1.query(i + 1);
			tot -= c00 * x + c01 * y;
			tot += c10 * y + c11 * x;
			t1.add(i + 1, -1);
			t0.add(i + 1, 1);
			ans = min(ans, tot);
		}	
	}

	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			long long c10 = t1.query(i);
			long long c11 = t1.query(n) - t1.query(i + 1);
			long long c00 = t0.query(i);
			long long c01 = t0.query(n) - t0.query(i + 1);
			tot -= c10 * y + c11 * x;
			tot += c00 * x + c01 * y;
			t1.add(i + 1, 1);
			t0.add(i + 1, -1);
			ans = min(ans, tot);
		}
	}

	cout << ans << '\n';

	return 0;
}
