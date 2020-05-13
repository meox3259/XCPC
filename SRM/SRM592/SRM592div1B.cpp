#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

template <typename T> 
void add(T &x, T y) {
	x = (x + y) % P;
}

class LittleElephantAndPermutationDiv1 {
	public:
	int getNumber(int N, int K) {
		int m = 2500;
		vector<vector<vector<int> > > dp(N + 1, vector<vector<int> > (m + 1, vector<int> (N + 1, 0)));
		dp[0][0][0] = 1;

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j <= m; ++j) {
				for(int k = 0; k <= i; ++k) {
					if(dp[i][j][k]) {
						add(dp[i + 1][j][k + 1], dp[i][j][k]);
						if(j + i + 1 <= m) {
							add(dp[i + 1][j + i + 1][k], (int)(1LL * dp[i][j][k] * (2 * k + 1) % P));
						}
						if(j + i * 2 + 2 <= m && k >= 1) {
							add(dp[i + 1][j + i * 2 + 2][k - 1], (int)(1LL * dp[i][j][k] * k * k % P));
						}
					}
				}
			}
		}

		int ans = 0;
		for(int i = K; i <= m; ++i) {
			add(ans, dp[N][i][0]);
		}

		for(int i = 1; i <= N; ++i) {
			ans = 1LL * ans * i % P;
		}

		return ans;
	}	
};
