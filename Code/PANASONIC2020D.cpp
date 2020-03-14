#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> ans;

	function<void(int, int, string)> dfs = [&] (int d, int p, string s) {
		if(d == n) {
			ans.emplace_back(s);
			return;
		}

		for(int i = 0; i <= p + 1; ++i) {
			dfs(d + 1, max(p, i), s + (char)('a' + i));
		}

	};

	dfs(1, 0, "a");

	sort(ans.begin(), ans.end());

	for(auto& s : ans) {
		cout << s << '\n';
	}
	return 0;
}
