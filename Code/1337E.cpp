#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

string s, t;

vector<vector<long long> > dp;

long long dfs(int l, int r) {
	if(l == r) {
		return (dp[l][l] = (t[l] == '?') ? 2 : (t[l] == s[0]) * 2);
	}

	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	
	long long ret = 0;

	int len = r - l;
	if(s[len] == t[r] || t[r] == '?') {
		ret += dfs(l, r - 1);
	}
	if(s[len] == t[l] || t[l] == '?') {
		ret += dfs(l + 1, r);
	}
	return dp[l][r] = ret % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> t;

	int n = s.size();
	int m = t.size();

	while(t.size() < n) {
		t += '?';
	}

	dp.resize(n + 1);

	for(int i = 0; i <= n; ++i) {
		dp[i].assign(n + 1, -1);
	}

	long long ans = 0;

	for(int i = m - 1; i < n; ++i) {
		ans = (ans + dfs(0, i)) % P;
	}

	cout << ans % P << '\n';

	return 0;
}
