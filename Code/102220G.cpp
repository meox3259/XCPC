#include <bits/stdc++.h>

using namespace std;

class fenwick {
	public:
		vector<long long> t;

		fenwick(int n) {
			t.resize(n + 1);
		}

		void add(int p, int d) {
			for(; p < (int)t.size(); p += p & -p) {
				t[p] += d;
			}
		}

		long long query(int p) {
			long long ret = 0;

			for(; p; p -= p & -p) {
				ret += t[p];
			}

			return ret;
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while(T--) {
		int n;
		cin >> n;

		vector<int> a;
		a.resize(n);

		vector<int> b;
		b.resize(n);

		vector<int> c;
		c.resize(n);

		vector<int> d;
		d.resize(n);

		vector<int> vec;

		for(int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i] >> c[i] >> d[i];
		}

		for(int i = 0; i < n; ++i) {
			vec.emplace_back(a[i]);
			vec.emplace_back(c[i]);
		}

		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		int m = vec.size();

		fenwick l(m);
		fenwick r(m);

		sort(a.begin(), a.end());
		sort(c.begin(), c.end());

		auto find = [&] (int x) {
			return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;	
		};

		for(int i = 0; i < n; ++i) {
			r.add(find(a[i]), a[i]);
			l.add(find(c[i]), c[i]);
		}

		long long mn_x = 1000000000000000000;

		for(auto& p : vec) {
			auto it = lower_bound(a.begin(), a.end(), p);
			
			int pos = find(p);

			long long tmp = 0;

			if(it != a.end()) {
				int t = n - (it - a.begin());
				tmp += r.query(m) - r.query(pos - 1) - 1LL * t * p;
			}

			auto it_1 = lower_bound(c.begin(), c.end(), p);

			if(it_1 != c.begin()) {
				--it_1;

				int t = it_1 - c.begin() + 1;

				tmp += 1LL * t * p - l.query(find(*it_1));
			}

			mn_x = min(mn_x, tmp);
		}

		vec.clear();

		for(int i = 0; i < n; ++i) {
			vec.emplace_back(b[i]);
			vec.emplace_back(d[i]);
		}

		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		m = vec.size();

		sort(b.begin(), b.end());
		sort(d.begin(), d.end());

		long long mn_y = 1000000000000000000;

		l.t.assign(m + 1, 0);
		r.t.assign(m + 1, 0);

		for(int i = 0; i < n; ++i) {
			r.add(find(b[i]), b[i]);
			l.add(find(d[i]), d[i]);
		}

		for(auto& p : vec) {
			auto it = lower_bound(b.begin(), b.end(), p);
			
			int pos = find(p);

			long long tmp = 0;

			if(it != b.end()) {
				int t = n - (it - b.begin());
				tmp += r.query(m) - r.query(pos - 1) - 1LL * t * p;
			} 

			auto it_1 = lower_bound(d.begin(), d.end(), p);

			if(it_1 != d.begin()) {
				--it_1;

				int t = it_1 - d.begin() + 1;

				tmp += 1LL * t * p - l.query(find(*it_1));
			}

			mn_y = min(mn_y, tmp);
		}
	

		cout << mn_x + mn_y << '\n';
	}

	return 0;
}
