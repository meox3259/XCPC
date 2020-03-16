#include <bits/stdc++.h>

using namespace std;

class fenwick {
	vector<int> t;
	
	public:
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

	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > v;
	v.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), [&] (pair<int, int> x, pair<int, int> y) {
		return x.second - x.first < y.second - y.first;
	});
	
	fenwick fenwick(m + 2);

	for(auto& p : v) {
		fenwick.add(p.first, 1);
		fenwick.add(p.second + 1, -1);
	}
	
	int tot = 0;

	vector<int> ans;

	ans.resize(m);

	for(int i = m; i >= 1; --i) {
		while(!v.empty() && v.back().second - v.back().first + 1 >= i) {
			++tot;

			fenwick.add(v.back().first, -1);
			fenwick.add(v.back().second + 1, 1);

			v.pop_back();
		}

		ans[i - 1] = tot;

		for(int j = 0; j <= m; j += i) {
			ans[i - 1] += fenwick.query(j);
		}
	}

	for(auto x : ans) {
		cout << x << '\n';
	}

	return 0;

}
