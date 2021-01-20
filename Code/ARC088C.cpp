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

	string s;
	cin >> s;

	int n = s.size();

	vector<vector<int> > p(26);
	for (int i = 0; i < n; ++i) {
		p[s[i] - 'a'].emplace_back(i);
	}

	int cnt = 0;
	for (int i = 0; i < 26; ++i) {
		cnt += (int)p[i].size() & 1;
	}

	if (cnt > (n & 1)) {
		cout << -1 << '\n';
		exit(0);
	}

	vector<pair<int, int> > seg;
	for (int i = 0; i < 26; ++i) {
		int m = p[i].size();
		for (int j = 0; j < m && m - j - 1 >= j; ++j) {
			seg.emplace_back(p[i][j], p[i][m - j - 1]);	
		}
	}

	FenwickTree<int> fw(n + 1);
	long long ans = 0;
	for (auto [x, y] : seg) {
		if (x == y) {
			fw.add(y + 1, 1);
		} else {
			fw.add(y + 1, 2);	
		}
	}

	for (auto [x, y] : seg) {
		if (x == y) {
			ans += fw.query(x) / 2; 
		} else {
			ans += fw.query(x);
		}
	}

	for (auto [x, y] : seg) {
		if (x == y) {
			fw.add(y + 1, -1);
		} else {
			fw.add(y + 1, -2);
		}
	}

	sort(seg.begin(), seg.end(), [&] (auto x, auto y) {
		return x.second < y.second;
	});

	for (auto [x, y] : seg) {
		ans += fw.query(y) - fw.query(x);
		fw.add(y + 1, 1);
		fw.add(x + 1, -1);
	}

	cout << ans << '\n';

	return 0;
}
