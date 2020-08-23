#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

class Fenwick {
	vector<int> t;

	public:
	Fenwick(int N) : t(N) {}

	void add(int x, int v) {
		for(int i = x; i < (int)t.size(); i += (i & -i)) {
			t[i] += v;
		}
	}

	int query(int x) {
		int ret = 0;
		for(int i = x; i >= 1; i -= (i & -i)) {
			ret += t[i];
		}
		return ret;
	}

	int range(int l, int r) {
		return query(r) - query(l - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int> > a;
	for(int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		a.emplace_back(x, y, z);
	}

	vector<tuple<int, int, int> > b;
	for(int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		b.emplace_back(x, y, z);
	}

	sort(b.begin(), b.end());

	long long ans = 1;

	for(auto [x, y, z] : a) {
		if(y == 0) {
			ans += 1;
		}
		if(z == inf) {
			ans += 1;
		}
	}	

	for(auto [x, y, z] : b) {
		if(y == 0) {
			ans += 1;
		}
		if(z == inf) {
			ans += 1;
		}
	}

	vector<pair<int, int> > left;
	vector<pair<int, int> > right;
	for(auto [y, l, r] : a) {
		if(l == 0) {
			left.emplace_back(r, y);
		} else {
			right.emplace_back(l, y);
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	Fenwick Fenwick(inf + 1);
	for(auto [r, y] : left) {
		Fenwick.add(y, 1);
	} 

	for(int i = 0, px = 0, py = 0; i < m; ++i) {
		auto [x, l, r] = b[i];

		while(px < left.size()) {
			auto [r, y] = left[px];
			if(r < x) {
				Fenwick.add(y, -1);
				px += 1;
			} else {
				break;
			}
		}

		while(py < right.size()) {
			auto [l, y] = right[py];
			if(l <= x) {
				Fenwick.add(y, 1);
				py += 1;
			} else {
				break;
			}
		}

		ans += Fenwick.range(l, r);
	}

	cout << ans - n - m << '\n';

	return 0;
}
