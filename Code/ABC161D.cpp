#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;

	long long l = 0;
	long long r = 3234566667 + 100;
	long long ans = 0;

	while(r - l > 1) {
		long long mid = (l + r) / 2;

		long long t = mid;

		vector<int> bit;

		while(t) {
			bit.emplace_back(t % 10);
			t /= 10;
		}

		reverse(bit.begin(), bit.end());

		int m = bit.size();
				
		vector<vector<vector<long long> > > dp;
		
		dp.resize(m + 1);

		for(int i = 0; i <= m; ++i) {
			dp[i].resize(11);
		}

		for(int i = 0; i <= m; ++i) {
			for(int j = 0; j <= 10; ++j) {
				dp[i][j].resize(2);
			}
		}

		dp[0][10][1] = 1;

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < 10; ++j) {
				for(int k = 0; k < 10; ++k) {
					if(abs(j - k) <= 1) {
						dp[i + 1][k][0] += dp[i][j][0];
						if(k < bit[i]) {
							dp[i + 1][k][0] += dp[i][j][1];
						}
						if(k == bit[i]) {
							dp[i + 1][k][1] += dp[i][j][1];
						}
					}
				}
			}

			for(int k = 1; k < 10; ++k) {
				if(k < bit[i]) {
					dp[i + 1][k][0] += dp[i][10][1];
				}
				if(k == bit[i]) {
					dp[i + 1][k][1] += dp[i][10][1];
				}
				dp[i + 1][k][0] += dp[i][10][0];
			}

			dp[i + 1][10][0] += dp[i][10][0] + dp[i][10][1];
		}

		int sum = 0;

		for(int i = 0; i < 11; ++i) {
			for(int j = 0; j < 2; ++j) {
				sum += dp[m][i][j];
			}
		}

		--sum;

		if(sum < k) {
			l = mid;
		} else {
			r = ans = mid;
		}
	}

	cout << ans << '\n';
	
	return 0;
}
