#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	string ans(n, '0');	
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			a.emplace_back(i);
		} else {
			b.emplace_back(i);
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		if (i & 1) {
			ans[a[i]] = '0';
		} else {
			ans[a[i]] = '1';
		}
	}

	for (int i = 0; i < b.size(); ++i) {
		if (i & 1) {
			ans[b[i]] = '0';
		} else {
			ans[b[i]] = '1';
		}
	}

	cout << ans << '\n';

	return 0;
}
