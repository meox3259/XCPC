#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	string ans;
	for (char c : s) {
		ans += c;
		int m = ans.size();
		if (m >= 3 && ans[m - 3] == 'f' && ans[m - 2] == 'o' && ans[m - 1] == 'x') {
			ans.pop_back();
			ans.pop_back();
			ans.pop_back();
		} 
	}

	cout << ans.size() << '\n';

	return 0;
}
