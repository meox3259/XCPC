#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();

	if (s.back() == '1') {
		cout << -1 << '\n';
		exit(0);
	}  

	if (s[0] == '0') {
		cout << -1 << '\n';
		exit(0);
	}

	for (int i = 1; i < n; ++i) {
		int j = n - i;
		if (s[i - 1] != s[j - 1]) {
			cout << -1 << '\n';
			exit(0);
		}
	}

	int cur = n - 1;
	int tot = n - 1;
	vector<pair<int, int> > ans;
	for (int i = n - 2; i >= 0; --i) {
		tot --;
		if (s[i] == '1') {
			ans.emplace_back(tot, cur);
			cur = tot;
		} else {
			ans.emplace_back(tot, cur);
		}	
	}

	for (auto [x, y] : ans) {
		cout << x + 1 << ' ' << y + 1 << '\n';
	}

	return 0;
}
