#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<vector<long long> > dp(n + 1, vector<long long> (2));
	dp[0][1] = 1;

	vector<long long> f(n);
	vector<bool> vis(n);

	long long cnt = 0;

	for(int i = 0; i < n; ++i) {
		dp[i + 1][0] = dp[i][0] * 2 % P;
		dp[i + 1][1] = dp[i][1];
		if(s[i] == '1') {
			dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % P;
		}
	}

	for(int i = 0; i + i + i + 3 <= n; ++i) {
		if((n * 2) % (2 * i + 2) == 0 && ((n * 2) / (2 * i + 2)) % 2 == 1) {
			string tmp = "";
			string t = "";
			for(int j = 0; j <= i; ++j) {
				tmp += s[j];
			}
			for(int j = 0; j <= i; ++j) {
				if(s[j] == '0') {
					tmp += '1';
				} else {
					tmp += '0';
				}
			}
			for(int j = 0; j < n; ++j) {
				t += tmp[j % (i * 2 + 2)];
			}
			long long x = dp[i + 1][0] + (t <= s);
			f[i] = x % P;
			vis[i] = true;
		} 
	}

	for(int i = 1; i <= n; ++i) {
		if(vis[i - 1]) {
			for(int j = i + i; j <= n; j += i) {
				if(vis[j - 1]) {
					f[j - 1] = (f[j - 1] - f[i - 1] + P) % P;
				}
			}
		}
	}

	long long ans = 0;
	long long tot = (dp[n][0] + dp[n][1]) % P;
	for(int i = 0; i < n; ++i) {
		if(vis[i]) {
			tot = (tot - f[i] + P) % P;
		}
	}
	ans = (ans + tot * n * 2) % P;
	for(int i = 0; i < n; ++i) {
		if(vis[i]) {
			ans = (ans + f[i] * (i + 1) * 2) % P;
		}
	}

	cout << ans << '\n';

	return 0;
}
