#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, int> > p;
	p.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i].second >> p[i].first;
	}
	sort(p.begin(), p.end());
	multiset<int> s;
	for(int i = 1; i < n; ++i) {
		s.emplace(p[i].second);
	}
	int ans = p[0].first - p[0].second + 1;
	int low = p[0].second;
	for(int i = 1; i < n; ++i) {
		int l = p[i].second;
		s.erase(s.find(l));
		ans = max(ans, p[i].first - p[i].second + 1 + max(0, p[0].first - max(low, s.empty() ? 0 : *s.rbegin()) + 1));
		int tmp = max(p[0].first - low + 1, 0);
		tmp += max(p[i].first - max(p[i].second, s.empty() ? 0 : *s.rbegin()) + 1, 0);
		ans = max(ans, tmp);
		low = max(low, l);
	}
	/*
	 1 4 x
	 2 5 x
	 4 7 -
	 5 8 -
	 */
	cout << ans << '\n';
	return 0;
}
