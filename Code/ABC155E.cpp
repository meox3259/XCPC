#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int> > dp;
	dp.resize(n);
	for(int i = 0; i < n; ++i) {
		dp[i].resize(2);
	}
	dp[n - 1][0] = s.back() - '0';
	dp[n - 1][1] = 10 - (s.back() - '0');
	for(int i = n - 2; i >= 0; --i) {
		dp[i][0] = min(dp[i + 1][0] + s[i] - '0', dp[i + 1][1] + s[i] - '0' + 1);
		dp[i][1] = min(dp[i + 1][0] + 10 - (s[i] - '0'), dp[i + 1][1] +	9 - (s[i] - '0'));
	}
	cout << min(dp[0][0], dp[0][1] + 1) << '\n';
	return 0;
}
