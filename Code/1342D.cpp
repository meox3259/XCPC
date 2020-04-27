#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> m;
	m.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> m[i];
	}

	vector<int> c;
	c.resize(k + 1);

	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
	}

	c[0] = n + 1;

	multiset<int> s;

	for(int i : m) {
		s.emplace(i);
	}

	vector<vector<int> > ans;

	vector<int> pre;
	pre.resize(k + 1);

	for(int i = 1; i <= k; ++i) {
		if(c[i - 1] != c[i]) {
			pre[i] = i - 1;
		} else {
			pre[i] = pre[i - 1];
		}
	}

	while(!s.empty()) {
		int x = *s.rbegin();
		s.erase(s.find(x));

		int p = x;

		vector<int> tmp = { x };

		int sum = 1;

		while(!s.empty()) {
			if(sum == c[x]) {
				x = pre[x];
				continue;
			}

			if(x == 0) {
				break;
			}

			auto it = s.upper_bound(x);

			if(it == s.begin()) {
				break;
			}

			--it;

			x = *it;
			s.erase(it);
			++sum;
			tmp.emplace_back(x);
		}

		ans.emplace_back(tmp);
	}

	cout << ans.size() << '\n';

	for(auto &v : ans) {
		cout << v.size() << ' ';

		for(int i : v) {
			cout << i << ' ';
		}

		cout << '\n';
	}

	return 0;
}
