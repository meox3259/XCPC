#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

long long dp[2005];

int main() {
	int s;
	cin >> s;

	dp[0] = 1;	
	for(int i = 0; i <= s; ++i) {
		for(int j = 3; j <= i; ++j) {
			dp[i] = (dp[i] + dp[i - j]) % P;	
		}
	}

	cout << dp[s] << '\n';

	return 0;
}
