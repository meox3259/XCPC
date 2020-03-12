#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	vector<long long> a;
	vector<vector<long long> > b;
	a.resize(26);
	b.resize(26);
	for(int i = 0; i < 26; ++i) {
		b[i].resize(26);
	}
	for(auto c : s) {
		int t = c - 'a';
		for(int i = 0; i < 26; ++i) {
			b[i][t] += a[i];
		}
		++a[t];
	}
	long long ans = *max_element(a.begin(), a.end());
	for(auto& v : b) {
		ans = max(ans, *max_element(v.begin(), v.end()));
	}
	cout << ans << '\n';
	return 0;
}
