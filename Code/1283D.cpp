#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> x(n);
	for(int &i : x) {
		cin >> i;
	}

	map<int, bool> vis;

	set<pair<int, int> > s;

	for(int i = 0; i < n; ++i) {
		s.emplace(1, x[i] - 1);
		s.emplace(1, x[i] + 1);
	}

	for(int i : x) {
		vis[i] = true;
	}

	long long sum = 0;
	vector<int> ans;

	while(ans.size() < m) {
		auto [d, p] = *s.begin();
		s.erase(s.begin());
		if(vis[p]) {
			continue;
		}
		ans.emplace_back(p);
		vis[p] = true;
		sum += d;
		s.emplace(d + 1, p - 1);
		s.emplace(d + 1, p + 1);
	}

	cout << sum << '\n';
	for(int i : ans) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
