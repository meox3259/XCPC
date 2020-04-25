#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> p;
	p.resize(n);

	for(int &i : p) {
		cin >> i;
	}

	set<int> s;

	for(int i = 0; i < k; ++i) {
		s.emplace(p[i]);
	}

	int ans = 1;

	for(int i = 0; i + k < n; ++i) {
		bool f1 = (*s.begin() == p[i]);
		s.emplace(p[i + k]);
		s.erase(p[i]);
		bool f2 = (*s.rbegin() == p[i + k]);

		if(!f1 || !f2) {
			++ans;
		}
	}

	bool ok = false;

	int pre = -1;
	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		if(pre < p[i]) {
			++cnt;
		} else {
			cnt = 1;
		}

		pre = p[i];

		if(cnt == k) {
			--ans;
			ok = true;
		}
	}

	cout << ans + ok << '\n';

	return 0;
}
