#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int> > a;
	a.emplace_back(0, 0);

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		a.emplace_back(x, i);

	}

	sort(a.begin(), a.end());

	vector<long long> ans;
	ans.resize(n);

	int cnt = 0;

	set<int> s;

	while(a.size() > 1) {
		++cnt;
		
		int h = a.back().first;
		int p = a.back().second;

		a.pop_back();

		s.emplace(p);

		ans[*s.begin()] += 1LL * cnt * (h - a.back().first);

	}

	for(auto x : ans) {
		cout << x << '\n';
	}

	return 0;

}
