#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> s;
	s.resize(n);
	map<string, int> mp;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		++mp[s[i]];
	}
	int mx = 0;
	vector<string> ans;
	for(int i = 0; i < n; ++i) {
		mx = max(mx, mp[s[i]]);
	}
	for(auto p : mp) {
		if(p.second == mx) {
			ans.emplace_back(p.first);
		}
	}
	sort(ans.begin(), ans.end());
	for(auto t : ans) {
		cout << t << '\n';
	}
	return 0;
}
