#include <bits/stdc++.h>

using namespace std;

#define double long double

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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(k);
	vector<bool> mark(n + 1);
	for (int i = 0; i < k; ++i) {
		int p;
		cin >> p;
		mark[p] = true;
	}

	cout << fixed << setprecision(10);
	vector<pair<double, double> > dp(n + 1);
	FenwickTree<double> fi(n + 1);
	FenwickTree<double> se(n + 1);
	dp[n] = make_pair(0, 0);
	for (int i = n - 1; i >= 0; --i) {
		double a = fi.query(min(n, i + m)) - fi.query(i);
		double b = se.query(min(n, i + m)) - se.query(i);
		if (mark[i]) {
			se.add(i, 1.0);
			continue;
		}
		a /= m;
		b /= m;
		a += 1.0;
		if (i != 0) {
			fi.add(i, a);
			se.add(i, b);
		} else {
			if (b >= 1.0) {
				cout << "-1" << '\n';
			} else {
				cout << a / (1.0 - b) << '\n';
			}
		}
	}

	return 0;
}
