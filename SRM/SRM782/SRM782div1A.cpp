#include <bits/stdc++.h>

using namespace std;

class EmptyTheBox {
	public:
		int n;
		
		vector<int> sum;

		vector<bool> vis;

		vector<double> dp;

		double dfs(int S, int D) {
			double tot = 0;

			if(vis[S]) {
				return dp[S];
			}

			for(int i = 1; i <= D; ++i) {
				for(int j = 1; j <= D; ++j) {
					double tmp = 1.0 / (double)(D * D) * sum[S];
					for(int s = S; s; s = (s - 1) & S) {
						if(sum[s] == i + j) {
							tmp = min(tmp, 1.0 / (double)(D * D) * dfs(S ^ s, D));				
						}
					}	

					tot += tmp;
				}
			}

			vis[S] = true;

			return dp[S] = tot;
		}
		double minExpectedPenalty(int D, int T) {
			n = min(2 * D, T);

			dp.resize(1 << (n + 1));
	
			vis.resize(1 << (n + 1));

			sum.resize(1 << (n + 1));

			for(int i = 0; i < 1 << n; ++i) {
				for(int j = 0; j < n; ++j) {
					if(i >> j & 1) {
						sum[i] += j + 1;
					}
				}
			}

			double ans = 0;

			for(int i = 2 * D + 1; i <= T; ++i) {
				ans += i;
			}

			ans += dfs(((1 << n) - 1), D);

			return ans;
		}
};

/*
int main() {
	EmptyTheBox a;

	int D, T;
	cin >> D >> T;

	cout << fixed << setprecision(10);

	cout << a.minExpectedPenalty(D, T) << '\n';

	return 0;
}*/
