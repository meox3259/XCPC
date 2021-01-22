#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

int main() {
	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	long long pre = 2;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (pre - dp[i - 2] + P) % P;
		pre = (pre + dp[i]) % P;
	}

	long long ans = (dp[n - 1] * (n - 1) % P + dp[n]) % P;
	for (int i = 0; i < n - 1; ++i) {
		ans = (ans + dp[i] * (n - 1) % P * (n - 1) % P) % P;
		ans = (ans + dp[i] * (i + 1)) % P;
	}

	cout << ans << '\n';

	return 0;
}
