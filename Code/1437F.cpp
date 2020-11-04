#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int P = 998244353;

int n;
int a[N];
long long dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1, greater<int> ());
	dp[1][1] = 1;
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			if(a[j] >= a[i] + a[i]) {
				dp[i][i] = (dp[i][i] + dp[i - 1][j]) % P;
			}
		}
		for(int j = 1; j < i; ++j) {
			if(a[j] >= a[i] + a[i]) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * (i - 1)) % P;
			} else {
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * max(i - 2, 0)) % P;
			}
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = (ans + dp[n][i]) % P;
	}

	cout << ans << '\n';

	return 0;
 }
