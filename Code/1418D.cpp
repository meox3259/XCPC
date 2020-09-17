#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int inf = 1000000005;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;

	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	set<int> pos;
	for(int i = 0; i < n; ++i) {
		pos.emplace(p[i]);
	}

	multiset<long long> s;
	long long sum = p[n - 1] - p[0];
	for(int i = 0; i + 1 < n; ++i) {
		s.emplace(p[i + 1] - p[i]);
	}

	auto query = [&] () {
		if(pos.size() <= 2) {
			return 0LL;
		}
		return *pos.rbegin() - *pos.begin() - *s.rbegin();
	};

	cout << query() << '\n';

	while(q--) {
		int t, x;
		cin >> t >> x;

		if(t == 0) {
			auto it = pos.find(x);	
			if(it != pos.begin()) {
				s.erase(s.find(x - *prev(it)));
			}
			if(it != (--pos.end())) {
				s.erase(s.find(*next(it) - x));
			}

			if(it != pos.begin() && it != (--pos.end())) {
				s.emplace(*next(it) - *prev(it));
			}

			pos.erase(it);
		} else {
			pos.emplace(x);
			auto it = pos.find(x);
			if(it != pos.begin() && it != (--pos.end())) {
				s.erase(s.find(*next(it) - *prev(it)));
			}
			if(it != pos.begin()) {
				s.emplace(x - *prev(it));
			}
			if(it != (--pos.end())) {
				s.emplace(*next(it) - x);
			}
		}

		cout << query() << '\n';	
	}

	return 0;
}
