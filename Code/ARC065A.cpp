#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();

	vector<int> dp;
	dp.assign(n + 1, 0);

	vector<string> S = {"dream", "dreamer", "erase", "eraser"};
	
	dp[0] = 1;

	for(int i = 0; i < n; ++i) {
		for(auto& t : S) {
			int len = t.size();
			if(s.substr(i, len) == t) {
				dp[i + len] |= dp[i];
			}
		}
	}

	if(dp[n]) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
	return 0;
}
