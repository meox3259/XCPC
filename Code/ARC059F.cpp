#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int n;
	cin >> n >> s;
	vector<vector<ll> > dp(n + 1, vector<ll> (n + 1, 0));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= n; ++j) {
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 2) % P;
			dp[i + 1][max(j - 1, 0)] = (dp[i + 1][max(j - 1, 0)] + dp[i][j]) % P;
		}
	}
	ll ans = dp[n][s.size()], inv = power(2, P - 2);
	for(int i = 0; i < s.size(); ++i) {
		ans = ans * inv % P;
	}
	cout << ans << '\n';
	return 0;
}
