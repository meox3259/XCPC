#include <bits/stdc++.h>

using namespace std;

class fenwick {
public:
	vector<int> t;

	fenwick(int n) {
		t.resize(n + 1);
	}

	void add(int p, int d) {
		for(; p < (int)t.size(); p += p & -p) {
			t[p] += d;
		}
	}

	int query(int p) {
		int ret = 0;
		
		for(; p; p -= p & -p) {
			ret += t[p];
		}

		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;
	a.resize(n);
	b.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	vector<int> v;

	for(int i = 0; i < n; ++i) {
		v.emplace_back(a[i] - b[i]);
		v.emplace_back(b[i] - a[i]);
	}

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	fenwick t(v.size() + 1);

	long long ans = 0;

	for(int i = 0; i < n; ++i) {
		int p = lower_bound(v.begin(), v.end(), a[i] - b[i]) - v.begin() + 1;
		
		ans += t.query(p - 1);

		int c = lower_bound(v.begin(), v.end(), b[i] - a[i]) - v.begin() + 1;
		t.add(c, 1);

	}

	cout << ans << '\n';
	return 0;
}
