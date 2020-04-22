#include <bits/stdc++.h>

using namespace std;

class fenwick {
	vector<int> t;

	public:
	fenwick(int n) {
		t.resize(n + 1);
	}

	void clr() {
		t.assign(t.size() + 1, 0);
	}

	void add(int p, int v) {
		for(int i = p; i < (int)t.size(); i += i & -i) {
			t[i] += v;
		}
	}

	int query(int p) {
		int ret = 0;

		for(int i = p; i >= 1; i -= i & -i) {
			ret += t[i];
		}

		return ret;
	}

	int range(int l, int r) {
		if(l > r) {
			return 0;
		}

		return query(r) - query(l - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		vector<int> a;
		a.resize(n);

		for(int &i : a) {
			cin >> i;
		}

		vector<pair<int, int> > p;

		vector<int> sz;
		sz.resize(2 * k + 1);

		for(int i = 0; i < n / 2; ++i) {
			p.emplace_back(a[i], a[n - 1 - i]);
			++sz[a[i] + a[n - 1 - i]];
		}
			
		sort(p.begin(), p.end());
	
		vector<int> ans;
		ans.resize(2 * k + 1);

		fenwick fenwick(k);

		int j = -1;

		for(int x = k + 1; x <= 2 * k; ++x) {
			while(j + 1 < p.size() && p[j + 1].first <= x - k - 1) {
				++j;
				fenwick.add(p[j].second, 1);
			}

			ans[x] += fenwick.range(1, x - k - 1);
		}

		j = 0;

		fenwick.clr();

		for(auto [x, y] : p) {
			fenwick.add(y, 1);
		}

		for(int x = 0; x <= k; ++x) {
			while(j < p.size() && p[j].first < x) {
				fenwick.add(p[j].second, -1);
				++j;
			}

			ans[x] += fenwick.range(x, k);
		}

		for(int i = 0; i < 2 * k + 1; ++i) {
			ans[i] = 2 * ans[i] + (n / 2 - ans[i]) - sz[i]; 		
		}

		cout << *min_element(ans.begin(), ans.end()) << '\n';
	}

	return 0;
}
